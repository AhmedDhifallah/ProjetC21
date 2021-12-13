#include <gtk/gtk.h>
#include <glib.h>
#include <string.h>
#include <stdbool.h>


typedef struct
{
int jour;
char mois[20];
int annee;
}date;

typedef struct
{
int id;
int type;
char contenu[50];
float dechets;
date d;
}menu;


void ajouter_menu(menu m);
int rechercher_menu (int idrechmenu);
void afficherrecherche_menu(int idrechmenu,char msgmenu[],int RES);
void trier_les_dechets(float tab[]);
void meilleur_menu(int jo,char msgmeilleurmenu[]/*,float tab[]*/);
void supprimer_menu(int id1);
void modifier_menu(menu m,int idverifmenu);
void afficher_menu(GtkWidget *liste);
void vider_menu(GtkWidget *liste);
