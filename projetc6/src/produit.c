#ifdef HAVE_CONFIG_H
# include <config.h>
#endif


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "produit.h"
#include<gtk/gtk.h>
/*--------------------------------*/
enum
{
	enom_produit,
	ereference,
	equantite,
	ejour,
	emois,
	eannee,
	ejour2,
	emois2,
	eannee2,
	COLUMNS
};

/*-------------------ajout-------------------------------*/


void ajouter_produit(produit p){
FILE *F;
F=fopen("produit.txt","a+");
if(F!=NULL)
{fprintf(F,"%s %s %s %d %s %d %d %s %d\n",p.nom_produit,p.reference,p.quantite,p.date_fab.jour,p.date_fab.mois,p.date_fab.annee,p.date_exp.jour,p.date_exp.mois,p.date_exp.annee);
fclose(F);
}
}



/*-------------------affichage-------------------------------*/


void afficher_produit(GtkWidget *liste)
{	produit p;

	GtkCellRenderer	*renderer; //envoyer la saisie de l utilisateur de chq chp
	GtkTreeViewColumn *column;  //correspondre la var du chp à son attribut de la liste	
	GtkTreeIter iter; //iterateur de l ensemble des elts de mon treeview
	GtkListStore *store; // var intermediaire pr iterer enregistrement par enreg ds mon treeview

	int jour;
	char mois[30];
	int annee;
	char nom_produit[30];
	char reference[30];
	char quantite[30];
	/*date date_fab;
	date date_exp;*/
	store==NULL;
	store=gtk_tree_view_get_model(liste);

	
	FILE *F;


	if (store==NULL)
	{

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom du produit", renderer, "text",enom_produit,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("reference", renderer, "text",ereference,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text",equantite,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
/*lmochkla f j w m w a des button mch widget*/
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour de fabrication", renderer, "text",ejour,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("mois de fabrication", renderer, "text",emois,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("annee de fabrication", renderer, "text",eannee,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour d'expiration", renderer, "text",ejour2,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("mois d'expiration", renderer, "text",emois2,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("annee d'expiration", renderer, "text",eannee2,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);

	F=fopen("produit.txt","r");
	if(F==NULL)
	{
		return;

	}
	else
	{/*jour w mois w annee?*/
		F=fopen("produit.txt","a+");
		while(fscanf(F,"%s %s %s %d %s %d %d %s %d\n",nom_produit,reference,quantite,&jour,mois,&annee,&jour,mois,&annee)!=EOF)
	{
		gtk_list_store_append (store,&iter);
		gtk_list_store_set (store, &iter, enom_produit, nom_produit, ereference, reference, equantite, quantite, ejour,jour, emois,mois, eannee,annee, ejour2,jour, emois2,mois, eannee2,annee, -1);
	}
	fclose(F);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}


	}



/*--------------------------------------------------recherche-------------------------------------------------------*/

int recherche_produit(char ref_rech[])
{
int trouve=-1;
//char msg[50];

produit p;

FILE *F=NULL;
F=fopen("produit.txt","r");
if(F!=NULL)
{
while(fscanf(F,"%s %s %s %d %s %d %d %s %d\n",p.nom_produit,p.reference,p.quantite,&p.date_fab.jour,p.date_fab.mois,&p.date_fab.annee,&p.date_exp.jour,p.date_exp.mois,&p.date_exp.annee)!=EOF)
{
	if(strcmp(ref_rech,p.reference)==0)
	{
		trouve=1;
	}


}
}
fclose(F);
return (trouve);
}

/*void afficherrecherche_produit(char ref_rech[],char msg[],int rech)
{
produit p;
    FILE *F;
	F = fopen("produit.txt","r");
if(F != NULL)
{
while(fscanf(F,"%s %s %s %d %s %d %d %s %d\n",p.nom_produit,p.reference,p.quantite,&p.date_fab.jour,p.date_fab.mois,&p.date_fab.annee,&p.date_exp.jour,p.date_exp.mois,&p.date_exp.annee) != EOF)
{
			if(strcmp(p.reference,ref_rech)==0)

				{strcpy(msg,"ce produit existe");}

}
}



    fclose(F);
    
}*/































/*-------------------recherche-------------------------------*/
/*int recherche_produit (char ref_rech[])
{
    produit p;
    FILE *F;
    F = fopen("produit.txt","r");
    if(F != NULL){
    	while(fscanf(F,"%s %s %s %d %s %d %d %s %d\n",p.nom_produit,p.reference,p.quantite,&p.date_fab.jour,p.date_fab.mois,&p.date_fab.annee,&p.date_exp.jour,p.date_exp.mois,&p.date_exp.annee)!=EOF)
        {
        	if(strcmp(p.reference,ref_rech)==0)
                {
       		     return 1;
        	}
    	}
}
    fclose(F);
    return 0;
}

void afficherrecherche_produit(char ref_rech[],char msg[],int RES)
{
    char ch1[50];
    char ch2[50];
    char ch3[50];
    char ch4[50];
    char ch5[50];
    char ch6[50];
    char ch7[50];
    char ch8[50];
    char ch9[50];
    produit p;
    FILE *F;
	F = fopen("produit.txt","r");
	if(F != NULL)
	  {
		while(fscanf(F,"%s %s %s %d %s %d %d %s %d\n",p.nom_produit,p.reference,p.quantite,&p.date_fab.jour,p.date_fab.mois,&p.date_fab.annee,&p.date_exp.jour,p.date_exp.mois,&p.date_exp.annee) != EOF)
		  {
			if(strcmp(p.reference,ref_rech)==0)
			  {     
				strcpy(ch1,"Reference: ");
       				strcat(ch1,p.reference);
				strcat(msg,ch1);
				strcat(msg,"\n");

				strcpy(ch2,"nom du produit:  ");
				strcat(ch2,p.nom_produit);
                                strcat(msg,ch2);
				strcat(msg,"\n");

				strcpy(ch3,"quantite: ");
				strcat(ch3,p.quantite);
				strcat(msg,ch3);
				strcat(msg,"\n");

				strcat(msg,"jour de fabrication: ");
				sprintf(ch4,"%d",p.date_fab.jour);
				strcat(msg,ch4);
				strcat(msg,"\n");

				strcpy(ch8,"mois de fabrication: ");
				strcat(ch8,p.date_fab.mois);
				strcat(msg,ch8);
				strcat(msg,"\n");

				strcat(msg,"annee de fabrication: ");
				sprintf(ch5,"%d",p.date_fab.annee);
				strcat(msg,ch5);
				strcat(msg,"\n");

				strcat(msg,"jour d'expiration: ");
				sprintf(ch6,"%d",p.date_exp.jour);
				strcat(msg,ch6);
				strcat(msg,"\n");

				strcpy(ch9,"mois d'expiration: ");
				strcat(ch9,p.date_exp.mois);
				strcat(msg,ch9);
				strcat(msg,"\n");


				strcat(msg,"annee d'expiration: ");
				sprintf(ch7,"%d",p.date_exp.annee);
				strcat(msg,ch7);
				


		

			  }
		  }
	  }



    fclose(F);
    
}*/













/*-------------------suppression-------------------------------*/


void supprimer_produit(char ref_s[])

{
    produit p;
    FILE *F;
    FILE *G;
    //char ref_s[30];
    F = fopen("produit.txt","r");
    G = fopen("Xproduit.txt","w");

     if (F==NULL || G==NULL)
	return;
     else 
     {
    	while(fscanf(F,"%s %s %s %d %s %d %d %s %d\n",p.nom_produit,p.reference,p.quantite,&p.date_fab.jour,p.date_fab.mois,&p.date_fab.annee,&p.date_exp.jour,p.date_exp.mois,&p.date_exp.annee) != EOF)
    {
        if(strcmp(p.reference,ref_s)!=0)//
            {
            fprintf(G,"%s %s %s %d %s %d %d %s %d\n",p.nom_produit,p.reference,p.quantite, p.date_fab.jour,p.date_fab.mois, p.date_fab.annee, p.date_exp.jour,p.date_exp.mois, p.date_exp.annee);
            }
    }
    fclose(F);
    fclose(G);
    remove("produit.txt");
    rename("Xproduit.txt","produit.txt");
    }
}

/*------------------------rupture de stock-------------------*/

void rupture_stock (char ref_rup[],char msgrup[])
{
    char ch[90]="0";
    char ch1[90];
    //char msgrup[10]="";
    produit p;
    FILE *F;
    F = fopen("produit.txt","r");
    if(F != NULL)
{
    	while(fscanf(F,"%s %s %s %d %s %d %d %s %d\n",p.nom_produit,p.reference,p.quantite,&p.date_fab.jour,p.date_fab.mois,&p.date_fab.annee,&p.date_exp.jour,p.date_exp.mois,&p.date_exp.annee)!=EOF)
        {
        	if( (strcmp(p.reference,ref_rup)==0) && (strcmp(p.quantite,ch)==0))
		{
   			strcpy(ch1,"Le produit que vous cherchez est en rupture de stock \n nom du produit: ");
			strcat(ch1,"\t");
			strcat(ch1,p.nom_produit);
			strcat(msgrup,ch1);      
		}
		else if ((strcmp(p.reference,ref_rup)==0) && (strcmp(p.quantite,ch)!=0))
			strcpy(msgrup,"Le produit n'est pas en rupture de stock.");
		
				
        }
}
fclose(F);

}


/*-------------------------modifiaction------------------------*/
void modifier_produit(char ref_m[], produit p)
{
produit p1;
FILE *F;
FILE *G;
F=fopen("produit.txt","r");
G=fopen("Xproduit.txt","a+");
while(fscanf(F,"%s %s %s %d %s %d %d %s %d\n",p1.nom_produit,p1.reference,p1.quantite,&p1.date_fab.jour,p1.date_fab.mois,&p1.date_fab.annee,&p1.date_exp.jour,p1.date_exp.mois,&p1.date_exp.annee)!=EOF)
{
if(strcmp(p1.reference,ref_m)!=0)
{fprintf(G,"%s %s %s %d %s %d %d %s %d\n",p1.nom_produit,p1.reference,p1.quantite,p1.date_fab.jour,p1.date_fab.mois,p1.date_fab.annee,p1.date_exp.jour,p1.date_exp.mois,p1.date_exp.annee);}
else 
{fprintf(G,"%s %s %s %d %s %d %d %s %d\n",p.nom_produit,p.reference,p.quantite,p.date_fab.jour,p.date_fab.mois,p.date_fab.annee,p.date_exp.jour,p.date_exp.mois,p.date_exp.annee);}
		
}

fclose(G);
fclose(F);
remove("produit.txt");
rename("Xproduit.txt","produit.txt");
}



































/*-------------------------modifiaction------------------------*/
/*void modifier_produit(char ref_m[],produit p2)
{
produit p;
FILE *F;
FILE *G;
//if (recherche_produit(ref_m)==1)
//{
F=fopen("produit.txt","r");
G = fopen("Xproduit.txt","a+");
while(fscanf(F,"%s %s %s %d %s %d %d %s %d\n",p.nom_produit,p.reference,p.quantite,&p.date_fab.jour,p.date_fab.mois,&p.date_fab.annee,&p.date_exp.jour,p.date_exp.mois,&p.date_exp.annee)!=EOF)
{
if(strcmp(p.reference,ref_m)==0)
{
strcpy(p.nom_produit,p2.nom_produit);
strcpy(p.reference,p2.reference);
strcpy(p.quantite,p2.quantite);
p.date_fab.jour=p2.date_fab.jour;
strcpy(p.date_fab.mois,p2.date_fab.mois);
p.date_fab.annee=p2.date_fab.annee;
p.date_exp.jour=p2.date_exp.jour;
strcpy(p.date_exp.mois,p2.date_exp.mois);
p.date_exp.annee=p2.date_exp.annee;


//}
fprintf(G,"%s %s %s %d %s %d %d %s %d\n",p.nom_produit,p.reference,p.quantite,&p.date_fab.jour,p.date_fab.mois,&p.date_fab.annee,&p.date_exp.jour,p.date_exp.mois,&p.date_exp.annee);

}
fclose(G);
fclose(F);
remove("produit.txt");
rename("Xproduit.txt","produit.txt");
//printf("modification effectuee avec succees");
}
//}
//else
//{
//printf("\n l'id de capteur n'existe pas");
//}
}*/





















/*----------------------actualisation----------------------*/


void vider_produit(GtkWidget *liste)
{    produit p;

	GtkCellRenderer	*renderer; //envoyer la saisie de l utilisateur de chq chp
	GtkTreeViewColumn *column;  //correspondre la var du chp à son attribut de la liste	
	GtkTreeIter iter; //iterateur de l ensemble des elts de mon treeview
	GtkListStore *store; // var intermediaire pr iterer enregistrement par enreg ds mon treeview

	int jour;
	char mois[30];
	int annee;
	char nom_produit[30];
	char reference[30];
	char quantite[30];
	store==NULL;

	
	FILE *F;

	store=gtk_tree_view_get_model(liste);


	if (store==NULL)
	{

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom du produit", renderer, "text",enom_produit,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("reference", renderer, "text",ereference,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text",equantite,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
/*lmochkla f j w m w a des button mch widget*/
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour de fabrication", renderer, "text",ejour,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("mois de fabrication", renderer, "text",emois,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("annee de fabrication", renderer, "text",eannee,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour d'expiration", renderer, "text",ejour2,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("mois d'expiration", renderer, "text",emois2,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("annee d'expiration", renderer, "text",eannee2,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	}

       store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT);
       gtk_list_store_append (store,&iter);
       gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

}
