#include<gtk/gtk.h>


typedef struct
{
int jour;
char mois[30];
int annee;
}ladate;

typedef struct
{
char nom_produit[30];
char reference[30];
char quantite[30];
ladate date_fab;
ladate date_exp;
}produit;


void ajouter_produit(produit p);
void afficher_produit(GtkWidget *liste);
//int recherche_produit(char ref_rech[]/*,char msg[]*/);
int recherche_produit(char ref_rech[]);
void supprimer_produit(char reference[]);
//void afficherrecherche_produit(char ref_rech[],char msg[],int rech);
void vider_produit(GtkWidget *liste);
void rupture_stock (char ref_rup[],char msgrup[]);
void modifier_produit(char ref_m[],produit p);
