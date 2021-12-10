#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "email.h"
#include "fonction.h"










int type=1;
char idM[30];
 user ust;
void
on_ajouterUser_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *espritId, *nom, *prenom, *jour, *mois, *annee, *email, *tel, *cin, *sexe, *role ,*tel_err,*id_err,*cin_err,*email_err,*nom_err,*prenom_err,*role_err;
char sexa[20];
char password[20];
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

espritId = lookup_widget (button, "espritIda");
nom = lookup_widget (button, "noma");
prenom = lookup_widget (button, "prenoma");
jour = lookup_widget (button, "joura");
mois = lookup_widget (button, "moisa");
annee = lookup_widget (button, "anneea");
email = lookup_widget (button, "emaila");
tel = lookup_widget (button, "tela");
cin = lookup_widget (button, "cina");
role = lookup_widget (button, "rolea");
tel_err = lookup_widget (button, "tel_err");
id_err = lookup_widget (button, "id_err");
cin_err = lookup_widget (button, "cin_err");
email_err = lookup_widget (button, "email_err");
nom_err = lookup_widget (button, "nom_err");
prenom_err = lookup_widget (button, "prenom_err");
role_err = lookup_widget (button, "role_err");
inscription(type,sexa);
genererPassword(password);
user u;
date d;
int test12=0;

