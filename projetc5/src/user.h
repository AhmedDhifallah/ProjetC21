#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct Date
{
int jour,mois,annee;
}date2;
typedef struct Utilisateur
{
char cin[50];
char nom[20];
char prenom[20];
char sexe[20];
char role[50];
int niveau;
date2 d;
}utilisateur;


void ajouter(utilisateur u);
void modifier(utilisateur u);
void afichertt();
void supprimer(char cin[]);
int chercher(char cin[]);
utilisateur find(char cin[]);
int nbretude(int niv);


typedef struct user
{
char userr[50];
char pass[50];
}user;

int chercherrr(char util[],char pass[]);
int chercherr(char util[],char pass[]);
int nbrdate(int jour,int mois,int annee);
