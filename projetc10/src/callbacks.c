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
#include "user.h"
#include <stdlib.h>
#include <stdio.h>
#include "fonction.h"
#include "technicien.h"
#include "alarme.h"

/////////////////////// ahmed //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int b;
int A[10];
int x;

void
on_adbutton4_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f=NULL;
identifiant c;
int ni,cher2;
GtkWidget *niv;
GtkWidget *adcombobox1;
GtkWidget *name;
GtkWidget *lstname;
GtkWidget *id;
GtkWidget *outputtt;
GtkWidget *idf;


char idg[20];

//nom prenom ID
lstname= lookup_widget (objet_graphique, "adentryNom1");
name= lookup_widget (objet_graphique, "adentryPrenom1");
id= lookup_widget (objet_graphique, "adentryID1");
strcpy(c.nom, gtk_entry_get_text(GTK_ENTRY(lstname)));
strcpy(c.prenom, gtk_entry_get_text(GTK_ENTRY(name)));
strcpy(c.ID, gtk_entry_get_text(GTK_ENTRY(id)));
idf= lookup_widget (objet_graphique, "adentryID1");
strcpy(idg,gtk_entry_get_text(GTK_ENTRY(idf)));
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
cher2=chercher_etudiant(idg,"Foyer.txt");
if (cher2==0)
{
outputtt = lookup_widget(objet_graphique, "adlabel33") ;
gtk_label_set_text(GTK_LABEL(outputtt),"Ajout terminee");
ajouter_etudiant(c);
}
if (cher2==1)
{
outputtt = lookup_widget(objet_graphique, "adlabel33") ;
gtk_label_set_text(GTK_LABEL(outputtt),"ID existe reessayez");}
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
GtkWidget *outp,*ou;
char idk[20];
outp= lookup_widget (objet_graphique,"adentryNom4");
strcpy(idk, gtk_entry_get_text(GTK_ENTRY(outp)));
if(A[0]==1)
{supprimer_etudiant(idk);
ou = lookup_widget(objet_graphique, "adlabel77") ;
gtk_label_set_text(GTK_LABEL(ou),"Suppression terminee");}
}





void
on_adbutton5_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *lstname,*name,*id,*class,*blok,*number,*outt;
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
outt = lookup_widget(objet_graphique, "adlabel55") ;
gtk_label_set_text(GTK_LABEL(outt),"Modification terminee");
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
//char msgmeilleurmenu[100]=" ";
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
	//afficherrecherche_menu(idrechmenu,msgmenu,RES);
	gtk_label_set_text(GTK_LABEL(sortiemenu), "ce menu existe");
}
else if(RES==0)
{
	//strcpy(msgmenu,"Ce menu n'existe pas");
	gtk_label_set_text(GTK_LABEL(sortiemenu), "ce menu n'existe pas");
}

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
char msgmeilleurmenu[100]="";
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
GtkWidget *modifcontenu, *modifid, *modifdechets, *idmenumodifexiste;
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




/*------------------------------------------Aicha----------------------------------------------------------------------*/


#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "produit.h"
#include<stdlib.h>
#include<string.h>

char ref_rech[10]="";
produit p;
int y;
int rech=0;
char msg[100]="";

	
	
void
on_ai_verif_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *input, *output;
	
	char msgrup[90]="";
        char ref_rup[90];
	

	input=lookup_widget(objet_graphique,"ai_ref_rup");
	output=lookup_widget(objet_graphique,"label_rup");
	strcpy(ref_rup,gtk_entry_get_text(GTK_ENTRY(input)));
	
	if (recherche_produit(ref_rup)==1)
	{

		//strcpy(ref_rup,gtk_entry_get_text(GTK_ENTRY(input)));
		rupture_stock(ref_rup,msgrup);
		//gtk_label_set_text(GTK_LABEL(output), msgrup);

	}
	else /*if (recherche_produit(ref_rup)==)*/
	{
		strcpy(msgrup,"Ce produit n'existe pas");	
		//output = lookup_widget(objet_graphique, "label1") ;
		//gtk_label_set_text(GTK_LABEL(output),"le produit n'existe pas");
		//strcpy(msgrup,"Ce produit n'existe pas");
		//gtk_label_set_text(GTK_LABEL(output), msgrup);
	}
gtk_label_set_text(GTK_LABEL(output), msgrup);

}






void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	GtkTreeIter iter;
	gchar* nom_produit;
	gchar* reference;
	gchar* quantite;
	gint* jour;
	gchar* mois;
	gint* annee;
	gint* jour2;
	gchar* mois2;
	gint* annee2;
	produit p;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter, path))
	{
	
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0,&nom_produit, 1, &reference, 2, &quantite, 3, &jour, 4, &mois, 5, &annee, 6, &jour2, 7, &mois2, 8, &annee2, -1);
		strcpy(p.nom_produit,nom_produit);
		strcpy(p.reference,reference);
		strcpy(p.quantite,quantite);
		//bel atoi wale?
		p.date_fab.jour=jour;
		strcpy(p.date_fab.mois,mois);
		p.date_fab.annee=annee;
		p.date_exp.jour=jour2;
		strcpy(p.date_exp.mois,mois2);
		p.date_exp.annee=annee2;
		supprimer_produit(p.reference); /*thabet fil parametre*/
		afficher_produit(treeview);
	}

}


void
on_ai_ajouter2_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *ajout_produit;
 GtkWidget *affichage_produit;//

	affichage_produit=lookup_widget(button, "affichage_produit");//

	gtk_widget_destroy(affichage_produit);//
  ajout_produit=create_ajout_produit();
  gtk_widget_show (ajout_produit);


}


void
on_ai_modif2_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *modification_produit;
 GtkWidget *affichage_produit;//

	affichage_produit=lookup_widget(button, "affichage_produit");//

	gtk_widget_destroy(affichage_produit);//
  modification_produit=create_modification_produit();
  gtk_widget_show (modification_produit);

}


void
on_ai_rech2_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *recherche_produit;
  GtkWidget *affichage_produit;//

	affichage_produit=lookup_widget(button, "affichage_produit");//

	gtk_widget_destroy(affichage_produit);//

  recherche_produit=create_recherche_produit();
  gtk_widget_show (recherche_produit);
}


void
on_ai_supp2_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *suppression_produit;
	GtkWidget *affichage_produit;//

	affichage_produit=lookup_widget(button, "affichage_produit");//

	gtk_widget_destroy(affichage_produit);//
	suppression_produit=create_suppression_produit();
	gtk_widget_show (suppression_produit);


}


void
on_ai_ajouter1_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
produit p;
GtkWidget *existence;
//GtkWidget *input2;


GtkWidget *input1, *input2, *input3;
GtkWidget *ajout_produit;
GtkWidget *ai_jour1;
GtkWidget *ai_annee1;
GtkWidget *ai_jour2;
GtkWidget *ai_annee2;
GtkWidget *ai_combobox1;
GtkWidget *ai_combobox2;

char reference[50];


input2=lookup_widget(objet_graphique, "reference"); 
strcpy(reference,gtk_entry_get_text(GTK_ENTRY(input2)));



if(recherche_produit(reference)==-1)
{

/*produit p;

GtkWidget *input1, *input2, *input3;
GtkWidget *ajout_produit;
GtkWidget *ai_jour1;
GtkWidget *ai_annee1;
GtkWidget *ai_jour2;
GtkWidget *ai_annee2;
GtkWidget *ai_combobox1;
GtkWidget *ai_combobox2;*/


ajout_produit=lookup_widget(objet_graphique, "ajout_produit");

input1=lookup_widget(objet_graphique, "nom_produit");
//input2=lookup_widget(objet_graphique, "reference");
input3=lookup_widget(objet_graphique, "quantite");
ai_jour1=lookup_widget(objet_graphique, "ai_jour1");
ai_annee1=lookup_widget(objet_graphique, "ai_annee1");
ai_jour2=lookup_widget(objet_graphique, "ai_jour2");
ai_annee2=lookup_widget(objet_graphique, "ai_annee2");
ai_combobox1=lookup_widget(objet_graphique, "ai_combobox1");
ai_combobox2=lookup_widget(objet_graphique, "ai_combobox2");


strcpy(p.nom_produit,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.reference,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.quantite,gtk_entry_get_text(GTK_ENTRY(input3)));
p.date_fab.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(ai_jour1));
p.date_fab.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(ai_annee1));
p.date_exp.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(ai_jour2));
p.date_exp.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(ai_annee2));

