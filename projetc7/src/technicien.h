#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct 
{
    int j55;
    int m55;
    int a55;
}date55;




typedef struct 
{
    char id55[20];
    int type55;
    char marque55[20];
    char garantie55[50];
    date55 d55;
}capteur55 ;





void supprimer_capt(capteur55 u);
void modifier_capt(capteur55 u);
void afficher_capt(GtkWidget *liste);
int chercher_capt(char id55[]);
capteur55 find_capt(char id55[]);
void ajouter_captt(capteur55 u);



