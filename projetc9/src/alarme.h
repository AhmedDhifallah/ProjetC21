#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct alarme
{
char jour[20];
int heure;
char num[20];
char valeur[20];
}alarme;
void adalarme(GtkWidget *liste, char mouvement[]);
void adalarme1(GtkWidget *liste, char fumee[]);
void advider(GtkWidget *liste, char mouvement[]);
void advider1(GtkWidget *liste, char fumee[]);
void ajoutfumee(alarme p);