if(strcmp("janvier",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox1)))==0)
strcpy(p.date_fab.mois,"janvier");
if(strcmp("fevrier",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox1)))==0)
strcpy(p.date_fab.mois,"fevrier");
if(strcmp("mars",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox1)))==0)
strcpy(p.date_fab.mois,"mars");
if(strcmp("avril",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox1)))==0)
strcpy(p.date_fab.mois,"avril");
if(strcmp("mai",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox1)))==0)
strcpy(p.date_fab.mois,"mai");
if(strcmp("juin",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox1)))==0)
strcpy(p.date_fab.mois,"juin");
if(strcmp("juillet",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox1)))==0)
strcpy(p.date_fab.mois,"juillet");
if(strcmp("aout",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox1)))==0)
strcpy(p.date_fab.mois,"aout");
if(strcmp("septembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox1)))==0)
strcpy(p.date_fab.mois,"septembre");
if(strcmp("octobre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox1)))==0)
strcpy(p.date_fab.mois,"octobre");
if(strcmp("novembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox1)))==0)
strcpy(p.date_fab.mois,"novembre");
if (strcmp("decembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox1)))==0)
strcpy(p.date_fab.mois,"decembre");


if(strcmp("janvier",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox2)))==0)
strcpy(p.date_exp.mois,"janvier");
if(strcmp("fevrier",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox2)))==0)
strcpy(p.date_exp.mois,"fevrier");
if(strcmp("mars",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox2)))==0)
strcpy(p.date_exp.mois,"mars");
if(strcmp("avril",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox2)))==0)
strcpy(p.date_exp.mois,"avril");
if(strcmp("mai",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox2)))==0)
strcpy(p.date_exp.mois,"mai");
if(strcmp("juin",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox2)))==0)
strcpy(p.date_exp.mois,"juin");
if(strcmp("juillet",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox2)))==0)
strcpy(p.date_exp.mois,"juillet");
if(strcmp("aout",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox2)))==0)
strcpy(p.date_exp.mois,"aout");
if(strcmp("septembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox2)))==0)
strcpy(p.date_exp.mois,"septembre");
if(strcmp("octobre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox2)))==0)
strcpy(p.date_exp.mois,"octobre");
if(strcmp("novembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox2)))==0)
strcpy(p.date_exp.mois,"novembre");
if(strcmp("decembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox2)))==0)
strcpy(p.date_exp.mois,"decembre");



ajouter_produit(p); 
}
else
{
  	existence=create_existence();
  	gtk_widget_show (existence);

}


}


void
on_ai_afficher1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *ajout_produit;
GtkWidget *affichage_produit;
GtkWidget *treeview1;

ajout_produit=lookup_widget(objet_graphique, "ajout_produit");


gtk_widget_destroy(ajout_produit);
affichage_produit=lookup_widget(objet_graphique,"affichage_produit");
affichage_produit=create_affichage_produit();

gtk_widget_show(affichage_produit);


treeview1=lookup_widget(affichage_produit,"treeview1");

afficher_produit(treeview1);

}


void
on_ai_supp1_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ //produit p;
  char ref_s[30];
  GtkWidget *input1;
  GtkWidget *suppression_produit;
  GtkWidget *output1;
  
  

  suppression_produit=lookup_widget(objet_graphique, "suppression_produit");
  input1=lookup_widget(objet_graphique, "ai_ref2");
  output1=lookup_widget(objet_graphique,"ai_labelsup");
  strcpy(ref_s,gtk_entry_get_text(GTK_ENTRY(input1)));
  

if ((y==1) && (recherche_produit(ref_s)==1))
{supprimer_produit(ref_s);
gtk_label_set_text(GTK_LABEL(output1), "la suppression est effectuée avec succes");
}
else if ((y==0) && (recherche_produit(ref_s)==1))
gtk_label_set_text(GTK_LABEL(output1), "veuillez confirmer la suppression");
else
gtk_label_set_text(GTK_LABEL(output1), "le produit n'existe pas");

 
  
}


void
on_ai_afficher2_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *suppression_produit;
GtkWidget *affichage_produit;
GtkWidget *treeview1;

suppression_produit=lookup_widget(objet_graphique, "suppression_produit");


gtk_widget_destroy(suppression_produit);
affichage_produit=lookup_widget(objet_graphique,"affichage_produit");
affichage_produit=create_affichage_produit();

gtk_widget_show(affichage_produit);


treeview1=lookup_widget(affichage_produit,"treeview1");

afficher_produit(treeview1);

}


void
on_ai_checkbutton1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))
y=1;
else 
{y=0;}
}




void
on_ai_modif1_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{produit p;


GtkWidget *input1, *input2, *input3, *output;
GtkWidget *modification_produit;
GtkWidget *ai_jour3;
GtkWidget *ai_annee3;
GtkWidget *ai_jour4;
GtkWidget *ai_annee4;
GtkWidget *ai_combobox30;
GtkWidget *ai_combobox40;
char ref_m[40];



modification_produit=lookup_widget(objet_graphique, "modification_produit");

input1=lookup_widget(objet_graphique, "nom_produit2");
input2=lookup_widget(objet_graphique, "reference2");
input3=lookup_widget(objet_graphique, "quantite2");
ai_jour3=lookup_widget(objet_graphique, "ai_jour3");
ai_annee3=lookup_widget(objet_graphique, "ai_annee3");
ai_jour4=lookup_widget(objet_graphique, "ai_jour4");
ai_annee4=lookup_widget(objet_graphique, "ai_annee4");
ai_combobox30=lookup_widget(objet_graphique, "ai_combobox30");
ai_combobox40=lookup_widget(objet_graphique, "ai_combobox40");
output=lookup_widget(objet_graphique,"ai_label_modif");


strcpy(p.nom_produit,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.reference,gtk_entry_get_text(GTK_ENTRY(input2)));

strcpy(ref_m,p.reference);

strcpy(p.quantite,gtk_entry_get_text(GTK_ENTRY(input3)));
p.date_fab.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(ai_jour3));
p.date_fab.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(ai_annee3));
p.date_exp.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(ai_jour4));
p.date_exp.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(ai_annee4));