strcpy(u.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(u.espritId, gtk_entry_get_text(GTK_ENTRY(espritId)));
strcpy(u.email, gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(u.tel, gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(u.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(u.password,password);

strcpy(u.sexe,sexa);
u.dateN=d;

if(strlen(u.tel)!=8){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (tel_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(tel_err),"Verifier le numéro de téléphone !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(tel_err),"");
if (verifier_espritId(u.espritId)==1)
{
GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (id_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(id_err),"Id existant !");
test12 =1;

}else if (strlen(u.espritId)!=10)
{
GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (id_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(id_err),"Vérifier Id !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(id_err),"");
if (strlen(u.cin)!=8)
{
GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (cin_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(cin_err),"Vérifier CIN !");
test12 =1;

}else if (verifier_CIN(u.cin)==1)
{
GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (cin_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(cin_err),"CIN existant !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(cin_err),"");
if (strlen(u.email)==0)
{
GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (email_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(email_err),"Vérifier Email !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(email_err),"");
if(strlen(u.nom)==0){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (nom_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(nom_err),"Verifier le nom !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(nom_err),"");
if(strlen(u.prenom)==0){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (prenom_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(prenom_err),"Verifier le prenom !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(prenom_err),"");
if(strlen(u.role)==0){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (role_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(role_err),"Verifier le role !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(role_err),"");
if (test12==0){
ajouter_user(u);
fenetre_ajout=lookup_widget(button,"ajouter_user");
gtk_widget_destroy(fenetre_ajout);
send_mail(u.email, u.espritId,u.password);
fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);
}


 
}


void
on_homme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
type=1;
}


void
on_femme_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
type=2;
}


void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(objet,"gestion_des_utilisateurs");
fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_user(treeview1);
}




void
on_afficher_user_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_ajout=lookup_widget(objet,"ajouter_user");
gtk_widget_destroy(fenetre_ajout);

fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* espritId;

char id[20];
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter, path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,3,&espritId,-1);

strcpy(id,espritId); 
   g_print("%s\n",id); 

 supprimer_user(id);
gtk_list_store_remove(GTK_LIST_STORE(model), &iter);

afficher_user(treeview);

}

}


void
on_ajouterUtilisateur_clicked          (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;

fenetre_afficher=lookup_widget(objet,"gestion_des_utilisateurs");

gtk_widget_destroy(fenetre_afficher);
fenetre_ajout=lookup_widget(objet,"ajouter_user");
fenetre_ajout=create_ajouter_user();
gtk_widget_show(fenetre_ajout);


}





//////////////////////////////////////////////////////

void
  view_popup_menu_onDoSomething (GtkWidget *menuitem, gpointer userdata)
  {
    /* we passed the view as userdata when we connected the signal */
    GtkTreeView *treeview = GTK_TREE_VIEW(userdata);

GtkWidget *fenetre_afficher;
GtkWidget *fenetre_modif;
GtkWidget *espritId, *nom, *prenom, *jour, *mois, *annee, *email, *tel, *cin, *sexe, *role,*homme,*femme ;


date d;
char jo[20];
char mo[20];
char an[20];
fenetre_afficher=lookup_widget(treeview,"gestion_des_utilisateurs");
gtk_widget_destroy(fenetre_afficher);
user um=modifier_user(idM);
d=um.dateN;
fenetre_modif=create_modifier_user();

espritId = lookup_widget (fenetre_modif, "espritIdm");
gtk_entry_set_text(GTK_ENTRY(espritId),um.espritId);
gtk_entry_set_editable(espritId,FALSE);
nom = lookup_widget (fenetre_modif, "nomm");
gtk_entry_set_text(GTK_ENTRY(nom),um.nom);
prenom = lookup_widget (fenetre_modif, "prenomm");
gtk_entry_set_text(GTK_ENTRY(prenom),um.prenom);
email = lookup_widget (fenetre_modif, "emailm");
gtk_entry_set_text(GTK_ENTRY(email),um.email);
tel = lookup_widget (fenetre_modif, "telm");
gtk_entry_set_text(GTK_ENTRY(tel),um.tel);
cin = lookup_widget (fenetre_modif, "cinm");
gtk_entry_set_text(GTK_ENTRY(cin),um.cin);
gtk_entry_set_editable(cin,FALSE);
jour = lookup_widget (fenetre_modif, "jourm");
//sprintf(jo,"%d",um.dateN.jour); convert int to char

gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),um.dateN.jour);
mois = lookup_widget (fenetre_modif, "moism");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),um.dateN.mois);
annee = lookup_widget (fenetre_modif, "anneem");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),um.dateN.annee);
role = lookup_widget (fenetre_modif, "rolem");
int i=  test_role(um.role);
gtk_combo_box_set_active(GTK_COMBO_BOX(role), i);
homme = lookup_widget (fenetre_modif, "hommem");
femme = lookup_widget (fenetre_modif, "femmem");
if (strcmp(um.sexe,"homme")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(homme),TRUE);
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(femme),FALSE);
}
else if (strcmp(um.sexe,"femme")==0){
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(homme),FALSE);
gtk_toggle_button_set_active(GTK_RADIO_BUTTON(femme),TRUE);
}

gtk_widget_show(fenetre_modif);

  }


  void
  view_popup_menu (GtkWidget *treeview, GdkEventButton *event, gpointer userdata)
  {
    GtkWidget *menu, *menuitem;
GtkTreeIter iter;
GtkTreePath *path;
    menu = gtk_menu_new();

    menuitem = gtk_menu_item_new_with_label("Modifier");

    g_signal_connect(menuitem, "activate",
                     (GCallback) view_popup_menu_onDoSomething, treeview);
 if (gtk_tree_view_get_path_at_pos(GTK_TREE_VIEW(treeview),
                                             (gint) event->x, 
                                             (gint) event->y,
                                             &path, NULL, NULL, NULL))
{
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
	     gchar* espritId;

if(gtk_tree_model_get_iter(model, &iter, path)){

	     gtk_tree_model_get(GTK_LIST_STORE(model),&iter,3,&espritId,-1);

	     strcpy(idM,espritId); 

  	     
}
	}     
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

    gtk_widget_show_all(menu);

    /* Note: event can be NULL here when called from view_onPopupMenu;
     *  gdk_event_get_time() accepts a NULL argument */
    gtk_menu_popup(GTK_MENU(menu), NULL, NULL, NULL, NULL,
                   (event != NULL) ? event->button : 0,
                   gdk_event_get_time((GdkEvent*)event));
	    
  }


  gboolean
on_treeview1_button_press_event         (GtkWidget *treeview, GdkEventButton *event, gpointer userdata)
  {
    /* single click with the right mouse button? */
    if (event->type == GDK_BUTTON_PRESS  &&  event->button == 3)
    {
      g_print ("Single right click on the tree view.\n");

      /* optional: select row if no row is selected or only
       *  one other row is selected (will only do something
       *  if you set a tree selection mode as described later
       *  in the tutorial) */
      if (1)
      {
        GtkTreeSelection *selection;

        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));

        /* Note: gtk_tree_selection_count_selected_rows() does not
         *   exist in gtk+-2.0, only in gtk+ >= v2.2 ! */
        if (gtk_tree_selection_count_selected_rows(selection)  <= 1)
        {
           GtkTreePath *path;

           /* Get tree path for row that was clicked */
           if (gtk_tree_view_get_path_at_pos(GTK_TREE_VIEW(treeview),
                                             (gint) event->x, 
                                             (gint) event->y,
                                             &path, NULL, NULL, NULL))
           {
             gtk_tree_selection_unselect_all(selection);
             gtk_tree_selection_select_path(selection, path);
	     
             gtk_tree_path_free(path);
           }
        }
      } /* end of optional bit */

      view_popup_menu(treeview, event, userdata);

      return TRUE; /* we handled this */
    }

    return FALSE; /* we did not handle this */
  }


  gboolean
  on_treeview1_popup_menu(GtkWidget *treeview, gpointer userdata)
  {

    view_popup_menu(treeview, NULL, userdata);

    return TRUE; /* we handled this */
  }


  

 
