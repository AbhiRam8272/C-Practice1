#include <gtk/gtk.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

int server_fd, client_fd;
GtkWidget *text_view;
GtkWidget *entry;
GtkWidget *progress_bar;

// === Thread-safe append text ===
typedef struct {
    GtkTextBuffer *buffer;
    char *msg;
} TextData;

gboolean append_text_idle(gpointer data) {
    TextData *t = (TextData*)data;
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(t->buffer, &end);
    gtk_text_buffer_insert(t->buffer, &end, t->msg, -1);
    free(t->msg);
    free(t);
    return FALSE;
}

void append_text(const char *msg) {
    if (!text_view) return;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    TextData *t = malloc(sizeof(TextData));
    t->buffer = buffer;
    t->msg = strdup(msg);
    g_idle_add(append_text_idle, t);
}

// === Thread-safe progress bar update ===
typedef struct {
    GtkWidget *progressbar;
    double fraction;
} ProgressData;

gboolean update_progress(gpointer data) {
    ProgressData *p = (ProgressData*)data;
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(p->progressbar), p->fraction);
    free(p);
    return FALSE;
}

// === Send file ===
void send_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        append_text("[!] File not found.\n");
        return;
    }

    // Send file header: "FILE" + filename
    send(client_fd, "FILE", 4, 0);
    usleep(100000); // 0.1 sec
    send(client_fd, filename, strlen(filename) + 1, 0);

    fseek(fp, 0, SEEK_END);
    long total = ftell(fp);
    rewind(fp);

    char buffer[SIZE];
    long sent = 0;
    int n;

    while ((n = fread(buffer, 1, SIZE, fp)) > 0) {
        if (send(client_fd, buffer, n, 0) == -1) break;
        sent += n;

        double frac = (double)sent / total;
        ProgressData *p = malloc(sizeof(ProgressData));
        p->progressbar = progress_bar;
        p->fraction = frac;
        g_idle_add(update_progress, p);
    }

    send(client_fd, "EOF", 3, 0);
    fclose(fp);
    append_text("[+] File sent successfully.\n");
}

// === Receive thread ===
void *receive_data(void *arg) {
    char buffer[SIZE];
    while (1) {
        bzero(buffer, SIZE);
        int n = recv(client_fd, buffer, SIZE, 0);
        if (n <= 0) break;

        if (strncmp(buffer, "FILE", 4) == 0) {
            // Receive filename
            char fname[256];
            recv(client_fd, fname, 256, 0);

            char newname[300];
            snprintf(newname, sizeof(newname), "%s", fname);
            FILE *fp = fopen(newname, "wb");
            if (!fp) continue;

            long received = 0;
            while (1) {
                n = recv(client_fd, buffer, SIZE, 0);
                if (n <= 0 || (n == 3 && strncmp(buffer, "EOF", 3) == 0)) break;
                fwrite(buffer, 1, n, fp);
                received += n;

                double frac = 0;
                fseek(fp, 0, SEEK_END);
                long size = ftell(fp);
                if (size > 0) frac = (double)received / size;

                ProgressData *p = malloc(sizeof(ProgressData));
                p->progressbar = progress_bar;
                p->fraction = frac;
                g_idle_add(update_progress, p);
            }
            fclose(fp);
            append_text("[+] File received successfully.\n");
        } else {
            append_text(buffer);
        }
    }
    return NULL;
}

// === Send button callback ===
void send_message(GtkWidget *widget, gpointer data) {
    const gchar *msg = gtk_entry_get_text(GTK_ENTRY(entry));
    if (strncmp(msg, "/send ", 6) == 0) {
        char filename[256];
        sscanf(msg + 6, "%s", filename);
        send_file(filename);
    } else {
        send(client_fd, msg, strlen(msg), 0);
        append_text("You: ");
        append_text(msg);
        append_text("\n");
    }
    gtk_entry_set_text(GTK_ENTRY(entry), "");
}

// === Server thread ===
void *server_thread(void *arg) {
    int port = *(int*)arg;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);

    append_text("[+] Waiting for client...\n");
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_size);
    append_text("[+] Client connected.\n");

    pthread_t recv_thr;
    pthread_create(&recv_thr, NULL, receive_data, NULL);
    pthread_detach(recv_thr);
    return NULL;
}

// === GTK activate ===
void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window, *vbox, *send_button, *scroll;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Chat Server");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 500);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_vexpand(scroll, TRUE);
    text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_container_add(GTK_CONTAINER(scroll), text_view);
    gtk_box_pack_start(GTK_BOX(vbox), scroll, TRUE, TRUE, 0);

    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 0);

    send_button = gtk_button_new_with_label("Send");
    gtk_box_pack_start(GTK_BOX(vbox), send_button, FALSE, FALSE, 0);

    progress_bar = gtk_progress_bar_new();
    gtk_box_pack_start(GTK_BOX(vbox), progress_bar, FALSE, FALSE, 0);

    g_signal_connect(send_button, "clicked", G_CALLBACK(send_message), NULL);

    gtk_widget_show_all(window);

    int *port_ptr = malloc(sizeof(int));
    *port_ptr = 8080; // change if needed
    pthread_t srv_thr;
    pthread_create(&srv_thr, NULL, server_thread, port_ptr);
}

// === Main ===
int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new("com.chat.server", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