if(strcmp("janvier",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox30)))==0)
strcpy(p.date_fab.mois,"janvier");
if(strcmp("fevrier",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox30)))==0)
strcpy(p.date_fab.mois,"fevrier");
if(strcmp("mars",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox30)))==0)
strcpy(p.date_fab.mois,"mars");
if(strcmp("avril",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox30)))==0)
strcpy(p.date_fab.mois,"avril");
if(strcmp("mai",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox30)))==0)
strcpy(p.date_fab.mois,"mai");
if(strcmp("juin",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox30)))==0)
strcpy(p.date_fab.mois,"juin");
if(strcmp("juillet",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox30)))==0)
strcpy(p.date_fab.mois,"juillet");
if(strcmp("aout",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox30)))==0)
strcpy(p.date_fab.mois,"aout");
if(strcmp("septembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox30)))==0)
strcpy(p.date_fab.mois,"septembre");
if(strcmp("octobre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox30)))==0)
strcpy(p.date_fab.mois,"octobre");
if(strcmp("novembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox30)))==0)
strcpy(p.date_fab.mois,"novembre");
if (strcmp("decembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox30)))==0)
strcpy(p.date_fab.mois,"decembre");


if(strcmp("janvier",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox40)))==0)
strcpy(p.date_exp.mois,"janvier");
if(strcmp("fevrier",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox40)))==0)
strcpy(p.date_exp.mois,"fevrier");
if(strcmp("mars",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox40)))==0)
strcpy(p.date_exp.mois,"mars");
if(strcmp("avril",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox40)))==0)
strcpy(p.date_exp.mois,"avril");
if(strcmp("mai",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox40)))==0)
strcpy(p.date_exp.mois,"mai");
if(strcmp("juin",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox40)))==0)
strcpy(p.date_exp.mois,"juin");
if(strcmp("juillet",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox40)))==0)
strcpy(p.date_exp.mois,"juillet");
if(strcmp("aout",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox40)))==0)
strcpy(p.date_exp.mois,"aout");
if(strcmp("septembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox40)))==0)
strcpy(p.date_exp.mois,"septembre");
if(strcmp("octobre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox40)))==0)
strcpy(p.date_exp.mois,"octobre");
if(strcmp("novembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox40)))==0)
strcpy(p.date_exp.mois,"novembre");
if(strcmp("decembre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(ai_combobox40)))==0)
strcpy(p.date_exp.mois,"decembre");

if ((x==1) && (recherche_produit(ref_m)==1))
{modifier_produit(ref_m,p); 
gtk_label_set_text(GTK_LABEL(output), "la modification est effectuée avec succes");
}

else
gtk_label_set_text(GTK_LABEL(output), "veuillez confirmer la modification");



}





/*void
on_ai_modif1_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{/*char ref_m[30];
  GtkWidget *input1;
  GtkWidget *modification_produit;

  modification_produit=lookup_widget(objet_graphique, "modification_produit");
  input1=lookup_widget(objet_graphique, "ai_ref"); barchaaa input....
  strcpy(ref_m,gtk_entry_get_text(GTK_ENTRY(input1)));
  if (x==1)
  modifier_produit(ref_m);*/



//}





void
on_ai_afficher3_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *modification_produit;
GtkWidget *affichage_produit;
GtkWidget *treeview1;

modification_produit=lookup_widget(objet_graphique, "modification_produit");


gtk_widget_destroy(modification_produit);
affichage_produit=lookup_widget(objet_graphique,"affichage_produit");
affichage_produit=create_affichage_produit();

gtk_widget_show(affichage_produit);


treeview1=lookup_widget(affichage_produit,"treeview1");

afficher_produit(treeview1);


}




/*void
on_ai_rech1_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{  
produit p,p1;
char ref_rech[20];
char msg[50];
GtkWidget *input, *output;
int rech=0;
input=lookup_widget(objet_graphique,"ai_ref3");
strcpy(ref_rech,gtk_entry_get_text(GTK_ENTRY(input)));
rech=recherche_produit(ref_rech);
if (rech==1)
{
output=lookup_widget(objet_graphique,"label_rech");
afficherrecherche_produit(ref_rech,msg,rech);
gtk_label_set_text(GTK_LABEL(output),msg);
}
else
{
strcpy(msg,"Ce produit n'existe pas");
gtk_label_set_text(GTK_LABEL(output),msg);
}
}*/



void
on_ai_rech1_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{  
	GtkWidget *input, *output;
	//char ref_rech[]="";
	//int rech=0;
	//char msg[50]="";
        //char ref_rech[50];
	
	
        
        input=lookup_widget(objet_graphique,"ai_ref3");
	output=lookup_widget(objet_graphique,"label_rech");

	strcpy(ref_rech,gtk_entry_get_text(GTK_ENTRY(input)));
	rech=recherche_produit(ref_rech);
	if(rech==1)
	{
		//afficherrecherche_produit(ref_rech,msg,rech);
		//gtk_label_set_text(GTK_LABEL(output),msg);
		gtk_label_set_text(GTK_LABEL(output),"le produit existe");
	}
	else   
	{
		//strcpy(msg,"Ce produit n'existe pas");
		gtk_label_set_text(GTK_LABEL(output),"le produit n'existe pas");
	}
//gtk_label_set_text(GTK_LABEL(output),msg);

}







void
on_ai_afficher4_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *recherche_produit;
GtkWidget *affichage_produit;
GtkWidget *treeview1;

recherche_produit=lookup_widget(objet_graphique, "recherche_produit");


gtk_widget_destroy(recherche_produit);
affichage_produit=lookup_widget(objet_graphique,"affichage_produit");
affichage_produit=create_affichage_produit();

gtk_widget_show(affichage_produit);


treeview1=lookup_widget(affichage_produit,"treeview1");

afficher_produit(treeview1);


}


void
on_ai_rupture2_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *rupture_stock;
 GtkWidget *affichage_produit;//

	affichage_produit=lookup_widget(button, "affichage_produit");//

	gtk_widget_destroy(affichage_produit);//
  rupture_stock=create_rupture_stock();
  gtk_widget_show (rupture_stock);


}


void
on_ai_actualiser_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *affichage_produit ,*w1;
 GtkWidget *treeview1;

 w1=lookup_widget(objet_graphique, "affichage_produit");
 affichage_produit=create_affichage_produit();

 gtk_widget_show (affichage_produit);
 
  gtk_widget_hide (w1);
  treeview1=lookup_widget(affichage_produit, "treeview1");
  
  vider_produit(treeview1);
  afficher_produit(treeview1);
}








/*void
on_ai_modification1_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *modification_produit1;
GtkWidget *modification_produit;
GtkWidget *inexistant;
GtkWidget *input1;
char ref_m[50];

input1=lookup_widget(objet_graphique, "ai_ref_m");
strcpy(ref_m,gtk_entry_get_text(GTK_ENTRY(input1)));



if(recherche_produit(ref_m)==1)
{
	modification_produit1=lookup_widget(objet_graphique, "modification_produit1");

	gtk_widget_destroy(modification_produit1);
  	modification_produit=create_modification_produit();
  	gtk_widget_show (modification_produit);
}
else
 {
	//modification_produit1=lookup_widget(objet_graphique, "modification_produit1");
  	inexistant=create_inexistant();
  	gtk_widget_show (inexistant);

 }
}*/





void
on_ai_afficher5_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *rupture_stock;
GtkWidget *affichage_produit;
GtkWidget *treeview1;

rupture_stock=lookup_widget(objet_graphique, "rupture_stock");


gtk_widget_destroy(rupture_stock);
affichage_produit=lookup_widget(objet_graphique,"affichage_produit");
affichage_produit=create_affichage_produit();

gtk_widget_show(affichage_produit);


treeview1=lookup_widget(affichage_produit,"treeview1");

afficher_produit(treeview1);


}





/*void
on_ai_afficher6_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *modification_produit1;
GtkWidget *affichage_produit;
GtkWidget *treeview1;

modification_produit1=lookup_widget(objet_graphique, "modification_produit1");


gtk_widget_destroy(modification_produit1);
affichage_produit=lookup_widget(objet_graphique,"affichage_produit");
affichage_produit=create_affichage_produit();

gtk_widget_show(affichage_produit);


treeview1=lookup_widget(affichage_produit,"treeview1");

afficher_produit(treeview1);

}*/







void
on_ai_modif3_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input, *output;
	
	
        
        input=lookup_widget(objet_graphique,"reference2");
	output=lookup_widget(objet_graphique,"ai_labelverif");

	strcpy(ref_rech,gtk_entry_get_text(GTK_ENTRY(input)));
	rech=recherche_produit(ref_rech);
	if(rech==1)
	{
		//afficherrecherche_produit(ref_rech,msg,rech);
		//gtk_label_set_text(GTK_LABEL(output),msg);
		gtk_label_set_text(GTK_LABEL(output),"Veuillez saisir la modification  ");
	}
	else   
	{
		
		gtk_label_set_text(GTK_LABEL(output),"           le produit n'existe pas \n \n Veuillez saisir un autre produit à modifier");
	}


}








void
on_ai_radiobutton1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))

{x=1;}


}


void
on_ai_radiobutton2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))

{x=2;}

}


/*-----------------------------------HOussem------------------------------------------*/

int po;
int et,af,ar,nu,tc;

int tub[5]={0,0,0,0,0};




void
on_hb_button22_clicked                 (GtkWidget   *objet_graphique,
                                        gpointer         user_data)
{

}


/*void
on_hb_afficher_admin_clicked           (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_espace_admin,*hb_gestion;
GtkWidget *treeview;
hb_espace_admin=lookup_widget(objet_graphique,"hb_espace_admin");
gtk_widget_destroy(hb_espace_admin);
hb_gestion=create_hb_gestion();

gtk_widget_show(hb_gestion);
treeview=lookup_widget(hb_gestion,"hb_treeview2");

afficher(treeview);
}
*/

void
on_hb_button15_ajouter_utilisateur_clicked
                                        (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_espace_admin,*hb_ajouter;
hb_espace_admin=lookup_widget(objet_graphique,"hb_espace_admin");
gtk_widget_destroy(hb_espace_admin);
hb_ajouter=create_hb_ajouter();
gtk_widget_show(hb_ajouter);
}



void
on_hb_ajouterrr_clicked                (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hbjour;
GtkWidget *hbmois;
GtkWidget *hbannee;
GtkWidget *hbniveau;
GtkWidget *Combobox1;
GtkWidget *hb_Combobox1;
GtkWidget *hb_Combobox2;

utilisateur u;
GtkWidget *input1, *input2, *input3,*pInfo;
GtkWidget *hb_ajouter,*output58;
hb_ajouter=lookup_widget(objet_graphique,"hb_ajouter");

input1=lookup_widget(objet_graphique,"hb_entry200");
input2=lookup_widget(objet_graphique,"hb_entry201");
input3=lookup_widget(objet_graphique,"hb_entry202");

hb_Combobox1=lookup_widget(objet_graphique,"hb_combobox1_sexe");
hb_Combobox2=lookup_widget(objet_graphique,"hb_combobox2_agent");


hbjour=lookup_widget(objet_graphique,"hb_spinbutton2_jour");
hbmois=lookup_widget(objet_graphique,"hb_spinbutton3_mois");
hbannee=lookup_widget(objet_graphique,"hb_spinbutton4_annee");
hbniveau=lookup_widget(objet_graphique,"hb_spinbutton1_niveau");



if(strcmp("Homme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(hb_Combobox1)))==0)
	{ strcpy(u.sexe,"Homme");}
else if (strcmp("Femme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(hb_Combobox1)))==0)
 {strcpy(u.sexe,"Femme");}




strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));

if (po==1)
{strcpy(u.role,"nutritioniste");}
if(po==2)
{strcpy(u.role,"technicien");}

if(po==3)
{
if(strcmp("Agentf",gtk_combo_box_get_active_text(GTK_COMBO_BOX(hb_Combobox2)))==0)
    {strcpy(u.role,"agentf");}
else if (strcmp("Agentr",gtk_combo_box_get_active_text(GTK_COMBO_BOX(hb_Combobox2)))==0)
    {strcpy(u.role,"agentr");}
}



u.niveau=0;
if(po==4)
{
strcpy(u.role,"etudiant");
u.niveau=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hbniveau));}



u.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hbjour));
u.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hbmois));
u.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hbannee));


if ( (strlen(u.cin)==8)  && (chercher(u.cin)==0))
{
ajouter(u);

pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"ajout  avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break; }

hb_ajouter=lookup_widget(objet_graphique,"hb_ajouter");
gtk_widget_destroy(hb_ajouter);
hb_ajouter=create_hb_ajouter();
gtk_widget_show(hb_ajouter);
}
else { 
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"cin doit contenir 8 chiffres ou déja existe");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;}	}

}


void
on_hb_radiobutton7_tech_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{po=2;}

}


void
on_hb_radiobutton9_etudiant_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{po=4;}
}


