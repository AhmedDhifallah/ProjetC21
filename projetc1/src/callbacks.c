#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "foyer.h"
#include "nutritionniste.h"
#include <stdlib.h>
#include <stdio.h>


/////////////////////// ahmed //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int b;
int A[10];


void
on_adbutton4_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f=NULL;
identifiant c;
int ni;
GtkWidget *niv;
GtkWidget *adcombobox1;
GtkWidget *name;
GtkWidget *lstname;
GtkWidget *id;
//nom prenom ID
lstname= lookup_widget (objet_graphique, "adentryNom1");
name= lookup_widget (objet_graphique, "adentryPrenom1");
id= lookup_widget (objet_graphique, "adentryID1");
strcpy(c.nom, gtk_entry_get_text(GTK_ENTRY(lstname)));
strcpy(c.prenom, gtk_entry_get_text(GTK_ENTRY(name)));
strcpy(c.ID, gtk_entry_get_text(GTK_ENTRY(id)));
//niveau
niv=lookup_widget(objet_graphique,"adspinbutton1");
ni=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(niv));
c.niveau=ni;
//bloc
if (b==1)		
{strcpy(c.bloc,"A");}
if (b==2)
{strcpy(c.bloc,"B");}
if (b==3)
{strcpy(c.bloc,"C");}
//num
adcombobox1=lookup_widget(objet_graphique,"adcombobox1");
if(strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(adcombobox1)))==0)
strcpy(c.num,"1");
if(strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(adcombobox1)))==0)
strcpy(c.num,"2");
if(strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(adcombobox1)))==0)
strcpy(c.num,"3");
if(strcmp("4",gtk_combo_box_get_active_text(GTK_COMBO_BOX(adcombobox1)))==0)
strcpy(c.num,"4");
if(strcmp("5",gtk_combo_box_get_active_text(GTK_COMBO_BOX(adcombobox1)))==0)
strcpy(c.num,"5");
ajouter_etudiant(c);
}


void
on_adradiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{b=1;}
}


void
on_adradiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{b=2;}
}


void
on_adradiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{b=3;}
}
void
on_adbuttonaff_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowaff;
GtkWidget *treeview,*Foyer_ESPRIT;
Foyer_ESPRIT=lookup_widget(objet_graphique,"Foyer_ESPRIT");
gtk_widget_destroy (Foyer_ESPRIT);
windowaff=create_Afficher_Foyer();
gtk_widget_show (windowaff);
treeview=lookup_widget(windowaff,"adtreeview1");
afficher_etudiant(treeview,"Foyer.txt");
}


void
on_adbutton1_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowaj,*Foyer_ESPRIT;
Foyer_ESPRIT=lookup_widget(objet_graphique,"Foyer_ESPRIT");
gtk_widget_destroy (Foyer_ESPRIT);
windowaj=create_Ajouter_Foyer();
gtk_widget_show (windowaj);

}


void
on_adbutton3_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmod,*Foyer_ESPRIT;
Foyer_ESPRIT=lookup_widget(objet_graphique,"Foyer_ESPRIT");
gtk_widget_destroy (Foyer_ESPRIT);
windowmod=create_Modifier_Foyer();
gtk_widget_show (windowmod);
}


void
on_adbutton2_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowsupp,*Foyer_ESPRIT;
Foyer_ESPRIT=lookup_widget(objet_graphique,"Foyer_ESPRIT");
gtk_widget_destroy (Foyer_ESPRIT);
windowsupp=create_Supprimer_Foyer();
gtk_widget_show (windowsupp);
}

void
on_adcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{A[0]=1;}
}
void
on_adbuttoncher_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
identifiant c;
char id[20];
GtkWidget *output;
GtkWidget *outputid;
int cher=0;
outputid= lookup_widget (objet_graphique, "adentry44");
strcpy(id, gtk_entry_get_text(GTK_ENTRY(outputid)));
cher=chercher_etudiant(id,"Foyer.txt");
if (cher==1)
{
output = lookup_widget(objet_graphique, "adlabel7") ;
gtk_label_set_text(GTK_LABEL(output),"id existe");
}
else if (cher==0)
{
output = lookup_widget(objet_graphique, "adlabel7") ;
gtk_label_set_text(GTK_LABEL(output),"id n existe pas");}
}
void
on_adbutton6_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
identifiant c;
GtkWidget *outp;
char idk[20];
outp= lookup_widget (objet_graphique,"adentryNom4");
strcpy(idk, gtk_entry_get_text(GTK_ENTRY(outp)));
if(A[0]==1)
{supprimer_etudiant(idk);}
}





