#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alarme.h"
#include "callbacks.h"
#include <gtk/gtk.h>
#include <stdio.h>
enum
{
JOUR,
HEURE,
NUM,
VALEUR,
COLUMNS
};
enum
{
JOUR1,
HEURE1,
NUM1,
VALEUR1,
COLUMNS1
};
void adalarme(GtkWidget *liste, char mouvement[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char jour[20];
char num[20];
char valeur[20];
FILE *f;
store=NULL;
int heure;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",HEURE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Num",renderer,"text",NUM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",VALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("mouvement.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %d %s %s \n",jour,&heure,num,valeur)!=EOF)
{
if((strcmp(valeur,"1")==0 && heure<6) ||(strcmp(valeur,"1")==0 && heure==24)){
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,JOUR,jour,HEURE,heure,NUM,num,VALEUR,valeur,-1);
}
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
//////////////////////////////////////
void advider(GtkWidget *liste, char mouvement[]){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char jour[20];
int heure;
char num[20];
char valeur[20];
FILE *f,*g;
store=NULL;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",HEURE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Num",renderer,"text",NUM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",VALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
gtk_list_store_append (store,&iter);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
}
///////

void adalarme1(GtkWidget *liste, char fumee[])
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char jour[20];
int heure;
char num[20];
char valeur[20];
FILE *g;
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",HEURE1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Num",renderer,"text",NUM1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",VALEUR1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
g=fopen("fumee.txt","r");
if(g!=NULL)
{
while(fscanf(g,"%s %d %s %s \n",jour,&heure,num,valeur)!=EOF)
{
if((strcmp(valeur,"1")==0 && heure<6) ||(strcmp(valeur,"1")==0 && heure==24)){
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,JOUR1,jour,HEURE1,heure,NUM1,num,VALEUR1,valeur,-1);
}
}
}
fclose(g);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
///////////
void advider1(GtkWidget *liste, char fumee[]){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char jour[20];
int heure;
char num[20];
char valeur[20];
FILE *g;
store=NULL;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",HEURE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Num",renderer,"text",NUM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	


	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",VALEUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
gtk_list_store_append (store,&iter);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
}