void
on_hb_radiobutton8_agent_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{po=3;}

}


void
on_hb_radiobutton5_nut_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{po=1;}

}


void
on_hb_treeview2_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
int jour;

int mois;
int annee;
gchar* role;
gchar* cin;
int niveau;
gchar* sexe;
utilisateur u;
GtkTreeModel *model =gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin,1, &nom,2,&prenom,3,&jour,4,&mois,5,&annee,6,&role,7,&sexe,8,&niveau,-1);

strcpy(u.cin,cin);
strcpy(u.nom,nom);
strcpy(u.prenom,prenom);

u.d.jour=jour;
u.d.mois=mois;
u.d.annee=annee;
strcpy(u.role,role);
strcpy(u.sexe,sexe);
u.niveau=niveau;
//supprimer(u);

supprimer2(u);


afficher(treeview);
}

}


void
on_hb_button27_aff_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_ajouter,*hb_gestion;
GtkWidget *treeview;
hb_ajouter=lookup_widget(objet_graphique,"hb_ajouter");
gtk_widget_destroy(hb_ajouter);
hb_gestion=create_hb_gestion();

gtk_widget_show(hb_gestion);
treeview=lookup_widget(hb_gestion,"hb_treeview2");

afficher(treeview);
}


void
on_hb_button24_actualiser_clicked      (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_gestion,*w1;
GtkWidget *treeview2;
w1=lookup_widget(objet_graphique,"hb_gestion");
hb_gestion=create_hb_gestion();
gtk_widget_show(hb_gestion);
gtk_widget_hide(w1);
treeview2=lookup_widget(hb_gestion,"hb_treeview2");
vider_admin(treeview2);
afficher(treeview2);
}


void
on_hb_button4_afichtoajouter_clicked   (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_gestion,*hb_ajouter;
hb_gestion=lookup_widget(objet_graphique,"hb_gestion");
gtk_widget_destroy(hb_gestion);
hb_ajouter=create_hb_ajouter();
gtk_widget_show(hb_ajouter);

}


void
on_hb_button26_retouraffich_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_gestion,*hb_suprrimer,*treeview;
hb_suprrimer=lookup_widget(objet_graphique,"hb_suprrimer");
gtk_widget_destroy(hb_suprrimer);
hb_gestion=create_hb_gestion();
gtk_widget_show(hb_gestion);
treeview=lookup_widget(hb_gestion,"hb_treeview2");

afficher(treeview);
}




void
on_hb_suprrimerrrr_clicked             (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
*cin,*output,*hb_suprrimer,*pInfo;
int x;
cin=lookup_widget(objet_graphique,"hb_entry8_cinsupp");
cin=gtk_entry_get_text(GTK_ENTRY(cin));
x=chercher(cin);
if (x==1)
{
supprimer(cin);


pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"supression  avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break; }

hb_suprrimer=lookup_widget(objet_graphique,"hb_suprrimer");
gtk_widget_destroy(hb_suprrimer);
hb_suprrimer=create_hb_suprrimer();
gtk_widget_show(hb_suprrimer);




}
else
{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"supression impossible , cin n'existe pas");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break; }}
}



void
on_hb_button25_suprrimer_clicked       (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_gestion,*hb_suprrimer;
hb_gestion=lookup_widget(objet_graphique,"hb_gestion");
gtk_widget_destroy(hb_gestion);
hb_suprrimer=create_hb_suprrimer();
gtk_widget_show(hb_suprrimer);
}


void
on_hb_button30_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int i;
char cin[500];
utilisateur j;
GtkWidget *hb_modifier,*input30,*hb_spin1,*hb_spin2,*hb_spin3,*hb_spin4,*output35,*output36;
GtkWidget *output31,*output32,*output33,*output45;
hb_modifier=lookup_widget(objet_graphique,"hb_modifier");
input30=lookup_widget(objet_graphique,"hb_entry100");

output32=lookup_widget(objet_graphique,"hb_entry8");
output33=lookup_widget(objet_graphique,"hb_entry9");
output35=lookup_widget(objet_graphique,"hb_entry23");
output36=lookup_widget(objet_graphique,"hb_entry24");
hb_spin1=lookup_widget(objet_graphique,"hb_spinbutton1");
hb_spin2=lookup_widget(objet_graphique,"hb_spinbutton2");
hb_spin3=lookup_widget(objet_graphique,"hb_spinbutton3");
hb_spin4=lookup_widget(objet_graphique,"hb_spinbutton4");
output45=lookup_widget(objet_graphique,"hb_label32");









strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input30)));
i=chercher(cin);
if (i==1)
{
   j=find(cin);

	gtk_entry_set_text(GTK_ENTRY(output32),j.nom);
	gtk_entry_set_text(GTK_ENTRY(output33),j.prenom);
		gtk_entry_set_text(GTK_ENTRY(output35),j.sexe);
	gtk_entry_set_text(GTK_ENTRY(output36),j.role);

	gtk_spin_button_set_value(GTK_SPIN_BUTTON(hb_spin1),j.d.jour);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(hb_spin2),j.d.mois);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(hb_spin3),j.d.annee);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(hb_spin4),j.niveau);
	gtk_label_set_text(GTK_LABEL(output45),"utilisateur trouve");

	}
else {
gtk_label_set_text(GTK_LABEL(output45),"non trouve");}


}


void
on_hb_button24_modif_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char cin[500];int x;
utilisateur u;
GtkWidget *hb_modifier,*hb_spin1,*hb_spin2,*hb_spin3,*hb_spin4,*output35,*output36,*output50;
GtkWidget *output31,*output32,*output33,*pInfo;

hb_modifier=lookup_widget(objet_graphique,"hb_modifier");
output31=lookup_widget(objet_graphique,"hb_entry100");
output32=lookup_widget(objet_graphique,"hb_entry8");
output33=lookup_widget(objet_graphique,"hb_entry9");
output35=lookup_widget(objet_graphique,"hb_entry23");
output36=lookup_widget(objet_graphique,"hb_entry24");
hb_spin1=lookup_widget(objet_graphique,"hb_spinbutton1");
hb_spin2=lookup_widget(objet_graphique,"hb_spinbutton2");
hb_spin3=lookup_widget(objet_graphique,"hb_spinbutton3");
hb_spin4=lookup_widget(objet_graphique,"hb_spinbutton4");
output50=lookup_widget(objet_graphique,"hb_label39_error");




strcpy(u.cin,gtk_entry_get_text(GTK_ENTRY(output31)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(output32)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(output33)));
strcpy(u.sexe,gtk_entry_get_text(GTK_ENTRY(output35)));
strcpy(u.role,gtk_entry_get_text(GTK_ENTRY(output36)));
u.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hb_spin1));
u.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hb_spin2));
u.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hb_spin3));
u.niveau=0;
if (strcmp(u.role,"etudiant")==0)
u.niveau=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hb_spin4));

if ( ( (strcmp(u.role,"etudiant")==0) || (strcmp(u.role,"nutritioniste")==0) || (strcmp(u.role,"technicien")==0) || (strcmp(u.role,"agentf")==0) || (strcmp(u.role,"agentr")==0)) && ( (strcmp(u.sexe,"Homme")==0)|| (strcmp(u.sexe,"Femme")==0  ) ))
{
modifier(u);
 	gtk_label_set_text(GTK_LABEL(output50),"success");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"modification  avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;} 
hb_modifier=lookup_widget(objet_graphique,"hb_modifier");
gtk_widget_destroy(hb_modifier);
hb_modifier=create_hb_modifier();
gtk_widget_show(hb_modifier);

 }


else { 	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"modification est echoué , verifier les coordonnés saisie");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break; }}
}


void
on_hb_button23_chercherbutton_clicked  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget
*cin,*output1,*hb_chercher_un_utilisateur,*output2,*output3,*output4,*output5,*output6,*output7;
int x;char texte5[500];char texte6[500];
utilisateur m;
output1=lookup_widget(objet_graphique,"hb_label118_cin");
output2=lookup_widget(objet_graphique,"hb_label121");
output3=lookup_widget(objet_graphique,"hb_label122");
output4=lookup_widget(objet_graphique,"hb_label123");
output5=lookup_widget(objet_graphique,"hb_label124");
output6=lookup_widget(objet_graphique,"hb_label125");
output7=lookup_widget(objet_graphique,"hb_label126");
cin=lookup_widget(objet_graphique,"hb_entry9");
cin=gtk_entry_get_text(GTK_ENTRY(cin));
x=chercher(cin);
	if (x==1)
{gtk_label_set_text(GTK_LABEL(output7),"utilisateur trouvé");
m=find(cin);
x=chercher(cin);

gtk_label_set_text(GTK_LABEL(output1),m.nom);
gtk_label_set_text(GTK_LABEL(output2),m.prenom);
gtk_label_set_text(GTK_LABEL(output3),m.sexe);
sprintf(texte5,"%d/%d/%d",m.d.jour,m.d.mois,m.d.annee);
gtk_label_set_text(GTK_LABEL(output4),texte5);
sprintf(texte6,"%d",m.niveau);
gtk_label_set_text(GTK_LABEL(output5),m.role);
gtk_label_set_text(GTK_LABEL(output6),texte6);}
else
gtk_label_set_text(GTK_LABEL(output7),"utilisateur non trouvé");

}