void
on_adbutton5_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *lstname,*name,*id,*class,*blok,*number;
identifiant c,c1;
lstname= lookup_widget (objet_graphique, "adentryNom2");
name= lookup_widget (objet_graphique, "adentryprenom2");
strcpy(c.nom, gtk_entry_get_text(GTK_ENTRY(lstname)));
strcpy(c.prenom, gtk_entry_get_text(GTK_ENTRY(name)));
id= lookup_widget (objet_graphique, "adentryID2");
strcpy(c.ID, gtk_entry_get_text(GTK_ENTRY(id)));
class= lookup_widget (objet_graphique, "adentryNiveau2");
c.niveau=atoi(gtk_entry_get_text(GTK_ENTRY(class)));
blok= lookup_widget (objet_graphique, "adentryBloc3");
strcpy(c.bloc, gtk_entry_get_text(GTK_ENTRY(blok)));
number= lookup_widget (objet_graphique, "adentrychambre");
strcpy(c.num, gtk_entry_get_text(GTK_ENTRY(number)));
modifier_etudiant(c,"Foyer.txt");
}

void
on_adtreeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *nom;
gchar *prenom;
gchar *bloc;
gchar *ID;
int niveau;
gchar *num;
identifiant c;
//char id[20];
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&ID,3,&niveau,4,&bloc,5,&num,-1);
strcpy(c.nom,nom);
strcpy(c.nom,prenom);
strcpy(c.ID,ID);
c.niveau=niveau;
strcpy(c.bloc,bloc);
strcpy(c.num,num);
//supprimer_etudiant(id);
afficher_etudiant(treeview,"Foyer.txt");
}
}




void
on_adbuttonactualiser_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview,*Afficher_Foyer;
Afficher_Foyer=lookup_widget(objet_graphique,"Afficher_Foyer");
gtk_widget_destroy(Afficher_Foyer);
Afficher_Foyer=lookup_widget(objet_graphique,"Afficher_Foyer");
Afficher_Foyer=create_Afficher_Foyer();
gtk_widget_show(Afficher_Foyer);

treeview=lookup_widget(Afficher_Foyer,"adtreeview1");
vider(treeview,"Foyer.txt");
afficher_etudiant(treeview,"Foyer.txt");

}




void
on_adretour1_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_Foyer,*windowfo;
Ajouter_Foyer=lookup_widget(objet_graphique,"Ajouter_Foyer");
gtk_widget_destroy (Ajouter_Foyer);
windowfo=create_Foyer_ESPRIT();
gtk_widget_show (windowfo);


}


void
on_adretour2_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Modifier_Foyer,*windowfo;
Modifier_Foyer=lookup_widget(objet_graphique,"Modifier_Foyer");
gtk_widget_destroy (Modifier_Foyer);
windowfo=create_Foyer_ESPRIT();
gtk_widget_show (windowfo);
}


void
on_adretour3_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_Foyer,*windowfo;
Supprimer_Foyer=lookup_widget(objet_graphique,"Supprimer_Foyer");
gtk_widget_destroy (Supprimer_Foyer);
windowfo=create_Foyer_ESPRIT();
gtk_widget_show (windowfo);
}


void
on_adretour4_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Afficher_Foyer,*windowfo;
Afficher_Foyer=lookup_widget(objet_graphique,"Afficher_Foyer");
gtk_widget_destroy (Afficher_Foyer);
windowfo=create_Foyer_ESPRIT();
gtk_widget_show (windowfo);
}



void
on_adretour5_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Rechercher_Foyer,*windowfo;
Rechercher_Foyer=lookup_widget(objet_graphique,"Rechercher_Foyer");
gtk_widget_destroy (Rechercher_Foyer);
windowfo=create_Foyer_ESPRIT();
gtk_widget_show (windowfo);
}
void
on_adbuttonchercher_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Rechercher_Foyer,*Foyer_ESPRIT;
Foyer_ESPRIT=lookup_widget(objet_graphique,"Foyer_ESPRIT");
gtk_widget_destroy (Foyer_ESPRIT);
Rechercher_Foyer=create_Rechercher_Foyer();
gtk_widget_show (Rechercher_Foyer);

}

