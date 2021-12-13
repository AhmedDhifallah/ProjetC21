#include "foyer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
enum
{ ENOM,
EPRENOM,
EID,
ENIVEAU,
EBLOC,
ENUM,
COLUMNS
};
void ajouter_etudiant(identifiant c)
{
//ouvrir le fichier
FILE *f;
f=fopen("Foyer.txt","a+");
if(f!=NULL)
{
//ecrire dans le fichier
fprintf(f,"%s %s %s %d %s %s \n",c.nom,c.prenom,c.ID,c.niveau,c.bloc,c.num);
fclose(f);
}
else
printf("\n Not found");
}
///////////////////////////////////////////////////
void modifier_etudiant(identifiant c,char Foyer[])
{
identifiant c1;
FILE *f, *g;
f=fopen("Foyer.txt","r");
g=fopen("test.txt","w+");
if (f!=NULL && g!=NULL) {
while(fscanf(f,"%s %s %s %d %s %s \n",c1.nom,c1.prenom,c1.ID,&c1.niveau,c1.bloc,c1.num)!=EOF)
{ if(strcmp(c1.ID,c.ID)!=0){
fprintf(g,"%s %s %s %d %s %s\n",c1.nom,c1.prenom,c1.ID,c1.niveau,c1.bloc,c1.num);}
else{
fprintf(g,"%s %s %s %d %s %s\n",c.nom,c.prenom,c.ID,c.niveau,c.bloc,c.num);
}
}
fclose(f);
fclose(g);
remove("Foyer.txt");
rename("test.txt","Foyer.txt");
}
}
/////////////////////////////////////////////////////////
int chercher_etudiant(char id[20],char Foyer[])
{
int trouve;
identifiant c;
FILE *f=NULL;
f=fopen("Foyer.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %d %s %s\n",c.nom,c.prenom,c.ID,&c.niveau,c.bloc,c.num)!=EOF)
{
if(strcmp(id,c.ID)==0)
{
trouve=1;
printf("id existe \n");
}
else
{trouve=0;}
fclose(f);
}
}
return (trouve);
}
///////////////////////////////////////////////////////
void supprimer_etudiant(char id[20])
{
identifiant c;
FILE *f, *g;
f=fopen("Foyer.txt","r");
g=fopen("test.txt","w+");
if (f!=NULL && g!=NULL)
{
while(fscanf(f,"%s %s %s %d %s %s\n",c.nom,c.prenom,c.ID,&c.niveau,c.bloc,c.num)!=EOF)
{ if(strcmp(id,c.ID)!=0)
{
fprintf(g,"%s %s %s %d %s %s\n",c.nom,c.prenom,c.ID,c.niveau,c.bloc,c.num);
}
}
}
fclose(f);
fclose(g);
remove("Foyer.txt");
rename("test.txt","Foyer.txt");
}
/////////////////////////////////////////////////////////////
void afficher_etudiant(GtkWidget *liste,char Foyer[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[30];
char prenom[30];
char bloc[30];
char ID[30];
int niveau;
char num[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("niveau",renderer,"text",ENIVEAU,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("bloc",renderer,"text",EBLOC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("num",renderer,"text",ENUM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("Foyer.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %d %s %s \n",nom,prenom,ID,&niveau,bloc,num)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,EID,ID,ENIVEAU,niveau,EBLOC,bloc,ENUM,num,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}

/////////////////////////////////////////////////////
void vider(GtkWidget *liste,char Foyer[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[30];
char prenom[30];
char bloc[30];
char ID[30];
int niveau;
char num[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("niveau",renderer,"text",ENIVEAU,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("bloc",renderer,"text",EBLOC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("num",renderer,"text",ENUM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append (store,&iter);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
}