////////////////////////////////////////////////////////////
void
on_rechercherUser_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_rechercher;
GtkWidget *fenetre_afficher;
GtkWidget *espritId;
GtkWidget *treeview1;
char rech[20];
espritId = lookup_widget (objet, "esId");
strcpy(rech, gtk_entry_get_text(GTK_ENTRY(espritId)));
fenetre_afficher=lookup_widget(objet,"gestion_des_utilisateurs");
gtk_widget_destroy(fenetre_afficher);
fenetre_rechercher=lookup_widget(objet,"gestion_des_utilisateurs");
fenetre_rechercher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_rechercher);
treeview1=lookup_widget(fenetre_rechercher,"treeview1");
rechercher_user(treeview1,rech);
}


void
on_retourU_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modif;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_modif=lookup_widget(objet,"modifier_user");
gtk_widget_destroy(fenetre_modif);

fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);
}


void
on_modifierUser_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *espritId, *nom, *prenom, *jour, *mois, *annee, *email, *tel, *cin, *sexe, *role ,*tel_err,*email_err,*nom_err,*prenom_err,*role_err;
char sexa[20];
char password[20];
GtkWidget *fenetre_modif;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

espritId = lookup_widget (button, "espritIdm");
nom = lookup_widget (button, "nomm");
prenom = lookup_widget (button, "prenomm");
jour = lookup_widget (button, "jourm");
mois = lookup_widget (button, "moism");
annee = lookup_widget (button, "anneem");
email = lookup_widget (button, "emailm");
tel = lookup_widget (button, "telm");
cin = lookup_widget (button, "cinm");
role = lookup_widget (button, "rolem");
tel_err = lookup_widget (button, "tel_errm");

email_err = lookup_widget (button, "email_errm");
nom_err = lookup_widget (button, "nom_errm");
prenom_err = lookup_widget (button, "prenom_errm");
role_err = lookup_widget (button, "role_errm");
inscription(type,sexa);

user u;
date d;
strcpy(u.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(u.espritId, gtk_entry_get_text(GTK_ENTRY(espritId)));
strcpy(u.email, gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(u.tel, gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(u.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(u.password,password);
strcpy(u.sexe,sexa);
u.dateN=d;
int test12=0;
if(strlen(u.tel)!=8){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (tel_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(tel_err),"Verifier le numéro de téléphone !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(tel_err),"");
if (strlen(u.email)==0)
{
GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (email_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(email_err),"Vérifier Email !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(email_err),"");
if(strlen(u.nom)==0){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (nom_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(nom_err),"Verifier le nom !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(nom_err),"");
if(strlen(u.prenom)==0){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (prenom_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(prenom_err),"Verifier le prenom !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(prenom_err),"");
if(strlen(u.role)==0){
  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (role_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(role_err),"Verifier le role !");
test12 =1;

}else
gtk_label_set_text(GTK_LABEL(role_err),"");
if (test12==0){

update_user(u);
fenetre_modif=lookup_widget(button,"modifier_user");
gtk_widget_destroy(fenetre_modif);

fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);
}

}


void
on_hommem_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
type=1;
}


void
on_femmem_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
type=2;
}


void
on_afficher_mouvement_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview2;
treeview2=lookup_widget(objet,"treeview2");
detection_mouvement(treeview2);
}


void
on_afficher_fumee_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview3;
treeview3=lookup_widget(objet,"treeview3");
detection_fumee(treeview3);
}


void
on_login_clicked                       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *espritId, *mdp,*login_err;
user u;
espritId = lookup_widget (button, "espritIdl");
mdp = lookup_widget (button, "mdpl");
login_err = lookup_widget (button, "login_err");
strcpy(u.espritId, gtk_entry_get_text(GTK_ENTRY(espritId)));
strcpy(u.password, gtk_entry_get_text(GTK_ENTRY(mdp)));

if(login(u.espritId,u.password,ust)==0){


  GdkColor color;

    gdk_color_parse ("red", &color);


    gtk_widget_modify_fg (login_err, GTK_STATE_NORMAL, &color);
gtk_label_set_text(GTK_LABEL(login_err),"Verifier vos cordonnées !");
}else if (login(u.espritId,u.password,ust)==1){
g_print("test %s\n",ust.espritId);
GtkWidget *login_window;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
login_window=lookup_widget(button,"login_window");
gtk_widget_destroy(login_window);

fenetre_afficher=create_gestion_des_utilisateurs();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher_user(treeview1);
}

}