void
on_hb_button220_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_chercher_un_utilisateur,*treeview;
hb_chercher_un_utilisateur=lookup_widget(objet_graphique,"hb_chercher_un_utilisateur");
gtk_widget_destroy(hb_chercher_un_utilisateur);
hb_chercher_un_utilisateur=create_hb_chercher_un_utilisateur();
gtk_widget_show(hb_chercher_un_utilisateur);
treeview=lookup_widget(hb_chercher_un_utilisateur,"hb_treeview3");

afficher(treeview);
}


void
on_hb__button21_clicked                (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_chercher_un_utilisateur,*hb_gestion;
GtkWidget *treeview1;
hb_chercher_un_utilisateur=lookup_widget(objet_graphique,"hb_chercher_un_utilisateur");
treeview1=lookup_widget(hb_chercher_un_utilisateur,"hb_treeview3");

create(et,tc,nu,af,ar);
if ((et==0)&& (nu==0) &&(af==0) &&(ar==0) &&(tc==0) )
afficher(treeview1);
else
afficher2(treeview1);
}


void
on_hb_button71_clicked                 (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
int kaa;char texte[500];char texte2[500];char texte3[500];
GtkCalendar *ajc,*output999;
int mois, jour , annee;
guint* day, month, year;
ajc=lookup_widget(objet_graphique,"hb_calendar2");
output999=lookup_widget(objet_graphique,"hb_label1200");
gtk_calendar_get_date(GTK_CALENDAR(ajc), &day, &month, &year);
jour=year;
mois=month+1;
annee=day;

kaa=nbrdate(jour,mois,annee);
sprintf(texte,"le nombre des etudiants qui \n ont ce date de naissance %d/%d/%d sont :\n %d",jour,mois,annee,kaa);
//strcpy(texte3,nbrdatee(jour,mois,annee));
//strcpy(texte2,texte3);
gtk_label_set_text(GTK_LABEL(output999),texte);
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
int jour;

int mois;
int annee;
gchar* role;
gchar* cin;
int niveau;
gchar* sexe;
utilisateur u;
GtkTreeModel *model =gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &cin,1, &nom,2,&prenom,3,&jour,4,&mois,5,&annee,6,&role,7,&sexe,8,&niveau,-1);

strcpy(u.cin,cin);
strcpy(u.nom,nom);
strcpy(u.prenom,prenom);

u.d.jour=jour;
u.d.mois=mois;
u.d.annee=annee;
strcpy(u.role,role);
strcpy(u.sexe,sexe);
u.niveau=niveau;
//supprimer(u);




afficher2(treeview);

}
}


void
on_hb_checkbutton40hb_checkbutton10_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{et=1;}
else {et=0;}
}


void
on_hb_checkbutton20_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{nu=1;}
else {nu=0;}
}


void
on_hb_checkbutton30_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{af=1;}
else {af=0;}
}


void
on_hb_checkbutton40_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{ar=1;}
else {ar=0;}
}


void
on_hb_checkbutton50_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
{tc=1;}
else {tc=0;}
}


void
on_hb_button23_chercheeeee_clicked     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_chercher_un_utilisateur,*hb_gestion,*treeview;
hb_gestion=lookup_widget(objet_graphique,"hb_gestion");
gtk_widget_destroy(hb_gestion);
hb_chercher_un_utilisateur=create_hb_chercher_un_utilisateur();
gtk_widget_show(hb_chercher_un_utilisateur);
treeview=lookup_widget(hb_chercher_un_utilisateur,"hb_treeview3");

afficher(treeview);
}


void
on_hb_button25_accueil_espace_admin_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_espace_admin,*hb_gestion;
hb_gestion=lookup_widget(objet_graphique,"hb_gestion");
gtk_widget_destroy(hb_gestion);
hb_espace_admin=create_hb_espace_admin();
gtk_widget_show(hb_espace_admin);
}


void
on_hb_button26_mod_espace_clicked      (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_modifier,*hb_espace_admin;
hb_modifier=lookup_widget(objet_graphique,"hb_modifier");
gtk_widget_destroy(hb_modifier);
hb_espace_admin=create_hb_espace_admin();
gtk_widget_show(hb_espace_admin);
}


void
on_hb_button3_mod_clicked              (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_modifier,*hb_gestion;
hb_gestion=lookup_widget(objet_graphique,"hb_gestion");
gtk_widget_destroy(hb_gestion);
hb_modifier=create_hb_modifier();
gtk_widget_show(hb_modifier);
}


void
on_hb_button24_retour_espace_admin_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_gestion,*hb_chercher_un_utilisateur,*treeview;
hb_chercher_un_utilisateur=lookup_widget(objet_graphique,"hb_chercher_un_utilisateur");
gtk_widget_destroy(hb_chercher_un_utilisateur);
hb_gestion=create_hb_gestion();
gtk_widget_show(hb_gestion);
treeview=lookup_widget(hb_gestion,"hb_treeview2");

afficher(treeview);
}


void
on_hb_button24_calcul_clicked          (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output11,*hb_dashboard;
GtkWidget *hbniveau;
int nbre;char texte[500];int niv;
hb_dashboard=lookup_widget(objet_graphique,"hb_dashboard");
output11=lookup_widget(objet_graphique,"hb_label_calcul");
hbniveau=lookup_widget(objet_graphique,"hb_spinbutton11");
niv=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(hbniveau));
nbre=nbretude(niv);
sprintf(texte,"le nombre de etudiants de niveau %d est :%d",niv,nbre);
gtk_label_set_text(GTK_LABEL(output11),texte);
}


void
on_hb_checkbutton2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{tub[0]=1;}
else {tub[0]=0;}
}


void
on_hb_checkbutton3_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{tub[1]=1;}
else {tub[1]=0;}
}


void
on_hb_checkbutton1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{tub[2]=1;}
else {tub[2]=0;}
}


void
on_hb_checkbutton5_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{tub[3]=1;}
else {tub[3]=0;}
}


void
on_hb_checkbutton6_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{tub[4]=1;}
else { tub[4]=0;}
}


void
on_hb_button23_totale_clicked          (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output80,*hb_dashboard;
char texte[500];
int nbr1,nbr2,nbr3,nbr4,nbr5,totale;

hb_dashboard=lookup_widget(objet_graphique,"hb_dashboard");

output80=lookup_widget(objet_graphique,"hb_label43_tot");
nbr1=0;nbr2=0;nbr3=0;nbr4=0;nbr5=0;
if (tub[0]==1)
	{nbr1=nbretude(1);}
if (tub[1]==1)
	{nbr2=nbretude(2);}

if (tub[2]==1)
	{nbr3=nbretude(3);}

if (tub[3]==1)
	{nbr4=nbretude(4);}

if (tub[4]==1)
	{nbr5=nbretude(5);}

totale=nbr1+nbr2+nbr3+nbr4+nbr5;


sprintf(texte,"le nombre de etudiants de niveau est :%d",totale);
gtk_label_set_text(GTK_LABEL(output80),texte);
}


void
on_hb_accueil_principale_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_first_window,*hb_dashboard;
hb_dashboard=lookup_widget(objet_graphique,"hb_dashboard");
gtk_widget_destroy(hb_dashboard);
hb_first_window=create_hb_first_window();
gtk_widget_show(hb_first_window);
}


void
on_hb_1_button31_clicked               (GtkWidget    *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_first_window,*hb_dashboard;
hb_first_window=lookup_widget(objet_graphique,"hb_first_window");
gtk_widget_destroy(hb_first_window);
hb_dashboard=create_hb_dashboard();
gtk_widget_show(hb_dashboard);
}


void
on_hb_afficher__admin_clicked          (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_espace_admin,*hb_gestion;
GtkWidget *treeview;
hb_espace_admin=lookup_widget(objet_graphique,"hb_espace_admin");
gtk_widget_destroy(hb_espace_admin);
hb_gestion=create_hb_gestion();

gtk_widget_show(hb_gestion);
treeview=lookup_widget(hb_gestion,"hb_treeview2");

afficher(treeview);
}
/////////////////////////////////////////////////////////////////////////////////ghassen//////////////////////////////

int y=1;
int yu[]={0,0,0,0,0};
void
on_checkbutton3_aj_gm_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{ yu[2]=1;}

}


void
on_checkbutton4_aj_gm_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{ yu[3]=1;}


}


void
on_checkbutton5_aj_gm_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{ yu[4]=1;}


}


void
on_checkbutton1_aj_gm_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{ yu[0]=1;}


}


void
on_checkbutton2_aj_gm_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{ yu[1]=1;}


}


