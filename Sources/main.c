#include <gtk/gtk.h>

static void
app_activate (GApplication *app, gpointer user_data) {
  GtkWidget *win;

  win = gtk_application_window_new (GTK_APPLICATION (app));
  gtk_window_set_title (GTK_WINDOW (win), "ydere");
  gtk_window_set_default_size (GTK_WINDOW (win), 400, 300);
  gtk_widget_show (win);
}

int
main (int argc, char **argv) {
  GtkApplication *app;
  int stat;

  app = gtk_application_new ("com.github.MrMiquy.ydere", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
  stat =g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);
  return stat;
}
