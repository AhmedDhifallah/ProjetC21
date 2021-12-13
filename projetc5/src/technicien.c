#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "technicien.h"
#include "callbacks.h"

#include <gtk/gtk.h>

enum
{
	ID,
	TYPE,
	MARQUE,
	DATE,
	GARANTIE,
	COLUMNS
};

void modifier_capt(capteur55 u)
{
capteur55 p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen("capteur.txt","r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
{
	return;
}
else{
	while(fscanf(f,"%s %d %s %s %d %d %d\n",p.id55,&p.type55,p.marque55,p.garantie55,&p.d55.j55,&p.d55.m55,&p.d55.a55)!=EOF)
	{
		if(strcmp(p.id55,u.id55)==0)
			fprintf(g,"%s %d %s %s %d %d %d\n",u.id55,u.type55,u.marque55,p.garantie55,u.d55.j55,u.d55.m55,u.d55.a55);
		else
			fprintf(g,"%s %d %s %s %d %d %d\n",p.id55,u.type55,u.marque55,p.garantie55,p.d55.j55,p.d55.m55,p.d55.a55);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur modifié avec succès !");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove("capteur.txt");
rename("dump.txt","capteur.txt");
}
}

void afficher_capt(GtkWidget *liste)
{
capteur55 p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
gchar date_achat[50], type[20];
FILE *f;


store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" ID", renderer,"text",ID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Type", renderer,"text",TYPE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Marque", renderer,"text",MARQUE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Garantie", renderer,"text",GARANTIE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes(" Date ", renderer,"text",DATE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
}	


store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("capteur.txt","r");
if(f!=NULL)

{ f = fopen("capteur.txt","a+");
		while(fscanf(f,"%s %d %s %s %d %d %d\n",p.id55,&p.type55,p.marque55,p.garantie55,&p.d55.j55,&p.d55.m55,&p.d55.a55)!=EOF)
	{
sprintf(date_achat,"%d/%d/%d",p.d55.j55,p.d55.m55,p.d55.a55);

sprintf(type,p.type55==0?"Température":p.type55==1?"Débit d'eau":p.type55==2?"Mouvement":"Fumée");

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,p.id55,TYPE,type,MARQUE,p.marque55,GARANTIE,p.garantie55,DATE,date_achat,-1);
	}
	fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

int chercher_capt(char id55[])
{
FILE *f ;
capteur55 u;
int trouve=0;
    f=fopen("capteur.txt","r");
 if(f!=NULL)
    {
	while(fscanf(f,"%s ;%d ;%s ;%s ;%d ;%d ;%d \n",u.id55,&u.type55,u.marque55,u.garantie55,&u.d55.j55,&u.d55.m55,&u.d55.a55)!=EOF)
	{ 
 	 if(strcmp(id55,u.id55)==0)
{
	    
	     trouve=1;
}

}
}
fclose(f);

return trouve;
}

void supprimer_capt(capteur55 u)
{
capteur55 p;
GtkWidget *pInfo;
gpointer user_data;
FILE *f, *g;
f=fopen("capteur.txt","r");
g=fopen("dump.txt","w");
if(f!=NULL&&g!=NULL){
	while(fscanf(f,"%s %d %s %s %d %d %d\n",p.id55,&(p.type55),p.marque55,p.garantie55,&(p.d55.j55),&(p.d55.m55),&(p.d55.a55))!=EOF)
	{
		if(strcmp(p.id55,u.id55)!=0)
			fprintf(g,"%s %d %s %s %d %d %d\n",p.id55,p.type55,p.marque55,p.garantie55,p.d55.j55,p.d55.m55,p.d55.a55);
	}
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur supprimé avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	fclose(f);
	fclose(g);
remove("capteur.txt");
rename("dump.txt","capteur.txt");
}
}

capteur55 find_capt(char id55[])
{
    capteur55 u;
 capteur55 y;
    FILE *f;
    f = fopen("capteur.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %d %s %s %d %d %d\n",u.id55,&u.type55,u.marque55,u.garantie55,&u.d55.j55,&u.d55.m55,&u.d55.a55) != EOF){
        	if(strcmp(u.id55,id55) == 0){
       		     y=u;
        	}
    	}
}

    fclose(f);
  return y;  
}


void ajouter_captt(capteur55 u)
{
FILE *f;
f=fopen("capteur.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %d %s %s %d %d %d\n",u.id55,u.type55,u.marque55,u.garantie55,u.d55.j55,u.d55.m55,u.d55.a55);
fclose(f);
}
}






