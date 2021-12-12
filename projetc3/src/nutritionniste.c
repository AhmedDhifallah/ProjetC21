#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nutritionniste.h"
#include <gtk/gtk.h>


enum
{
	EID,
	ETYPE,
	ECONTENU,
	EDECHETS,
	EJOUR,
	EMOIS,
	EANNEE,
	COLUMNS,
};

//////////////////////////////////
void ajouter_menu(menu m)
{
FILE *f;
f=fopen("menu.txt","a+");
if(f!=NULL)
{
fprintf(f,"%d %d %s %f %d %s %d \n",m.id, m.type, m.contenu, m.dechets, m.d.jour, m.d.mois, m.d.annee);
fclose(f);
}
}


///////////////////////////////////////
int rechercher_menu (int idrechmenu)
{
    menu m;
    FILE *f;
    f = fopen("menu.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%d %d %s %f %d %s %d\n",&m.id,&m.type,m.contenu,&m.dechets,&m.d.jour,m.d.mois,&m.d.annee) != EOF)
        {
        	if(m.id==idrechmenu)
                {
       		     return 1;
        	}
    	}
}
    fclose(f);
    return 0;
}
/////////////////////////////////////////////
void afficherrecherche_menu(int idrechmenu,char msgmenu[],int RES)
{
    char ch0[5]="";
    char ch1[10]="";
    char ch2[10]="";
    char ch3[6]="";
    char ch4[10]="";
    menu m;
    FILE *f;

	f = fopen("menu.txt","a+");
	if(f != NULL)
	  {
		while(fscanf(f,"%d %d %s %f %d %s %d\n",&m.id,&m.type,m.contenu,&m.dechets,&m.d.jour,m.d.mois,&m.d.annee) != EOF)
		  {
			if(m.id=idrechmenu)
			  {
				strcat(msgmenu, "Voici le menu que vous cherchez :\n");
				strcat(msgmenu, "L'identifiant :\t");
       				sprintf(ch0, "%d", m.id);
				strcat(msgmenu,ch0);
				strcat(msgmenu, "\n");
				strcat(msgmenu, "Le type :\t");
				sprintf(ch1, "%d", m.type);
				strcat(msgmenu,ch1);
				strcat(msgmenu,"\n");
				strcat(msgmenu, "Le contenu :\t");
				strcat(msgmenu, m.contenu);
				strcat(msgmenu,"\n");
				strcat(msgmenu, "La quantité de dechets :\t");
				sprintf(ch2, "%f", m.dechets);
				strcat(msgmenu,ch2);
				strcat(msgmenu,"\n");
				sprintf(ch3, "%d", m.d.jour);
				sprintf(ch4, "%d", m.d.annee);
				strcat(msgmenu, "La date du menu :\n");
				strcat(msgmenu, "\t Jour :\t");
				strcat(msgmenu,ch3);
				strcat(msgmenu,"\n");
				strcat(msgmenu, "\t Mois :\t");
				strcat(msgmenu,m.d.mois);
				strcat(msgmenu,"\n");
				strcat(msgmenu, "\t Année :\t");
				strcat(msgmenu,ch4);
				
			  }
		  }
	  }



    fclose(f);
    /*return;*/
}
///////////////////////////////////////////////////////////////////
void trier_les_dechets(float tab[])
{
int permut,i;
float aux;
do 
{
permut=0;
for(i=0;i<20;i++)
{
if(tab[i]>tab[i+1])
{
aux=tab[i];
tab[i]=tab[i+1];
tab[i+1]=aux;
permut=1;
}
}
}
while(permut==1);
}
//////////////////////////////////////////////

