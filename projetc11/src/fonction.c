#include "fonction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>


int rech5(char id[])
{
recl r;
int k=0;
FILE*F;
F=fopen("Reclamations.txt","r");
if (F!=NULL)
{

while( fscanf(F,"%s %s %s %s %s %s %d %d %d %s \n",r.id,r.nom,r.prenom,r.reclamation,r.type,r.choix,&r.d.j,&r.d.m,&r.d.a,r.d.h)!=(EOF))
{
if (strcmp(id,r.id) == 0)
	{ 
		k=1;
	}
}
}
fclose(F);
return k;
}
void ajouter_reclamation(recl r)
{
FILE*F;
F=fopen("Reclamations.txt","a+");
if (F!=NULL)
{

fprintf(F,"%s %s %s %s %s %s %d %d %d %s \n",r.id,r.nom,r.prenom,r.reclamation,r.type,r.choix,r.d.j,r.d.m,r.d.a,r.d.h);
fclose(F);
}
else
printf("le fichier introuvable");
}

void supprimer_reclamation(char id[])
{
recl r;

if (rech5(id)== 1)
{
FILE*fich,*F;
F=fopen("Reclamations.txt","r");
fich = fopen("tempetudiant.txt","a+");
while (fscanf(F,"%s %s %s %s %s %s %d %d %d %s \n",r.id,r.nom,r.prenom,r.reclamation,r.type,r.choix,&r.d.j,&r.d.m,&r.d.a,r.d.h)!=(EOF))
{
if(strcmp(id,r.id) !=0)
{
fprintf(fich,"%s %s %s %s %s %s %d %d %d %s \n",r.id,r.nom,r.prenom,r.reclamation,r.type,r.choix,r.d.j,r.d.m,r.d.a,r.d.h);
}
}
fclose(fich);
fclose(F);
remove("Reclamations.txt");
rename("tempetudiant.txt","Reclamations.txt");
printf("suppression, effectuee avec succees");
}

else
{
printf("\n cet identifiant d'etudiant n'existe pas");
}
}
void modifier_reclamation(recl re,char id[])
{
FILE*F,*fich;
recl r;
if(rech5(id) == 1)
{

F=fopen("Reclamations.txt","r");
fich=fopen("tempetudiants.txt","a");
while (fscanf(F,"%s %s %s %s %s %s %d %d %d %s \n",r.id,r.nom,r.prenom,r.reclamation,r.type,r.choix,&r.d.j,&r.d.m,&r.d.a,r.d.h)!=(EOF))
{
if(strcmp(id,r.id) == 0 )
{
strcpy(r.id,re.id);
strcpy(r.nom,re.nom);
strcpy(r.prenom,re.prenom);
strcpy(r.reclamation,re.reclamation);
strcpy(r.type,re.type);
strcpy(r.choix,re.choix);
strcpy(r.d.h,re.d.h);
r.d.j=re.d.j;
r.d.m=re.d.m;
r.d.a=re.d.a;
}
fprintf(fich,"%s %s %s %s %s %s %d %d %d %s \n",r.id,r.nom,r.prenom,r.reclamation,r.type,r.choix,r.d.j,r.d.m,r.d.a,r.d.h);
}

fclose(F);
fclose(fich);
remove("Reclamations.txt");
rename("tempetudiants.txt","Reclamations.txt");
}
else
{
printf("\n cet identifiant d'etudiant n'existe pas \n");
}
}






enum
{
	EID,
	ENOM,
	EPRENOM,
	ERECLAMATION,
	ETYPE,
	ECHOIX,
	EJOUR,
	EMOIS,
	EANNEE,
	EHEURE,
	COLUMNS


};



