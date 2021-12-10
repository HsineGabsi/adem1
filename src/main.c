/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"
#include "fonction.h"

int
main (int argc, char *argv[])
{
  GtkWidget *ajouter_user;
  GtkWidget *gestiondesutilisateurs;
  GtkWidget *treeview1;
  GtkWidget *detection;
 GtkWidget *login;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  //gestiondesutilisateurs =create_gestion_des_utilisateurs();
  //gtk_widget_show (gestiondesutilisateurs);
//treeview1=lookup_widget(gestiondesutilisateurs,"treeview1");
//afficher_user(treeview1);
//detection=create_detection();
//gtk_widget_show (detection);
login = create_login_window();
gtk_widget_show (login);
  gtk_main ();
  return 0;
}