void
on_button7_aj_gm_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* id;
GtkWidget* nom;
GtkWidget* prenom;
GtkWidget* reclamation;
GtkWidget* output;
GtkWidget* jour;
GtkWidget* mois;
GtkWidget* annee;
GtkWidget* heure;
char id1 [100];
char n[100];
char pre[100];
char rec[1000];
char hr[100];
date25 d ;
int i;
char msg[100]="";
char texte[100]="";
recl r;
char ch[100];
id = lookup_widget(button,"entry4_aj_gm");
nom = lookup_widget(button,"entry3_aj_gm");
prenom = lookup_widget(button,"entry5_aj_gm");
reclamation = lookup_widget(button,"entry7_aj_gm");
jour = lookup_widget(button,"spinbutton7_j_aj_gm");
mois = lookup_widget(button,"spinbutton8_mo_aj_gm");
annee = lookup_widget(button,"spinbutton9_an_aj_gm");
heure = lookup_widget(button,"combobox2_dt_aj_gm");
d.j =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
d.m =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
d.a =gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(n, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(pre, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(rec, gtk_entry_get_text(GTK_ENTRY(reclamation)));
strcpy(hr,gtk_combo_box_get_active_text(GTK_COMBO_BOX(heure)));
strcpy(r.id,id1);
strcpy(r.nom,n);
strcpy(r.prenom,pre);
strcpy(r.reclamation,rec);
r.d.j=d.j;
r.d.m=d.m;
r.d.a=d.a;
strcpy(r.d.h,hr);
radio(x,msg);
strcpy(r.type,msg);
autres(yu,texte,x);
strcpy(r.choix,texte);
i = rech5(id1);
if (i == 1)
{
output= lookup_widget (button, "gm_labelajo");
strcpy(ch," l'identifiant est déja utilisé  ");
gtk_label_set_text(GTK_LABEL(output),ch);
}
else 
{
output= lookup_widget (button, "gm_labelajo");
strcpy(ch,"ajout effectuée avec succees");
gtk_label_set_text(GTK_LABEL(output),ch);
ajouter_reclamation(r);
}



}


void
on_button8_ann_gm_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowsacceuil;
GtkWidget *windowsaj_destroy;

windowsaj_destroy = lookup_widget ( button, "window2_aj_gm");
gtk_widget_destroy(windowsaj_destroy);
windowsacceuil = lookup_widget ( button, "window1_acc_gm");

windowsacceuil=create_window1_acc_gm();
gtk_widget_show (windowsacceuil);


}


void
on_radiobutton1_aj_gm_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	y=1;


}


void
on_radiobutton2_aj_gm_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	y=2;

}


void
on_button9_rech_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id ;
GtkWidget *output ;
char id1[100];
int c ;
char ch [100];
id= lookup_widget (button, "entry8_rech_gm");
strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
c = rech5 (id1);
if (c == 1) 
{
output= lookup_widget (button, "label2_recherche_gm");
strcpy(ch,"la Reclamation existe ");
gtk_label_set_text(GTK_LABEL(output),ch);
}
else 
{
output= lookup_widget (button, "label2_recherche_gm");
strcpy(ch," la Reclamation n'existe pas ");
gtk_label_set_text(GTK_LABEL(output),ch);
}

}


void
on_rechgotoacc_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1_acc_gm;
GtkWidget *window3_rech_gm;

window3_rech_gm = lookup_widget (button, "window3_rech_gm");

gtk_widget_destroy(window3_rech_gm);
window1_acc_gm = lookup_widget (button, "window1_acc_gm");
window1_acc_gm = create_window1_acc_gm();

gtk_widget_show(window1_acc_gm);


}


void
on_suppgotoac_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1_acc_gm;
GtkWidget *window5_supp_gm;

window5_supp_gm = lookup_widget (button, "window5_supp_gm");

gtk_widget_destroy(window5_supp_gm);
window1_acc_gm = lookup_widget (button, "window1_acc_gm");
window1_acc_gm = create_window1_acc_gm();

gtk_widget_show(window1_acc_gm);


}


void
on_button11_supprimer_gm_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *id ;
GtkWidget *output ;
char id1[100];
int c ;
char ch [100];
id= lookup_widget (button, "entry13_id_sup_gm");
strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
c = rech5 (id1);
if (c == 1) 
{
output= lookup_widget (button, "label1_supprimer_gm");
strcpy(ch,"suppression effectuée avec succees");
gtk_label_set_text(GTK_LABEL(output),ch);
supprimer_reclamation(id1);
}
else 
{
output= lookup_widget (button, "label1_supprimer_gm");
strcpy(ch," l'identifiant n'existe pas ");
gtk_label_set_text(GTK_LABEL(output),ch);
}

}


void
on_reclameplus_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
char texte [100];
sercive(texte);
output= lookup_widget (button, "label21_service_gm");
gtk_label_set_text(GTK_LABEL(output),texte);

}


void
on_reclgotoacc_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1_acc_gm;
GtkWidget *window7_ser_recl;

window7_ser_recl = lookup_widget (button, "window7_ser_recl");

gtk_widget_destroy(window7_ser_recl);
window1_acc_gm = lookup_widget (button, "window1_acc_gm");
window1_acc_gm = create_window1_acc_gm();

gtk_widget_show(window1_acc_gm);



}


void
on_button1returntoac_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1_acc_gm;
GtkWidget *window6_aff_gm;

window6_aff_gm = lookup_widget (button, "window6_aff_gm");

gtk_widget_destroy(window6_aff_gm);
window1_acc_gm = lookup_widget (button, "window1_acc_gm");
window1_acc_gm = create_window1_acc_gm();

gtk_widget_show(window1_acc_gm);


}


void
on_buttonmod_ok_gm_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idnv ;
GtkWidget *idold ;
GtkWidget *output ;
GtkWidget *fenetre_modifier;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *heure;
GtkWidget *choix;
GtkWidget *type;
GtkWidget *reclamation;
char id1[100];
int c ;
recl a;
char ch[100]="";


fenetre_modifier = lookup_widget (button, "window4_mod_gm");
idold = lookup_widget (button, "entrynouvid");
idnv = lookup_widget (button, "entry9_id_gm");
nom = lookup_widget (button, "entry10_nom_gm");
prenom= lookup_widget (button, "entry11_pre_gm");
type = lookup_widget (button, "entry8_gm_type");
choix = lookup_widget (button, "entry9_gm_choix");
jour = lookup_widget (button, "spinbutton1_mod_gm");
mois = lookup_widget (button, "spinbutton2_mod_gm");
annee = lookup_widget (button, "spinbutton3_mod_gm");
heure = lookup_widget (button, "entry10_gm_heure");
reclamation = lookup_widget (button, "entry12_txt_gm");
strcpy(id1, gtk_entry_get_text(GTK_ENTRY(idold)));
c = rech5(id1);
if (c == 1)
{
a = find5(id1);
output = lookup_widget (button, "label9_verifermod");
strcpy(ch," l'identifiant existe ");
gtk_label_set_text(GTK_LABEL(output),ch);
gtk_entry_set_text(GTK_ENTRY(idnv),a.id);
gtk_entry_set_text(GTK_ENTRY(nom),a.nom);
gtk_entry_set_text(GTK_ENTRY(prenom),a.prenom);
gtk_entry_set_text(GTK_ENTRY(type),a.type);
gtk_entry_set_text(GTK_ENTRY(choix),a.choix);
gtk_entry_set_text(GTK_ENTRY(heure),a.d.h);
gtk_entry_set_text(GTK_ENTRY(reclamation),a.reclamation);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),a.d.j);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),a.d.m);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),a.d.a);
}
else
{
output= lookup_widget (button, "label9_verifermod");
strcpy(ch," l'identifiant n'existe pas  ");
gtk_label_set_text(GTK_LABEL(output),ch);
}

}


void
on_modgotoacc_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1_acc_gm;
GtkWidget *window4_mod_gm;

window4_mod_gm = lookup_widget (button, "window4_mod_gm");

gtk_widget_destroy(window4_mod_gm);
window1_acc_gm = lookup_widget (button, "window1_acc_gm");
window1_acc_gm = create_window1_acc_gm();

gtk_widget_show(window1_acc_gm);

}


void
on_button10_modif_gm_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *idnv ;
GtkWidget *idold ;
GtkWidget *output ;
GtkWidget *fenetre_modifier;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *heure;
GtkWidget *choix;
GtkWidget *type;
GtkWidget *reclamation;
char idnv1[100];
char idold1[100];
int c ;
recl r;
char ch[100]="";
date25 d;
char type1[100];
char nom1[100];
char prenom1[100];
char reclamation1[100];
char choix1[100];
char heure1[100];