void afficher5(GtkWidget *liste)
{

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore   *store;
	char id[100];
	char nom[100];
	char prenom[100];
	char type[100];
	char choix[100];
	char heure[100];
	char reclamation[100];
	int jour ;
	int mois ;
	int annee ;
	recl r;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL) 
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("reclamation",renderer,"text",ERECLAMATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("choix",renderer,"text",ECHOIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("heure",renderer,"text",EHEURE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING);

f = fopen ("Reclamations.txt","r");

if(f==NULL)
{
	return;	
}
else
{
	f = fopen ("Reclamations.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s \n",id,nom,prenom,reclamation,type,choix,&jour,&mois,&annee,heure)!=EOF)
		{ 

		gtk_list_store_append(store,&iter);
		gtk_list_store_set (store,&iter,EID,id,ENOM,nom,EPRENOM,prenom,ERECLAMATION,reclamation,ETYPE,type,ECHOIX,choix,EJOUR,jour,EMOIS,mois,EANNEE,annee,EHEURE,heure,-1);
	
		}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);

}
}
///////////////////////////////////////////
void radio(int x,char msg[])
{
if (x ==1)
	strcpy(msg,"Restauration");
if (x ==2)
	strcpy(msg,"Hebergement");
}
///////////////////////////////////////////////////////////////////
void autres(int t[],char texte[],int x)
{
if(x==1)
{
if(t[0]==1)
strcat(texte,"plats'ou'desserts/");
if(t[1]==1)
strcat(texte,"Autres");
}
else
{
if(x==2)
	{
if(t[2]==1)
strcat(texte,"Binome'ou'Voisins/");
if(t[3]==1)
strcat(texte,"Equippement'ou'meubles/");
if(t[4]==1)
strcat(texte,"Autres");
	}
}
}


///////////////////////////////////////////////////////////////////////////
recl find5(char id[])
{
FILE *F ;
recl a;
recl r;
F=fopen ("Reclamations.txt","r");
if(F!=NULL){
while (fscanf(F,"%s %s %s %s %s %s %d %d %d %s \n",r.id,r.nom,r.prenom,r.reclamation,r.type,r.choix,&r.d.j,&r.d.m,&r.d.a,r.d.h)!=(EOF))
	{
		if (strcmp(r.id,id)==0)
		{	
			a =r ;
		}
	}
}
fclose(F);
return a ;
}




/////////////////////////////////////////////////////////////////////////
void sercive(char texte[])
    {
        int p,h;
        FILE*f=NULL;
        recl r;
        f=fopen("Reclamations.txt","r");
        p=0;
        h=0;
while (fscanf(f,"%s %s %s %s %s %s %d %d %d %s \n",r.id,r.nom,r.prenom,r.reclamation,r.type,r.choix,&r.d.j,&r.d.m,&r.d.a,r.d.h)!=(EOF))
        {
            if(strcmp("Restauration",r.type)==0)
            {
                p++;
            }
            if(strcmp("Hebergement",r.type)==0)
            {
                h++;
            }
		}
            if(p>h)
            {
                strcpy(texte,"la restauration est le service le plus reclamé");
            }
               else if (p<h)
            {
                strcpy(texte,"l' Hebergement est le service le plus reclamé");
            }
	    else
	{
		strcpy(texte,"Hebergement et la restauration sont reclamées le meme nombre de fois");	
	}
        
    }
///////////////////////////////////////////////////////////////////////////////////////////////////
void supprimer25(recl p)
{

FILE *f, *g;
recl k;
f=fopen("Reclamations.txt","r");
g=fopen("ghassen.txt","w");

if (f==NULL || g==NULL)
{
return;
}

else 
{
		while(fscanf(f,"%s %s %s %s %s %s %d %d %d %s \n",k.id,k.nom,k.prenom,k.reclamation,k.type,k.choix,&k.d.j,&k.d.m,&k.d.a,k.d.h)!=(EOF))
{
						if  (  (strcmp(p.id,k.id)!=0 )|| (strcmp(p.nom,k.nom)!=0 )||( strcmp(p.prenom,k.prenom)!=0) || (strcmp(p.reclamation,k.reclamation)!=0) || (strcmp(p.type,k.type)!=0) || (strcmp(p.choix,k.choix)!=0) || (p.d.j!=k.d.j)  || (p.d.m!=k.d.m) || (p.d.a!=k.d.a) || (p.d.h!=k.d.h) )

				fprintf(g,"%s %s %s %s %s %s %d %d %d %s \n",k.id,k.nom,k.prenom,k.reclamation,k.type,k.choix,k.d.j,k.d.m,k.d.a,k.d.h);

}


fclose(f);
fclose(g);
remove("Reclamations.txt");
rename("ghassen.txt","Reclamations.txt");

}
}






