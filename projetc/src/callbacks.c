#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "foyer.h"
#include <stdlib.h>
#include <stdio.h>

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