fenetre_modifier = lookup_widget (button, "window4_mod_gm");
idold = lookup_widget (button, "entrynouvid");
idnv = lookup_widget (button, "entry9_id_gm");
nom = lookup_widget (button, "entry10_nom_gm");
prenom= lookup_widget (button, "entry11_pre_gm");
type = lookup_widget (button, "entry8_gm_type");
choix = lookup_widget (button, "entry9_gm_choix");
jour = lookup_widget (button, "spinbutton1_mod_gm");
mois = lookup_widget (button, "spinbutton2_mod_gm");
annee = lookup_widget (button, "spinbutton3_mod_gm");
heure = lookup_widget (button, "entry10_gm_heure");
reclamation = lookup_widget (button, "entry12_txt_gm");
d.j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(jour));
d.m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mois));
d.a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(annee));
strcpy(nom1, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(prenom1, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(choix1, gtk_entry_get_text(GTK_ENTRY(choix)));
strcpy(heure1, gtk_entry_get_text(GTK_ENTRY(heure)));
strcpy(type1, gtk_entry_get_text(GTK_ENTRY(type)));
strcpy(reclamation1, gtk_entry_get_text(GTK_ENTRY(reclamation)));
strcpy(idnv1, gtk_entry_get_text(GTK_ENTRY(idnv)));
strcpy(idold1, gtk_entry_get_text(GTK_ENTRY(idold)));
r.d.j=d.j;
r.d.m=d.m;
r.d.a=d.a;
strcpy(r.id,idnv1);
strcpy(r.d.h,heure1);
strcpy(r.type,type1);
strcpy(r.choix,choix1);
strcpy(r.reclamation,reclamation1);
strcpy(r.nom,nom1);
strcpy(r.prenom,prenom1);
if  (   (     (	     ( strcmp (r.type,"Restauration") == 0 ) &&((strcmp (r.choix,"plats'ou'desserts") == 0 ) || (strcmp (r.choix,"autres") == 0 ))) || (( strcmp (r.type,"Hebergement") == 0 ) &&((strcmp (r.choix,"binome'ou'voisins") == 0 ) || (strcmp (r.choix,"equippements'ou'meubles") == 0 )|| (strcmp (r.choix,"autres")==0)))) && (strcmp (r.d.h,"8h==>12h15") == 0 )||(strcmp (r.d.h,"12h15==>14h") == 0 )||(strcmp (r.d.h,"14h==>17h") == 0 )||(strcmp (r.d.h,"17h==>00h") == 0 )||(strcmp (r.d.h,"00h==>8h") == 0 ))
{
output= lookup_widget (button, "label10_modafficher");
strcpy(ch,"modfication effectuée avec succees");
gtk_label_set_text(GTK_LABEL(output),ch);
modifier_reclamation(r,idold1);
}
else
{
output= lookup_widget (button, "label10_modafficher");
strcpy(ch,"verifer le type et le choix et le heure  ");
gtk_label_set_text(GTK_LABEL(output),ch);
}

}


void
on_button6_ser_recl_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1_acc_gm;
GtkWidget *window7_ser_recl;

window1_acc_gm = lookup_widget (button, "window1_acc_gm");

gtk_widget_destroy(window1_acc_gm);
window7_ser_recl = lookup_widget (button, "window7_ser_recl");
window7_ser_recl = create_window7_ser_recl();

gtk_widget_show(window7_ser_recl);

}


void
on_button5_aff_gm_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1_acc_gm;
GtkWidget *window6_aff_gm;
GtkWidget *treeview1;

window1_acc_gm=lookup_widget(button,"window1_acc_gm");

gtk_widget_destroy(window1_acc_gm);
window6_aff_gm=lookup_widget(button,"window6_aff_gm");
window6_aff_gm=create_window6_aff_gm();

gtk_widget_show(window6_aff_gm);

treeview1=lookup_widget(window6_aff_gm,"treeview1_gm");
afficher5(treeview1);


}


void
on_button3_mod_gm_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1_acc_gm;
GtkWidget *window4_mod_gm;

window1_acc_gm = lookup_widget (button, "window1_acc_gm");

gtk_widget_destroy(window1_acc_gm);
window4_mod_gm = lookup_widget (button, "window4_mod_gm");
window4_mod_gm = create_window4_mod_gm();

gtk_widget_show(window4_mod_gm);


}


void
on_button4_supp_gm_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1_acc_gm;
GtkWidget *window5_supp_gm;

window1_acc_gm = lookup_widget (button, "window1_acc_gm");

gtk_widget_destroy(window1_acc_gm);
window5_supp_gm = lookup_widget (button, "window5_supp_gm");
window5_supp_gm = create_window5_supp_gm();

gtk_widget_show(window5_supp_gm);

}


void
on_button2_rech_gm_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1_acc_gm;
GtkWidget *window3_rech_gm;

window1_acc_gm = lookup_widget (button, "window1_acc_gm");

gtk_widget_destroy(window1_acc_gm);
window3_rech_gm = lookup_widget (button, "window3_rech_gm");
window3_rech_gm = create_window3_rech_gm();

gtk_widget_show(window3_rech_gm);

}


void
on_button1_aj_gm_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1_acc_gm;
GtkWidget *window2_aj_gm;

window1_acc_gm = lookup_widget (button, "window1_acc_gm");

gtk_widget_destroy(window1_acc_gm);
window2_aj_gm = lookup_widget (button, "window2_aj_gm");
window2_aj_gm = create_window2_aj_gm();

gtk_widget_show(window2_aj_gm);


}


void
on_treeview1_gm_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter ;
gchar* id;
gchar* nom;
gchar* prenom ;
gchar* reclamation ;
gchar* type;
gchar* choix;
int jour ;
int mois ;
int annee ;
gchar* heure;
recl r;

GtkTreeModel *model =gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path))
	{
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&prenom,3,&reclamation,4,&type,5,&choix,6,&jour,7,&mois,8,&annee,9,&heure,-1);
		strcpy(r.id,id);
		strcpy(r.nom,nom);
		strcpy(r.prenom,prenom);
		strcpy(r.reclamation,reclamation);
		strcpy(r.type,type);
		strcpy(r.choix,choix);
		r.d.j=jour;
		r.d.m=mois;
		r.d.a=annee;
		strcpy(r.d.h,heure);
		supprimer25(r);		
		afficher5(treeview);
	}

}

//////////////////////////chehine///////////////////////////////////////////////////////////

int xdh;


void
on_aj6_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
xdh=3;
}


void
on_aj5_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
xdh=2;
}


void
on_aj4_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
xdh=1;
}



void
on_chehinebutton1_clicked              (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *aj, *dashboard;
dashboard=lookup_widget(objet_graphique,"dashboard");
aj=lookup_widget(objet_graphique,"aj");
aj=create_aj();
gtk_widget_show(aj);
}


void
on_chehinebutton2_clicked              (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *mod, *dashboard;
dashboard=lookup_widget(objet_graphique,"dashboard");
mod=lookup_widget(objet_graphique,"mod");
mod=create_mod();
gtk_widget_show(mod);
}

void
on_chehinebutton3_clicked              (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *chehinetreeview, *af;
af=lookup_widget(objet_graphique,"af");
af=create_af();
gtk_widget_show(af);
chehinetreeview=lookup_widget(af,"chehinetreeview");
afficher_capt(chehinetreeview);
}


void
on_chehinebutton4_clicked              (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *cherch, *dashboard;
dashboard=lookup_widget(objet_graphique,"dashboard");
cherch=lookup_widget(objet_graphique,"cherch");
cherch=create_cherch();
gtk_widget_show(cherch);

}

void
on_chehinebutton_aj_clicked           (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *aj1, *aj2, *aj3, *aj4, *aj5, *aj6, *aj7, *aj8, *aj9;
capteur55 u;
aj1=lookup_widget(objet_graphique,"aj1");
aj2=lookup_widget(objet_graphique,"aj2");
aj3=lookup_widget(objet_graphique,"aj3");
aj4=lookup_widget(objet_graphique,"aj4");
aj5=lookup_widget(objet_graphique,"aj5");
aj6=lookup_widget(objet_graphique,"aj6");
aj7=lookup_widget(objet_graphique,"aj7");
aj8=lookup_widget(objet_graphique,"aj8");
aj9=lookup_widget(objet_graphique,"aj9");


strcpy(u.id55,gtk_entry_get_text(GTK_ENTRY(aj1)));
u.type55=gtk_combo_box_get_active(GTK_COMBO_BOX(aj2));
//u.type55=1;
strcpy(u.marque55,gtk_entry_get_text(GTK_ENTRY(aj3)));

if (xdh==1) 
{strcpy(u.garantie55,"1an");}
if (xdh==2)
{strcpy(u.garantie55,"2ans");}
if (xdh==3)
{strcpy(u.garantie55,"3ans");}

u.d55.j55=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(aj7));
u.d55.m55=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(aj8));
u.d55.a55=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(aj9));

ajouter_captt(u);
}


void
on_chehinebutton_mod_clicked           (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4, *mod6, *mod7, *mod8, *mod9, *pInfo;
capteur55 u;
mod1=lookup_widget(objet_graphique,"mod1");
mod2=lookup_widget(objet_graphique,"mod2");
mod3=lookup_widget(objet_graphique,"mod3");
mod4=lookup_widget(objet_graphique,"mod4");
mod7=lookup_widget(objet_graphique,"mod7");
mod8=lookup_widget(objet_graphique,"mod8");
mod9=lookup_widget(objet_graphique,"mod9");
strcpy(u.id55,gtk_entry_get_text(GTK_ENTRY(mod1)));
u.type55=gtk_combo_box_get_active(GTK_COMBO_BOX(mod2));
//u.type55=1;
strcpy(u.marque55,gtk_entry_get_text(GTK_ENTRY(mod3)));
strcpy(u.garantie55,gtk_entry_get_text(GTK_ENTRY(mod4)));
u.d55.j55=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mod7));
u.d55.m55=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mod8));
u.d55.a55=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(mod9));



modifier_capt(u);
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Capteur modifié avec succès");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}


}


