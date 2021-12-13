#include "user.h"
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
enum 
 {
	ECIN,
	ENOM,
	EPRENOM,
	EJOUR,
	EMOIS,
	EANNEE,
	EROLE,
	ESEXE,
	ENIVEAU,
	COLUMNS
};
//////////////////////
void ajouter(utilisateur u)
{
FILE *f;
f=fopen("users.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,u.niveau,u.d.jour,u.d.mois,u.d.annee);
fclose(f);
}
}
///////////////////////////////



void supprimer(char cin[])
{
FILE *f ;
FILE *g;
utilisateur u;
    f=fopen("users.txt","r");
    g=fopen("users2.txt","w+");
 if(f!=NULL)
    {
	while(fscanf(f,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,&u.niveau,&u.d.jour,&u.d.mois,&u.d.annee)!=EOF)
	{ 
 	 if(strcmp(cin,u.cin)!=0)
{
	     fprintf(g,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,u.niveau,u.d.jour,u.d.mois,u.d.annee);
	     
}

}
}
fclose(f);
fclose(g);
remove("users.txt");
rename("users2.txt","users.txt");
}

///////////////////////////////////////////////////////////////
void afficher(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore   *store;
  	//g_object_set(renderer, "editable", TRUE, NULL);


	
	char cin[30];
	char nom[30];
	char prenom[30];
	int jour;
	int mois;
	int annee;
	char role[30];
	char sexe[30];
	int niveau;
	utilisateur u;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",EROLE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("niveau",renderer,"text",ENIVEAU, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	



store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);


f=fopen("users.txt","r");
if (f==NULL)
{
return;
}
else
{
f=fopen("users.txt","a+");
while (fscanf(f,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",cin,nom,prenom,sexe,role,&niveau,&jour,&mois,&annee)!=EOF)
{
	
	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter, ECIN, cin, ENOM, nom, EPRENOM, prenom, EJOUR,jour,EMOIS,mois,EANNEE,annee, EROLE, role, ESEXE, sexe,ENIVEAU, niveau,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));

}

}


/////////////////////////////////////
void vider_admin (GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore   *store;

	
	char cin[30];
	char nom[30];
	char prenom[30];
	int jour;
	int mois;
	int annee;
	char role[30];
	char sexe[30];
	int niveau;
	utilisateur u;
	store=NULL;
	FILE *f;
store=gtk_tree_view_get_model(liste);


if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",EROLE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("niveau",renderer,"text",ENIVEAU, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
}

/////////////////////////////
   
 
///////////////////////////
int chercher(char cin[])
{
FILE *f ;
utilisateur u;
int x=0;
    f=fopen("users.txt","r");
 if(f!=NULL)
    {
	while(fscanf(f,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,&u.niveau,&u.d.jour,&u.d.mois,&u.d.annee)!=EOF)
	{ 
 	 if(strcmp(cin,u.cin)==0)
{
	    
	     x=1;
}

}
}
fclose(f);
return x;
}
////////////////////////////////
utilisateur find(char cin[])
{
    utilisateur y;
utilisateur a;
    FILE *f;
    f = fopen("users.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",y.cin,y.nom,y.prenom,y.sexe,y.role,&y.niveau,&y.d.jour,&y.d.mois,&y.d.annee) != EOF){
        	if(strcmp(y.cin,cin) == 0){
       		     a=y;
        	}
    	}
}

    fclose(f);
  return a;  
}

///////////////////////
int nbretude(int niv)
{
utilisateur u;
int nbr=0;

 FILE *f;
    f = fopen("users.txt","r");
 if(f != NULL){
    	while(fscanf(f,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,&u.niveau,&u.d.jour,&u.d.mois,&u.d.annee)!= EOF){
if (niv==u.niveau)
    nbr++;
}}

fclose(f);
return nbr;
}



