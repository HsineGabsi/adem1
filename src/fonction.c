#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonction.h"
#include <gtk/gtk.h>
enum
{
CIN,
NOM,
PRENOM,
ESPRITID,
ROLE,
DATEN,
TEL,
SEXE,
EMAIL,
COLUMNS
};
enum
{
ETAGE,
HEURE,
JOUR,
COLUMN
};
void genererPassword(char password[])
{
	char str[20];

	int size=20;
	srand(time(NULL) * size );
	int n;
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK";
    if (size) {
        --size;
        for ( n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
	
strcpy(password,str);
}
void inscription(int type,char gender[]){
if (type == 1)
strcpy(gender,"homme");
else if (type==2)
strcpy(gender,"femme");
} 
void afficher_user(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[20];
	char prenom[20];
	char cin[20];
	char email[30];
	char sexe[20];
	char daten[20];
	char tel[20];
	char espritId[20];
	char role[20];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store == NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" EspritId:",renderer,"text",ESPRITID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Nom:",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Prenom:",renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Date de naissance:",renderer,"text",DATEN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Role:",renderer,"text",ROLE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Cin:",renderer,"text",CIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Email:",renderer,"text",EMAIL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Gender:",renderer,"text",SEXE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Téléphone:",renderer,"text",TEL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		f=fopen("utilisateur.txt","r");
		if(f==NULL)
		{

			return;
		}
		else
		{

			f=fopen("utilisateur.txt","r");
			while(fscanf(f,"%s %s %s %*s %s %s %s %s %s %s\n",espritId,nom,prenom,daten,email,cin,tel,role,sexe)!=EOF)
			{
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,ESPRITID,espritId,NOM,nom,PRENOM,prenom,DATEN,daten,ROLE,role,CIN,cin,EMAIL,email,SEXE,sexe,TEL,tel, -1);
			}
			fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
			g_object_unref(store);
		}
	}
}
void rechercher_user(GtkWidget *liste,char rech[])
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char nom[20];
	char prenom[20];
	char cin[20];
	char email[30];
	char sexe[20];
	char daten[20];
	char tel[20];
	char espritId[20];
	char role[20];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store == NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("EspritId:",renderer,"text",ESPRITID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Nom:",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Prenom:",renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Date de naissance:",renderer,"text",DATEN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Role:",renderer,"text",ROLE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Cin:",renderer,"text",CIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Email:",renderer,"text",EMAIL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Gender:",renderer,"text",SEXE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Téléphone:",renderer,"text",TEL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		f=fopen("utilisateur.txt","r");
		if(f==NULL)
		{

			return;
		}
		else
		{

			f=fopen("utilisateur.txt","r");
			while(fscanf(f,"%s %s %s %*s %s %s %s %s %s %s\n",espritId,nom,prenom,daten,email,cin,tel,role,sexe)!=EOF)
			{
			if(strcmp(rech,espritId)==0 ||strcmp(rech,cin)==0||strcmp(rech,"")==0 ){
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,EMAIL,email,ESPRITID,espritId,ROLE,role,DATEN,daten,TEL,tel,SEXE,sexe, -1);
}
			}
			fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
			g_object_unref(store);
		}
	}
}

