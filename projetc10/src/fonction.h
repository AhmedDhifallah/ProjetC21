#include <gtk/gtk.h>
typedef struct 
{
int j;
int m;
int a;
char h[50];
}date25 ;

typedef struct 
{
char id[100];
char nom[100];
char prenom[100];
char reclamation[50];
date25 d ;
char type[100];
char choix [100];
}recl;






int rech5(char id[]);
void ajouter_reclamation(recl r);
void supprimer_reclamation(char id[]);
void modifier_reclamation(recl re,char id[]);
void afficher5(GtkWidget *liste);
void autres(int t[],char texte[],int x);
void radio(int x,char msg[]);
recl find5(char id[]);
void sercive(char texte[]);
void supprimer25(recl p);