/////////////////////// chaima //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

menu m;
int x_cm,jo,id1,y_cm;
int idrechmenu=0;
char msgmeilleurmenu[100]=" ";
float tab[50];
int T[10];
int idverifmenu=0;
void
on_buttonactualisermenu_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestiondesmenusdelasemaine, *w12;
GtkWidget *treeview1_cm;
w12=lookup_widget(objet_graphique,"gestiondesmenusdelasemaine");
gestiondesmenusdelasemaine=create_gestiondesmenusdelasemaine();
gtk_widget_show(gestiondesmenusdelasemaine);
gtk_widget_hide (w12);
treeview1_cm=lookup_widget(gestiondesmenusdelasemaine,"treeviewmenu");
vider_menu(treeview1_cm);
afficher_menu(treeview1_cm);
}


void
on_ajouterunmenuacceuil_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowAjoutmenu,*gestiondesmenusdelasemaine;
gestiondesmenusdelasemaine=lookup_widget(objet_graphique,"gestiondesmenusdelasemaine");
gtk_widget_destroy(gestiondesmenusdelasemaine);
windowAjoutmenu=create_ajouterunmenu();
gtk_widget_show (windowAjoutmenu);
}


void
on_rechercherunmenuacceuil_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rechercherunmenu,*gestiondesmenusdelasemaine;
gestiondesmenusdelasemaine=lookup_widget(objet_graphique,"gestiondesmenusdelasemaine");
gtk_widget_destroy(gestiondesmenusdelasemaine);
rechercherunmenu=create_rechercherunmenu();
gtk_widget_show(rechercherunmenu);
}


void
on_button432_cm_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowmeilleur,*gestiondesmenusdelasemaine;
gestiondesmenusdelasemaine=lookup_widget(objet_graphique,"gestiondesmenusdelasemaine");
gtk_widget_destroy(gestiondesmenusdelasemaine);
windowmeilleur=create_meilleurmenudelasemaine();
gtk_widget_show (windowmeilleur);
}


void
on_modifierunmenuacceuil_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowVerifModifmenu, *gestiondesmenusdelasemaine;

gestiondesmenusdelasemaine=lookup_widget(objet_graphique,"gestiondesmenusdelasemaine");
gtk_widget_destroy(gestiondesmenusdelasemaine);
windowVerifModifmenu=create_verifierlamodification();
gtk_widget_show (windowVerifModifmenu);
}


void
on_supprimerunmenuacceuil_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowSuppmenu, *gestiondesmenusdelasemaine;

gestiondesmenusdelasemaine=lookup_widget(objet_graphique,"gestiondesmenusdelasemaine");
gtk_widget_destroy(gestiondesmenusdelasemaine);
windowSuppmenu=create_supprimerunmenu ();
gtk_widget_show (windowSuppmenu);
}


void
on_buttonajouterafficher_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestiondesmenusdelasemaine;
GtkWidget *ajouterunmenu;
GtkWidget *treeview1_cm;
ajouterunmenu=lookup_widget(objet_graphique,"ajouterunmenu");
gtk_widget_destroy(ajouterunmenu);
gestiondesmenusdelasemaine=lookup_widget(objet_graphique,"gestiondesmenusdelasemaine");
gestiondesmenusdelasemaine=create_gestiondesmenusdelasemaine();
gtk_widget_show(gestiondesmenusdelasemaine);
treeview1_cm=lookup_widget(gestiondesmenusdelasemaine,"treeviewmenu");
afficher_menu(treeview1_cm);
}


void
on_button4_cm_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutcontenu, *ajoutid, *ajoutdechets, *idajoutnondisponible, *ajouterunmenu;
GtkWidget *Jour, *Annee;
GtkWidget *Comboboxmois;
GtkWidget *toggleajout1, *toggleajout2, *toggleajout3;
menu m;



ajoutcontenu = lookup_widget (objet_graphique, "entry2_cm");
ajoutid = lookup_widget (objet_graphique, "entry13_cm");
ajoutdechets = lookup_widget (objet_graphique, "entry1_cm");
Jour = lookup_widget (objet_graphique, "jourajoutcm");
Annee = lookup_widget (objet_graphique, "anneeajoutcm");
Comboboxmois = lookup_widget (objet_graphique, "moisajoutcm");