void
on_chehinecheck_id_clicked             (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *mod1, *mod2, *mod3, *mod4,  *mod7, *mod8, *mod9, *pInfo;
capteur55 l;
int aaa=0;
char id55[50];

mod1=lookup_widget(objet_graphique,"mod1");
mod2=lookup_widget(objet_graphique,"mod2");
mod3=lookup_widget(objet_graphique,"mod3");
mod4=lookup_widget(objet_graphique,"mod4");
mod7=lookup_widget(objet_graphique,"mod7");
mod8=lookup_widget(objet_graphique,"mod8");
mod9=lookup_widget(objet_graphique,"mod9");
strcpy(id55,gtk_entry_get_text(GTK_ENTRY(mod1)));
aaa=chercher_capt(id55);
if(aaa==1)
{
l = find_capt(id55);
gtk_combo_box_set_active(GTK_COMBO_BOX(mod2),l.type55);
gtk_entry_set_text(GTK_ENTRY(mod3),l.marque55);
gtk_entry_set_text(GTK_ENTRY(mod4),l.garantie55);

gtk_spin_button_set_value(GTK_SPIN_BUTTON(mod7),l.d55.j55);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mod8),l.d55.m55);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mod9),l.d55.a55);

}
else{
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Capteur introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}
}

void
on_chehinebutton_cherch_clicked         (GtkWidget        *objet_graphique,
                                        gpointer         user_data)


{
GtkWidget *cherch1,*output200,*output666;
int ccc;

char id55[20];
char ch55[50];
capteur55 u;
cherch1=lookup_widget(objet_graphique,"cherch1");
strcpy(id55,gtk_entry_get_text(GTK_ENTRY(cherch1)));
output200= lookup_widget (objet_graphique, "chehinelabel111");
output666= lookup_widget (objet_graphique, "chehinelabel55");


ccc=chercher_capt(id55);
if (ccc==1)
{
u=find_capt(id55);
gtk_label_set_text(GTK_LABEL(output666),u.garantie55);


strcpy(ch55," capteur existe ");
gtk_label_set_text(GTK_LABEL(output200),ch55);
}
else
{
strcpy(ch55," capteur n'existe pas ");
gtk_label_set_text(GTK_LABEL(output200 ),ch55);
}
}


void
on_chehinebutton_af_clicked            (GtkWidget    *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *chehinetreeview, *af;
af=lookup_widget(objet_graphique,"af");
gtk_widget_destroy(af);
af=lookup_widget(objet_graphique,"af");
af=create_af();
gtk_widget_show(af);
chehinetreeview=lookup_widget(af,"chehinetreeview");
afficher_capt(chehinetreeview);
}

void
on_chehinetreeview_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)

{
	GtkTreeIter iter;
	gchar *id55;
	capteur55 u;
	GtkWidget *pInfo;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path))
{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id55,-1);
	strcpy(u.id55,id55);
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer ce capteur?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	gtk_widget_destroy(pInfo);
	supprimer_capt(u);
	afficher_capt(treeview);
	break;
	case GTK_RESPONSE_NO:
	gtk_widget_destroy(pInfo);
	break;
}	
}
}

///////////////////////////////hb_login/////////////////////////








void
on_hb_1_button30_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_login,*hb_first_window;
hb_first_window=lookup_widget(objet_graphique,"hb_first_window");
gtk_widget_destroy(hb_first_window);
hb_login=create_hb_login();
gtk_widget_show(hb_login);
}


void
on_hb_button22_connecter_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char util[50];
char pass[50];
int test21;
GtkWidget *input1,*input2,*hb_menu_employe,*output,*hb_login,*pInfo,*treeview1_cm;
GtkWidget *hb_espace_admin,*dashboard,*Foyer_ESPRIT,*window1_acc_gm,*gestiondesmenusdelasemaine,*affichage_produit,*hb_first_window;

input1=lookup_widget(objet_graphique,"hb_entry75");
input2=lookup_widget(objet_graphique,"hb_entry69");
hb_login=lookup_widget(objet_graphique,"hb_login");


strcpy(util,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(pass,gtk_entry_get_text(GTK_ENTRY(input2)));
test21=chercherr211(util,pass);
if (test21==1)
	{hb_login=lookup_widget(objet_graphique,"hb_login");
	gtk_widget_destroy(hb_login);
	hb_espace_admin=create_hb_espace_admin();
	gtk_widget_show(hb_espace_admin);}
if (test21==2)
	{hb_login=lookup_widget(objet_graphique,"hb_login");
	gtk_widget_destroy(hb_login);
	dashboard=create_dashboard();
	gtk_widget_show(dashboard);}
if(test21==3)
	{hb_login=lookup_widget(objet_graphique,"hb_login");
	gtk_widget_destroy(hb_login);	
	Foyer_ESPRIT=create_Foyer_ESPRIT();
	gtk_widget_show(Foyer_ESPRIT);}
if (test21==6)
	{hb_login=lookup_widget(objet_graphique,"hb_login");
	gtk_widget_destroy(hb_login);
	window1_acc_gm=create_window1_acc_gm();
	gtk_widget_show(window1_acc_gm);}
if (test21==5)
	{hb_login=lookup_widget(objet_graphique,"hb_login");
	gtk_widget_destroy(hb_login);
	gestiondesmenusdelasemaine=create_gestiondesmenusdelasemaine();
	gtk_widget_show(gestiondesmenusdelasemaine);
	treeview1_cm=lookup_widget(gestiondesmenusdelasemaine,"treeviewmenu");

	afficher_menu(treeview1_cm);
}
if (test21==4)
	{hb_login=lookup_widget(objet_graphique,"hb_login");
	gtk_widget_destroy(hb_login);
	affichage_produit=create_affichage_produit();
	gtk_widget_show(affichage_produit);}


if (test21==0)
 {
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"nom de utilisateur ou mot de passe incorrect");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;} }

}


void
on_hb_button_chaima_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestiondesmenusdelasemaine,*hb_login;
gestiondesmenusdelasemaine=lookup_widget(objet_graphique,"gestiondesmenusdelasemaine");
	gtk_widget_destroy(gestiondesmenusdelasemaine);
	hb_login=create_hb_login();
	gtk_widget_show(hb_login);
}


void
on_hb_button_aicha_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affichage_produit,*hb_login;
affichage_produit=lookup_widget(objet_graphique,"affichage_produit");
gtk_widget_destroy(affichage_produit);
	hb_login=create_hb_login();
	gtk_widget_show(hb_login);
}


void
on_hb_button_ahmed_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Foyer_ESPRIT,*hb_login;
Foyer_ESPRIT=lookup_widget(objet_graphique,"Foyer_ESPRIT");
gtk_widget_destroy(Foyer_ESPRIT);
	hb_login=create_hb_login();
	gtk_widget_show(hb_login);
}


void
on_hb_button_ghassen_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1_acc_gm,*hb_login;
window1_acc_gm=lookup_widget(objet_graphique,"window1_acc_gm");
gtk_widget_destroy(window1_acc_gm);
	hb_login=create_hb_login();
	gtk_widget_show(hb_login);
}


void
on_hb_button_chehine_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dashboard,*hb_login;
dashboard=lookup_widget(objet_graphique,"dashboard");
gtk_widget_destroy(dashboard);
	hb_login=create_hb_login();
	gtk_widget_show(hb_login);
}


void
on_hb_button_houssem_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_login,*hb_espace_admin;
hb_espace_admin=lookup_widget(objet_graphique,"hb_espace_admin");
gtk_widget_destroy(hb_espace_admin);
hb_login=create_hb_login();
gtk_widget_show(hb_login);
}


/*void
on_hb_button_retour_main_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_login,*hb_first_window;
hb_login=lookup_widget(objet_graphique,"hb_login");
gtk_widget_destroy(hb_login);
hb_first_window=create_hb_login();
gtk_widget_show(hb_first_window);
}*/


void
on_hb_button_retour_main2_clicked      (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_login,*hb_first_window;
hb_login=lookup_widget(objet_graphique,"hb_login");
gtk_widget_destroy(hb_login);
hb_first_window=create_hb_first_window();
gtk_widget_show(hb_first_window);
}


////////////dashboard ahmed/////////////////
int r;
void
on_adfumee_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{r=2;}
}


void
on_admouvement_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{r=1;}
}

void
on_adbutton88_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *hb_dashboard,*adtreeview2,*adtree,*treeview;

if (r==1)
{
hb_dashboard=lookup_widget(objet_graphique,"create_adtree");
adtree=create_adtree();
gtk_widget_show(adtree);

treeview=lookup_widget(adtree,"adtreeview2");
advider(treeview,"mouvement.txt");
adalarme(treeview,"mouvement.txt");
}
if (r==2)
{
hb_dashboard=lookup_widget(objet_graphique,"create_adtree");
adtree=create_adtree();
gtk_widget_show(adtree);
treeview=lookup_widget(adtree,"adtreeview2");
advider1(treeview,"fumee.txt");
adalarme1(treeview,"fumee.txt");
}
}






void
on_adtreeview2_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar jour[20];
int heure;
gchar num[20];
gchar valeur[20];
alarme p;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&jour,1,&heure,2,&num,3,&valeur,-1);
strcpy(p.jour,jour);
p.heure=heure;
strcpy(p.num,num);
strcpy(p.valeur,valeur);
if (r==1)
{
adalarme(treeview,"mouvement.txt");
}
else if (r==2)
{
adalarme1(treeview,"fumee.txt");
}
}
}

