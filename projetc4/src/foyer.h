#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct identifiant
{
char nom[20];
char prenom[20];
char ID[20];
int niveau;
char bloc[20];
char num[20];
}identifiant;

void ajouter_etudiant(identifiant c);
void modifier_etudiant(identifiant c,char Foyer[]);
void supprimer_etudiant(char id[20]);
void afficher_etudiant(GtkWidget *liste,char Foyer[]);
int chercher_etudiant(char id[20],char Foyer[]);
void vider(GtkWidget *liste,char Foyer[]);