//toggleajout1 = lookup_widget (objet_graphique, "radiobutton1_cm");
//toggleajout2 = lookup_widget (objet_graphique, "radiobutton2_cm");
//toggleajout3 = lookup_widget (objet_graphique, "radiobutton3_cm");


strcpy(m.contenu, gtk_entry_get_text(GTK_ENTRY(ajoutcontenu)));
m.id=atoi(gtk_entry_get_text(GTK_ENTRY(ajoutid)));
m.dechets=atof(gtk_entry_get_text(GTK_ENTRY(ajoutdechets)));
m.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
m.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));
idrechmenu=atoi(gtk_entry_get_text(GTK_ENTRY(ajoutid)));

if(strcmp("Janvier",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmois)))==0)
	strcpy(m.d.mois,"Janvier");
if(strcmp("Février",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmois)))==0)
	strcpy(m.d.mois,"Février");
if(strcmp("Mars",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmois)))==0)
	strcpy(m.d.mois,"Mars");
if(strcmp("Avril",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmois)))==0)
	strcpy(m.d.mois,"Avril");
if(strcmp("Mai",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmois)))==0)
	strcpy(m.d.mois,"Mai");
if(strcmp("Juin",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmois)))==0)
	strcpy(m.d.mois,"Juin");
if(strcmp("Juillet",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmois)))==0)
	strcpy(m.d.mois,"Juillet");
if(strcmp("Aout",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmois)))==0)
	strcpy(m.d.mois,"Aout");
if(strcmp("Septembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmois)))==0)
	strcpy(m.d.mois,"Septembre");
if(strcmp("Octobre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmois)))==0)
	strcpy(m.d.mois,"Octobre");
if(strcmp("Novembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmois)))==0)
	strcpy(m.d.mois,"Novembre");
if(strcmp("Décembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxmois)))==0) 
	strcpy(m.d.mois,"Décembre");

	if(x_cm==1)
		{m.type=1;}
	if (x_cm==2)
		{m.type=2;}
	if (x_cm==3)
		{m.type=3;}


if (rechercher_menu(idrechmenu)==0)
{
	ajouter_menu(m);
}
else if (rechercher_menu(idrechmenu)==1)
{
	ajouterunmenu=lookup_widget(objet_graphique,"ajouterunmenu");
	gtk_widget_destroy(ajouterunmenu);
	idajoutnondisponible=create_idajoutnondisponible();
	gtk_widget_show(idajoutnondisponible);
}


}



void
on_radiobutton1_cm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x_cm=1;}
}


void
on_radiobutton2_cm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x_cm=2;}
}


void
on_radiobutton3_cm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x_cm=3;}
}

void
on_treeviewmenu_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gint* id;
	gint* type;
	gchar* contenu;
	float dechets;
	gint* jour;
	gchar* mois;
	gint* annee;
	menu m;


	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
 	
	if (gtk_tree_model_get_iter(model, &iter, path))
	{
	//obtention des valeurs de la ligne soulignéé
	
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &type, 2, &contenu, 3, &dechets, 4, &jour, 5, &mois, 6, &annee, -1);
		//copie des valeurs dans la variable m de type menu pour le passer à la fonction de suppression
		m.id=id;
		m.type=type;
		strcpy(m.contenu,contenu);
		m.dechets=dechets;
		m.d.jour=jour;
		strcpy(m.d.mois,mois);
		m.d.annee=annee;
		//appel de la fonction de suppression
		supprimer_menu(m.id);
		//mise à jour de l'affichage de la treeview
		afficher_menu(treeview);
	}
}


void
on_button111_cm_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *IDEN, *sortiemenu;
int idrechmenu,RES=0;
char msgmenu[200]="";

IDEN=lookup_widget(objet_graphique,"entry777_cm");
sortiemenu=lookup_widget(objet_graphique,"sortierecherche_cm");

idrechmenu=atoi(gtk_entry_get_text(GTK_ENTRY(IDEN)));
RES=rechercher_menu(idrechmenu);
if(RES==1)
{
	afficherrecherche_menu(idrechmenu,msgmenu,RES);
}
else if(RES==0)
{
	strcpy(msgmenu,"Ce menu n'existe pas");
}
gtk_label_set_text(GTK_LABEL(sortiemenu), msgmenu);
}