void meilleur_menu(int jo,char msgmeilleurmenu[]/*,float tab[]*/)
{
FILE *f=NULL;
FILE *g=NULL;
menu m;
float tab[25];
char ch1[10]="";
char ch2[10]="";
char ch3[10]="";
char ch4[10]="";
f=fopen("dechets.txt","r");
if(f!=NULL)
{
	while(fscanf(f,"%d %d %f",&m.d.jour,&m.type,&m.dechets) != EOF)
	{
		if(m.d.jour==jo && m.type==1)
		tab[0]=m.dechets;
		if(m.d.jour==jo && m.type==2)
		tab[1]=m.dechets;
		if(m.d.jour==jo && m.type==3)
		{
		tab[2]=m.dechets;
		jo+=1;
		}
		if(m.d.jour==jo && m.type==1)
		tab[3]=m.dechets;
		if(m.d.jour==jo && m.type==2)
		tab[4]=m.dechets;
		if(m.d.jour==jo && m.type==3)
		{
		tab[5]=m.dechets;
		jo+=1;
		}
		if(m.d.jour==jo && m.type==1)
		tab[6]=m.dechets;
		if(m.d.jour==jo && m.type==2)
		tab[7]=m.dechets;
		if(m.d.jour==jo && m.type==3)
		{
		tab[8]=m.dechets;
		jo+=1;
		}
		if(m.d.jour==jo && m.type==1)
		tab[9]=m.dechets;
		if(m.d.jour==jo && m.type==2)
		tab[10]=m.dechets;
		if(m.d.jour==jo && m.type==3)
		{
		tab[11]=m.dechets;
		jo+=1;
		}
		if(m.d.jour==jo && m.type==1)
		tab[12]=m.dechets;
		if(m.d.jour==jo && m.type==2)
		tab[13]=m.dechets;
		if(m.d.jour==jo && m.type==3)
		{
		tab[14]=m.dechets;
		jo+=1;
		}
		if(m.d.jour==jo && m.type==1)
		tab[15]=m.dechets;
		if(m.d.jour==jo && m.type==2)
		tab[16]=m.dechets;
		if(m.d.jour==jo && m.type==3)
		{
		tab[17]=m.dechets;
		jo+=1;
		}
		if(m.d.jour==jo && m.type==1)
		tab[18]=m.dechets;
		if(m.d.jour==jo && m.type==2)
		tab[19]=m.dechets;
		if(m.d.jour==jo && m.type==3)
		tab[20]=m.dechets;
		}
		}
fclose(f);
trier_les_dechets(tab);
g=fopen("menu.txt","r");
if(g!=NULL)
{
	while(fscanf(g,"%d %d %s %f %d %s %d\n",&m.id,&m.type,m.contenu,&m.dechets,&m.d.jour,m.d.mois,&m.d.annee) != EOF)
	{
		if(m.dechets==tab[0])
		{
		sprintf(msgmeilleurmenu, "%d", m.id);
		sprintf(ch1, "%d", m.type);
		strcat(msgmeilleurmenu,"\t");
		strcat(msgmeilleurmenu,ch1);
		strcat(msgmeilleurmenu,"\t");
		strcat(msgmeilleurmenu,m.contenu);
		strcat(msgmeilleurmenu,"\t");
		sprintf(ch2, "%f", m.dechets);
		strcat(msgmeilleurmenu,ch2);
		strcat(msgmeilleurmenu,"\t");
		sprintf(ch3, "%d", m.d.jour);
		sprintf(ch4, "%d", m.d.annee);
		strcat(msgmeilleurmenu,ch3);
		strcat(msgmeilleurmenu,"\t");
		strcat(msgmeilleurmenu,m.d.mois);
		strcat(msgmeilleurmenu,"\t");
		strcat(msgmeilleurmenu,ch4);
		}

	}
}

fclose(g);


}

//////////////////////////////////////////////////////////////
void supprimer_menu(int id1)
{

	menu m1;    
	FILE *f=NULL;
	FILE *g=NULL;
	f = fopen("menu.txt","r");
	g = fopen("menu1.txt","w");
	if (f==NULL || g==NULL )
	return;
	else
	{
		while(fscanf(f,"%d %d %s %f %d %s %d\n",&m1.id,&m1.type,m1.contenu,&m1.dechets,&m1.d.jour,m1.d.mois,&m1.d.annee)!=EOF)
	  	{
			if(m1.id!=id1)
			{
			fprintf(g,"%d %d %s %f %d %s %d\n",m1.id,m1.type,m1.contenu,m1.dechets,m1.d.jour,m1.d.mois,m1.d.annee);
			}
	  	}
		fclose(f);
		fclose(g);
remove("menu.txt");
rename("menu1.txt","menu.txt");
	}
}
////////////////////////////////////////////////////////////////////
void modifier_menu(menu m,int idverifmenu)
{
FILE *f,*g;
menu m1;
f=fopen("menu.txt","r");
g=fopen("menu1.txt","w+");
if(f==NULL || g==NULL)
return;
else
{
	while(fscanf(f,"%d %d %s %f %d %s %d\n",&m1.id,&m1.type,m1.contenu,&m1.dechets,&m1.d.jour,m1.d.mois,&m1.d.annee) != EOF)
	{
		if(m1.id!=idverifmenu)
		{
			fprintf(g,"%d %d %s %f %d %s %d\n",m1.id, m1.type, m1.contenu, m1.dechets, m1.d.jour, m1.d.mois, m1.d.annee);
		}
		else if(m1.id==idverifmenu)
		{
			fprintf(g,"%d %d %s %f %d %s %d\n",m.id, m.type, m.contenu, m.dechets, m.d.jour, m.d.mois, m.d.annee);
			
		}
	}
}
fclose(f);
fclose(g);
remove("menu.txt");
rename("menu1.txt","menu.txt");
}
///////////////////////////////////////////////////////////////////////////////////////
void afficher_menu(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	int id;
	int type;
	char contenu[50];
	float dechets;
	int jour;
	char mois[20];
	int annee;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
 	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", EID, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", ETYPE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("contenu", renderer, "text", ECONTENU, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("dechets", renderer, "text", EDECHETS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EJOUR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EMOIS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text", EANNEE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_FLOAT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);

	f=fopen("menu.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("menu.txt","a+");
		while(fscanf(f,"%d %d %s %f %d %s %d\n",&id,&type,contenu,&dechets,&jour,mois,&annee)!=EOF)
		{
			gtk_list_store_append (store,&iter);
			gtk_list_store_set (store, &iter, EID, id, ETYPE, type, ECONTENU, contenu, EDECHETS, dechets, EJOUR, jour, EMOIS, mois, EANNEE, annee, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
		

	}
}
///////////////////////////////////////////////////////////////
void vider_menu(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkListStore *store;
GtkTreeIter iter;
int id;
int type;
char contenu[50];
float dechets;
int jour;
char mois[10];
int annee;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
  {
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", EID, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", ETYPE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("contenu", renderer, "text", ECONTENU, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("dechets", renderer, "text", EDECHETS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EJOUR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EMOIS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text", EANNEE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
  }
store=gtk_list_store_new (COLUMNS, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_FLOAT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);
gtk_list_store_append (store,&iter);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));


}