void ajouter_user(user u)
{
FILE *f=NULL;
f=fopen("utilisateur.txt","a");
if(f!=NULL)
{
fprintf(f, "%s %s %s %s %d/%d/%d %s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,u.dateN.jour,u.dateN.mois,u.dateN.annee,u.email,u.cin,u.tel,u.role,u.sexe);
fclose(f);
}
}
void supprimer_user(char id[])
{
	user u;

    FILE *f1;
    FILE *f2;

    f1 = fopen("utilisateur.txt","r");
    f2 = fopen("tmp.txt","a");

    while(fscanf(f1,"%s %s %s %s %d/%d/%d %s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,&u.dateN.jour,&u.dateN.mois,&u.dateN.annee,u.email,u.cin,u.tel,u.role,u.sexe) != EOF){
        if(strcmp(u.espritId,id)!=0){
                        fprintf(f2, "%s %s %s %s %d/%d/%d %s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,u.dateN.jour,u.dateN.mois,u.dateN.annee,u.email,u.cin,u.tel,u.role,u.sexe);


        }
    }
    fclose(f1);
    fclose(f2);

    remove("utilisateur.txt");
    rename("tmp.txt","utilisateur.txt");

}

user modifier_user(char id[])
{
	user u;
user um;

    FILE *f1;


    f1 = fopen("utilisateur.txt","r");
    while(fscanf(f1,"%s %s %s %s %d/%d/%d %s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,&u.dateN.jour,&u.dateN.mois,&u.dateN.annee,u.email,u.cin,u.tel,u.role,u.sexe) != EOF){
        if(strcmp(u.espritId,id)==0){

um=u;



        }
    }
    fclose(f1);
    return um;
}


int test_role(char role[]){
	int i;
        if(strcmp(role,"ETUDIANT")==0)
		i=0;
	else if (strcmp(role,"AGENT-DE-FOYER")==0)
		i=1;
else if (strcmp(role,"NUTRISIONNISTE")==0)
		i=2;
else if (strcmp(role,"AGENT-DE-RESTAURANT")==0)
		i=3;
else if (strcmp(role,"TECHNICIEN")==0)
		i=4;
else if (strcmp(role,"ADMIN")==0)
		i=5;




      
	return i;
}
void update_user(user u1){
     user u;
    FILE *f;
    FILE *g;
    f = fopen("utilisateur.txt","r");
    g = fopen("tmp.txt","a");
     while(fscanf(f,"%s %s %s %s %d/%d/%d %s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,&u.dateN.jour,&u.dateN.mois,&u.dateN.annee,u.email,u.cin,u.tel,u.role,u.sexe) != EOF){

        if(strcmp(u.espritId,u1.espritId) == 0){


            u = u1;
        }
        fprintf(g, "%s %s %s %s %d/%d/%d %s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,u.dateN.jour,u.dateN.mois,u.dateN.annee,u.email,u.cin,u.tel,u.role,u.sexe);

    }
     fclose(f);
    fclose(g);
    remove("utilisateur.txt");
    rename("tmp.txt","utilisateur.txt");

}

int verifier_espritId(char id[]){
     user u;
 FILE *f1;


    f1 = fopen("utilisateur.txt","r");


    while(fscanf(f1,"%s %s %s %s %d/%d/%d %s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,&u.dateN.jour,&u.dateN.mois,&u.dateN.annee,u.email,u.cin,u.tel,u.role,u.sexe) != EOF){
        if(strcmp(u.espritId,id)==0){
                       
return 1;
        }
    }

    fclose(f1);
return 0;

}

int verifier_CIN(char cin[]){
     user u;
 FILE *f1;


    f1 = fopen("utilisateur.txt","r");


    while(fscanf(f1,"%s %s %s %s %d/%d/%d %s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,&u.dateN.jour,&u.dateN.mois,&u.dateN.annee,u.email,u.cin,u.tel,u.role,u.sexe) != EOF){
        if(strcmp(u.cin,cin)==0){
                       
return 1;
        }
    }

    fclose(f1);
return 0;

}


void  detection_mouvement(GtkWidget *liste) {
char jour[20];
char heure[20];
char num_capteur[20];
int valeur;
int test=0;




GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store == NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Etage:",renderer,"text",ETAGE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Heure:",renderer,"text",HEURE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Jour:",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		

		store=gtk_list_store_new(COLUMN, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		f=fopen("mouvement.txt","r");
		if(f==NULL)
		{

			return;
		}
		else
		{

			f=fopen("mouvement.txt","r");
while(fscanf(f,"%s %s %s %d\n",jour, heure, num_capteur, &valeur)!=EOF){
			if(valeur==1){
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,ETAGE,num_capteur,HEURE,heure,JOUR,jour, -1);
			}}
			fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
			g_object_unref(store);
		}
	}
}
void  detection_fumee(GtkWidget *liste) {
char jour[20];
char heure[20];
char num_capteur[20];
int valeur;
int test=0;




GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store == NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Etage:",renderer,"text",ETAGE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Heure:",renderer,"text",HEURE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes(" Jour:",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		

		store=gtk_list_store_new(COLUMN, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
		f=fopen("fumee.txt","r");
		if(f==NULL)
		{

			return;
		}
		else
		{

			f=fopen("fumee.txt","r");
while(fscanf(f,"%s %s %s %d\n",jour, heure, num_capteur, &valeur)!=EOF){
			if(valeur==1){
				gtk_list_store_append(store,&iter);
				gtk_list_store_set(store,&iter,ETAGE,num_capteur,HEURE,heure,JOUR,jour, -1);
			}}
			fclose(f);
			gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
			g_object_unref(store);
		}
	}
}
int  login(char id[],char mdp[], user u1){
   user u;
 FILE *f1;


    f1 = fopen("utilisateur.txt","r");


    while(fscanf(f1,"%s %s %s %s %d/%d/%d %s %s %s %s %s\n",u.espritId,u.nom,u.prenom,u.password,&u.dateN.jour,&u.dateN.mois,&u.dateN.annee,u.email,u.cin,u.tel,u.role,u.sexe) != EOF){
        if(strcmp(u.espritId,id)==0&&strcmp(u.password,mdp)==0){
            u1=u;           
return 1;
        }
    }

    fclose(f1);
return 0;
}


