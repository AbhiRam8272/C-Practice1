#include <gtk/gtk.h>
int main(int argc, char *argv[]) {
    GtkWidget *w;
    gtk_init(&argc, &argv);
    w = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(w), "Test");
    gtk_window_set_default_size(GTK_WINDOW(w), 200, 100);
    gtk_widget_show_all(w);
    gtk_main();
    return 0;
}

