// app.c
#include <gtk/gtk.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

// === Networking ===
int sockfd = -1;
int is_server = 0;

// === GTK Widgets ===
GtkWidget *text_view;
GtkWidget *entry;
GtkWidget *progress_bar;

// === Progress Data ===
typedef struct {
    GtkWidget *progressbar;
    double fraction;
} ProgressData;

gboolean update_progress(gpointer data) {
    ProgressData *p = (ProgressData *)data;
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(p->progressbar), p->fraction);
    free(p);
    return FALSE;
}

void append_text(const char *msg) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(buffer, &end);
    gtk_text_buffer_insert(buffer, &end, msg, -1);
}

// === Send File ===
void send_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        append_text("[!] File not found.\n");
        return;
    }

    // Send FILE header
    send(sockfd, "FILE", 4, 0);
    sleep(1);
    send(sockfd, filename, strlen(filename), 0);
    sleep(1);

    fseek(fp, 0, SEEK_END);
    long total = ftell(fp);
    rewind(fp);

    char buffer[SIZE];
    long sent = 0;
    int n;

    while ((n = fread(buffer, 1, SIZE, fp)) > 0) {
        if (send(sockfd, buffer, n, 0) == -1) break;
        sent += n;

        // Update progress
        ProgressData *p = malloc(sizeof(ProgressData));
        p->progressbar = progress_bar;
        p->fraction = (double)sent / total;
        g_idle_add(update_progress, p);
    }

    send(sockfd, "EOF", 3, 0);
    fclose(fp);
    append_text("[+] File sent successfully.\n");
}

// === Receive Thread ===
void *receive_data(void *arg) {
    char buffer[SIZE];
    while (1) {
        bzero(buffer, SIZE);
        int n = recv(sockfd, buffer, SIZE, 0);
        if (n <= 0) break;

        if (strncmp(buffer, "FILE", 4) == 0) {
            char fname[256];
            recv(sockfd, fname, 256, 0);
            char newname[300];
            sprintf(newname, "received_%s", fname);
            FILE *fp = fopen(newname, "wb");
            if (!fp) continue;

            while (1) {
                n = recv(sockfd, buffer, SIZE, 0);
                if (n <= 0 || (n == 3 && strncmp(buffer, "EOF", 3) == 0)) break;
                fwrite(buffer, 1, n, fp);
            }
            fclose(fp);
            append_text("[+] File received successfully.\n");
        } else {
            append_text(buffer);
            append_text("\n");
        }
    }
    return NULL;
}

// === Send Message Callback ===
void send_message(GtkWidget *widget, gpointer data) {
    const gchar *msg = gtk_entry_get_text(GTK_ENTRY(entry));
    if (!msg || strlen(msg) == 0) return;

    if (strncmp(msg, "/send ", 6) == 0) {
        char filename[256];
        sscanf(msg + 6, "%s", filename);
        send_file(filename);
    } else {
        send(sockfd, msg, strlen(msg), 0);
        append_text("You: ");
        append_text(msg);
        append_text("\n");
    }

    gtk_entry_set_text(GTK_ENTRY(entry), "");
}

// === Server Thread ===
void *server_thread(void *arg) {
    int port = *(int*)arg;
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);

    append_text("[+] Waiting for client...\n");
    sockfd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_size);
    append_text("[+] Client connected.\n");

    pthread_t recv_thr;
    pthread_create(&recv_thr, NULL, receive_data, NULL);
    pthread_join(recv_thr, NULL);

    close(server_fd);
    return NULL;
}

// === Client Thread ===
void *client_thread(void *arg) {
    struct sockaddr_in server_addr;
    char *ip = ((char **)arg)[0];
    int port = atoi(((char **)arg)[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        append_text("[!] Connect failed.\n");
        return NULL;
    }

    append_text("[+] Connected to server.\n");

    pthread_t recv_thr;
    pthread_create(&recv_thr, NULL, receive_data, NULL);
    pthread_join(recv_thr, NULL);

    return NULL;
}

// === GUI Setup ===
void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window, *vbox, *send_button, *scroll;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), is_server ? "Chat Server" : "Chat Client");
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
}

// === Main Function ===
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s server <port> OR %s client <IP> <port>\n", argv[0], argv[0]);
        return 1;
    }

    GtkApplication *app = gtk_application_new("com.chat.app", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    pthread_t net_thread;

    if (strcmp(argv[1], "server") == 0) {
        is_server = 1;
        int port = atoi(argv[2]);
        pthread_create(&net_thread, NULL, server_thread, &port);
    } else if (strcmp(argv[1], "client") == 0) {
        if (argc < 4) {
            printf("Usage: %s client <IP> <port>\n", argv[0]);
            return 1;
        }
        pthread_create(&net_thread, NULL, client_thread, argv + 2);
    } else {
        printf("Invalid mode: %s\n", argv[1]);
        return 1;
    }

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    pthread_join(net_thread, NULL);
    return status;
}