////////////////////////////
void modifier( utilisateur u)
{
	utilisateur h;
	FILE *f, *g;
	f=fopen("users.txt","r");
	g=fopen("users15.txt","a");
	if (f!=NULL ) {
		while(fscanf(f,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",h.cin,h.nom,h.prenom,h.sexe,h.role,&h.niveau,&h.d.jour,&h.d.mois,&h.d.annee)!=EOF)
			{ if(strcmp(u.cin,h.cin)==0){
				fprintf(g,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,u.niveau,u.d.jour,u.d.mois,u.d.annee);}
			else{
				fprintf(g,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",h.cin,h.nom,h.prenom,h.sexe,h.role,h.niveau,h.d.jour,h.d.mois,h.d.annee);}
			}
		}
	fclose(f);
	fclose(g);
	remove("users.txt");
	rename("users15.txt","users.txt");
}



//////////////////////////////////////////////////////////////
int chercherrr(char util[],char pass[])
{
FILE *f;
user u;
int x=0;
    f=fopen("admin.txt","r");
 if(f!=NULL)
    {
	while(fscanf(f,"%s %s \n",u.userr,u.pass)!=EOF)
	{ 
 	 if  ( (strcmp(util,u.userr)==0) && (strcmp(pass,u.pass)==0)  && (strcmp(util,"houssem_balti")!=0)  )
{
	    
	     x=1;

}

}
}
fclose(f);
return x;
}

//////////////////////////////////////////////////////////
int chercherr(char util[],char pass[])
{
FILE *f ;
user u;
int x=0;
    f=fopen("admin.txt","r");
 if(f!=NULL)
    {
	while(fscanf(f,"%s %s \n",u.userr,u.pass)!=EOF)
	{ 
 	 if ((strcmp(util,"houssem_balti")==0) && (strcmp(pass,"H321")==0) )
{
	    
	     x=1;
}

}
}
fclose(f);
return x;
}
////////////////////////////////////////////////////////
int nbrdate(int jour,int mois,int annee)
{
utilisateur u;
int nbr=0;

 FILE *f;
    f = fopen("users.txt","r");
 if(f != NULL){
    	while(fscanf(f,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,&u.niveau,&u.d.jour,&u.d.mois,&u.d.annee)!= EOF){
	if (   (jour==u.d.jour) && (mois==u.d.mois) && (annee==u.d.annee) && (strcmp(u.role,"etudiant")==0) )
    	nbr++;
}}

fclose(f);
return nbr;
}

/////////////////////////////////////////////////////////
/*char nbrdatee(int jour,int mois,int annee)
{
utilisateur u;
char texte[500]="";
 FILE *f;
    f = fopen("users.txt","r");
 if(f != NULL){
    	while(fscanf(f,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,&u.niveau,&u.d.jour,&u.d.mois,&u.d.annee)!= EOF){
	if (   (jour==u.d.jour) && (mois==u.d.mois) && (annee==u.d.annee) )
    		 strcpy(texte,u.nom);

}}

fclose(f);
return texte;
}*/

/////////////////////////////////////////////////////////
void afficher2(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore   *store;
  	//g_object_set(renderer, "editable", TRUE, NULL);


	
	char cin[30];
	char nom[30];
	char prenom[30];
	int jour;
	int mois;
	int annee;
	char role[30];
	char sexe[30];
	int niveau;
	utilisateur u;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",EROLE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("niveau",renderer,"text",ENIVEAU, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	



store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);


f=fopen("users22.txt","r");
if (f==NULL)
{
return;
}
else
{
f=fopen("users22.txt","a+");
while (fscanf(f,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",cin,nom,prenom,sexe,role,&niveau,&jour,&mois,&annee)!=EOF)
{



	gtk_list_store_append(store,&iter);
	gtk_list_store_set(store,&iter, ECIN, cin, ENOM, nom, EPRENOM, prenom, EJOUR,jour,EMOIS,mois,EANNEE,annee, EROLE, role, ESEXE, sexe,ENIVEAU, niveau,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
//g_object_unref(store);
}

}





///////////////////////////////////////////////////////////////



void create(int et,int tc,int nu,int af,int ar)
{
FILE *f ;
FILE *g;
utilisateur u;
     //remove("users2.txt");
    f=fopen("users.txt","r");
    g=fopen("users22.txt","w+");






 if(f!=NULL)
    {
	while(fscanf(f,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,&u.niveau,&u.d.jour,&u.d.mois,&u.d.annee)!=EOF)
	{ 
 	 if ( (et==1) && (strcmp(u.role,"etudiant")==0) )
{

	     fprintf(g,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,u.niveau,u.d.jour,u.d.mois,u.d.annee);
	     
}
 if( (nu==1)	&& (strcmp(u.role,"nutritioniste")==0) )
{

	     fprintf(g,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,u.niveau,u.d.jour,u.d.mois,u.d.annee);
	     
}
 if  ( (af==1)	&& (strcmp(u.role,"agentf")==0) )
{

	     fprintf(g,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,u.niveau,u.d.jour,u.d.mois,u.d.annee);
	     
}
 if( (ar==1)	&& (strcmp(u.role,"agentr")==0) )
{

	     fprintf(g,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,u.niveau,u.d.jour,u.d.mois,u.d.annee);
	     
}
 if ((tc==1)	&& (strcmp(u.role,"technicien")==0) )
{

	     fprintf(g,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,u.niveau,u.d.jour,u.d.mois,u.d.annee);
	     
}


}
}
fclose(f);
fclose(g);


}





///////////////////////////////////////////////////
void supprimer2(utilisateur p)
{

FILE *f, *g;
utilisateur u;
f=fopen("users.txt","r");
g=fopen("users20.txt","w");

if (f==NULL || g==NULL)
{
return;
}

else 
{
		while(fscanf(f,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,&u.niveau,&u.d.jour,&u.d.mois,&u.d.annee)!=EOF)
{
						if  (  (strcmp(p.cin,u.cin)!=0 )|| (strcmp(p.nom,u.nom)!=0 )||( strcmp(p.prenom,u.prenom)!=0) || (strcmp(p.sexe,u.sexe)!=0) || (strcmp(p.role,u.role)!=0) || (p.niveau!=u.niveau) || (p.d.jour!=u.d.jour)  || (p.d.mois!=u.d.mois) || (p.d.annee!=u.d.annee) )

				fprintf(g,"%s ;%s ;%s ;%s ;%s ;%d ;%d ;%d ;%d \n",u.cin,u.nom,u.prenom,u.sexe,u.role,u.niveau,u.d.jour,u.d.mois,u.d.annee);

}


fclose(f);
fclose(g);
remove("users.txt");
rename("users20.txt","users.txt");

}
}