void
on_button2222_cm_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestiondesmenusdelasemaine, *rechercherunmenu;
rechercherunmenu=lookup_widget(objet_graphique,"rechercherunmenu");
gtk_widget_destroy(rechercherunmenu);
gestiondesmenusdelasemaine=create_gestiondesmenusdelasemaine();
gtk_widget_show(gestiondesmenusdelasemaine);
}


void
on_button44444_cm_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
//char msgmeilleurmenu[100]="";
//float tab[50];
GtkWidget *choixjour, *sortie2menu;
//int jo;
choixjour=lookup_widget(objet_graphique,"spinbuttonmenu_cm");
jo=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (choixjour));
sortie2menu=lookup_widget(objet_graphique,"label63sortie_cm");
meilleur_menu(jo,msgmeilleurmenu/*,tab*/);
gtk_label_set_text(GTK_LABEL(sortie2menu), msgmeilleurmenu);

}


void
on_button234_cm_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestiondesmenusdelasemaine, *meilleurmenudelasemaine;
meilleurmenudelasemaine=lookup_widget(objet_graphique,"meilleurmenudelasemaine");
gtk_widget_hide(meilleurmenudelasemaine);
gestiondesmenusdelasemaine=create_gestiondesmenusdelasemaine();
gtk_widget_show(gestiondesmenusdelasemaine);
}


void
on_buttonsupprimerafficher_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestiondesmenusdelasemaine;
GtkWidget *supprimerunmenu;
GtkWidget *treeview1_cm;
supprimerunmenu=lookup_widget(objet_graphique,"supprimerunmenu");
gtk_widget_destroy(supprimerunmenu);
gestiondesmenusdelasemaine=lookup_widget(objet_graphique,"gestiondesmenusdelasemaine");
gestiondesmenusdelasemaine=create_gestiondesmenusdelasemaine();
gtk_widget_show(gestiondesmenusdelasemaine);
treeview1_cm=lookup_widget(gestiondesmenusdelasemaine,"treeviewmenu");
afficher_menu(treeview1_cm);
}


void
on_button7_cm_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *suppressionid, *supprimerunmenu, *supprimererreur;
menu m;
int id1,resul;
suppressionid = lookup_widget (objet_graphique, "entry3333_cm");
id1=atoi(gtk_entry_get_text(GTK_ENTRY(suppressionid)));
resul=rechercher_menu(id1);
if(T[0]==1 && resul==1)
{
	supprimer_menu(id1);
}
 
else if(resul==0)
{
supprimerunmenu=lookup_widget(objet_graphique,"supprimerunmenu");
gtk_widget_destroy(supprimerunmenu);
supprimererreur=create_supprimererreur();
gtk_widget_show(supprimererreur);	
}
}


void
on_checkbutton3_cm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{T[0]=1;}
}


void
on_button6_cm_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifcontenu, *modifid, *modifdechets;
GtkWidget *JJ, *AA;
GtkWidget *Combomois;
GtkWidget *toggleajout11, *toggleajout12, *toggleajout13;
menu m;

modifcontenu = lookup_widget (objet_graphique, "entry444_cm");
modifid = lookup_widget (objet_graphique, "entry111_cm");
modifdechets = lookup_widget (objet_graphique, "entry222_cm");
JJ = lookup_widget (objet_graphique, "spinbutton55_cm");
AA = lookup_widget (objet_graphique, "spinbutton66_cm");
Combomois = lookup_widget (objet_graphique, "combobox111_cm");

strcpy(m.contenu, gtk_entry_get_text(GTK_ENTRY(modifcontenu)));
//idrechmenu=atoi(gtk_entry_get_text(GTK_ENTRY(modifid)));
m.dechets=atof(gtk_entry_get_text(GTK_ENTRY(modifdechets)));
m.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (JJ));
m.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (AA));
m.id=atoi(gtk_entry_get_text(GTK_ENTRY(modifid)));

if(strcmp("Janvier",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combomois)))==0)
	strcpy(m.d.mois,"Janvier");
else if(strcmp("Février",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combomois)))==0)
	strcpy(m.d.mois,"Février");
else if(strcmp("Mars",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combomois)))==0)
	strcpy(m.d.mois,"Mars");
else if(strcmp("Avril",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combomois)))==0)
	strcpy(m.d.mois,"Avril");
else if(strcmp("Mai",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combomois)))==0)
	strcpy(m.d.mois,"Mai");
else if(strcmp("Juin",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combomois)))==0)
	strcpy(m.d.mois,"Juin");
else if(strcmp("Juillet",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combomois)))==0)
	strcpy(m.d.mois,"Juillet");
else if(strcmp("Aout",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combomois)))==0)
	strcpy(m.d.mois,"Aout");
else if(strcmp("Septembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combomois)))==0)
	strcpy(m.d.mois,"Septembre");
else if(strcmp("Octobre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combomois)))==0)
	strcpy(m.d.mois,"Octobre");
else if(strcmp("Novembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combomois)))==0)
	strcpy(m.d.mois,"Novembre");
else if(strcmp("Décembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combomois)))==0)
	strcpy(m.d.mois,"Décembre");

if(y_cm==1)
	{m.type=1;}
if (y_cm==2)
	{m.type=2;}
if (y_cm==3)
	{m.type=3;}

if (rechercher_menu(idverifmenu)==1)
{
	modifier_menu(m,idverifmenu);
}
}


void
on_buttonmodifierafficher_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifierunmenu;
GtkWidget *gestiondesmenusdelasemaine;
GtkWidget *treeview1_cm;
modifierunmenu=lookup_widget(objet_graphique,"modifierunmenu");
gtk_widget_destroy(modifierunmenu);
gestiondesmenusdelasemaine=lookup_widget(objet_graphique,"gestiondesmenusdelasemaine");
gestiondesmenusdelasemaine=create_gestiondesmenusdelasemaine();
gtk_widget_show(gestiondesmenusdelasemaine);
treeview1_cm=lookup_widget(gestiondesmenusdelasemaine,"treeviewmenu");
afficher_menu(treeview1_cm);
}






void
on_radiobutton11_cm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y_cm=1;}
}


void
on_radiobutton12_cm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y_cm=2;}
}


void
on_radiobutton13_cm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y_cm=3;}
}


void
on_button7777_cm_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajouterunmenu, *idajoutnondisponible;
idajoutnondisponible=lookup_widget(objet_graphique,"idajoutnondisponible");
gtk_widget_destroy(idajoutnondisponible);
ajouterunmenu=create_ajouterunmenu();
gtk_widget_show(ajouterunmenu);
}






void
on_button200_cm_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *supprimerunmenu, *supprimererreur;
supprimererreur=lookup_widget(objet_graphique,"supprimererreur");
gtk_widget_destroy(supprimererreur);
supprimerunmenu=create_supprimerunmenu();
gtk_widget_show(supprimerunmenu);
}


void
on_buttonmodifierverif_cm_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *verif18, *windowModifmenu, *verifierlamodification, *modifiererreur;
//int idverifmenu;
verif18=lookup_widget(objet_graphique,"entryverifmodif_cm");
idverifmenu=atoi(gtk_entry_get_text(GTK_ENTRY(verif18)));
if (rechercher_menu(idverifmenu)==1)
{
windowModifmenu=create_modifierunmenu();
gtk_widget_show (windowModifmenu);
verifierlamodification=lookup_widget(objet_graphique,"verifierlamodification");
gtk_widget_destroy(verifierlamodification);
}
if (rechercher_menu(idverifmenu)==0)
{
modifiererreur=create_modifiererreur();
gtk_widget_show (modifiererreur);
verifierlamodification=lookup_widget(objet_graphique,"verifierlamodification");
gtk_widget_destroy(verifierlamodification);
}
}

void
on_button244_cm_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modifiererreur, *verifierlamodification;
modifiererreur=lookup_widget(objet_graphique,"modifiererreur");
gtk_widget_destroy(modifiererreur);
verifierlamodification=create_verifierlamodification();
gtk_widget_show(verifierlamodification);
}





void
on_buttonretour_cm_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestiondesmenusdelasemaine, *verifierlamodification;
verifierlamodification=lookup_widget(objet_graphique,"verifierlamodification");
gtk_widget_destroy(verifierlamodification);
gestiondesmenusdelasemaine=create_gestiondesmenusdelasemaine();
gtk_widget_show(gestiondesmenusdelasemaine);
}

