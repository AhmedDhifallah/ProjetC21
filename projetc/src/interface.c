/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_Foyer_ESPRIT (void)
{
  GtkWidget *Foyer_ESPRIT;
  GtkWidget *fixed1;
  GtkWidget *ADlabel1;
  GtkWidget *adbutton2;
  GtkWidget *alignment10;
  GtkWidget *hbox10;
  GtkWidget *image10;
  GtkWidget *label26;
  GtkWidget *adbutton3;
  GtkWidget *alignment11;
  GtkWidget *hbox11;
  GtkWidget *image11;
  GtkWidget *label27;
  GtkWidget *adbutton1;
  GtkWidget *alignment12;
  GtkWidget *hbox12;
  GtkWidget *image12;
  GtkWidget *label28;
  GtkWidget *adbuttonaff;
  GtkWidget *alignment9;
  GtkWidget *hbox9;
  GtkWidget *image9;
  GtkWidget *label25;
  GtkWidget *adbuttonchercher;
  GtkWidget *alignment16;
  GtkWidget *hbox16;
  GtkWidget *image16;
  GtkWidget *label32;

  Foyer_ESPRIT = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Foyer_ESPRIT), _("Foyer ESPRIT"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (Foyer_ESPRIT), fixed1);

  ADlabel1 = gtk_label_new (_("Page Accueil"));
  gtk_widget_show (ADlabel1);
  gtk_fixed_put (GTK_FIXED (fixed1), ADlabel1, 112, 0);
  gtk_widget_set_size_request (ADlabel1, 152, 72);

  adbutton2 = gtk_button_new ();
  gtk_widget_show (adbutton2);
  gtk_fixed_put (GTK_FIXED (fixed1), adbutton2, 288, 168);
  gtk_widget_set_size_request (adbutton2, 96, 32);

  alignment10 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment10);
  gtk_container_add (GTK_CONTAINER (adbutton2), alignment10);

  hbox10 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox10);
  gtk_container_add (GTK_CONTAINER (alignment10), hbox10);

  image10 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image10);
  gtk_box_pack_start (GTK_BOX (hbox10), image10, FALSE, FALSE, 0);

  label26 = gtk_label_new_with_mnemonic (_("Supprimer"));
  gtk_widget_show (label26);
  gtk_box_pack_start (GTK_BOX (hbox10), label26, FALSE, FALSE, 0);

  adbutton3 = gtk_button_new ();
  gtk_widget_show (adbutton3);
  gtk_fixed_put (GTK_FIXED (fixed1), adbutton3, 144, 168);
  gtk_widget_set_size_request (adbutton3, 88, 32);

  alignment11 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment11);
  gtk_container_add (GTK_CONTAINER (adbutton3), alignment11);

  hbox11 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox11);
  gtk_container_add (GTK_CONTAINER (alignment11), hbox11);

  image11 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image11);
  gtk_box_pack_start (GTK_BOX (hbox11), image11, FALSE, FALSE, 0);

  label27 = gtk_label_new_with_mnemonic (_("Modifier"));
  gtk_widget_show (label27);
  gtk_box_pack_start (GTK_BOX (hbox11), label27, FALSE, FALSE, 0);

  adbutton1 = gtk_button_new ();
  gtk_widget_show (adbutton1);
  gtk_fixed_put (GTK_FIXED (fixed1), adbutton1, 0, 168);
  gtk_widget_set_size_request (adbutton1, 88, 32);

  alignment12 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment12);
  gtk_container_add (GTK_CONTAINER (adbutton1), alignment12);

  hbox12 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox12);
  gtk_container_add (GTK_CONTAINER (alignment12), hbox12);

  image12 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image12);
  gtk_box_pack_start (GTK_BOX (hbox12), image12, FALSE, FALSE, 0);

  label28 = gtk_label_new_with_mnemonic (_("Ajouter"));
  gtk_widget_show (label28);
  gtk_box_pack_start (GTK_BOX (hbox12), label28, FALSE, FALSE, 0);

  adbuttonaff = gtk_button_new ();
  gtk_widget_show (adbuttonaff);
  gtk_fixed_put (GTK_FIXED (fixed1), adbuttonaff, 64, 88);
  gtk_widget_set_size_request (adbuttonaff, 104, 32);

  alignment9 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment9);
  gtk_container_add (GTK_CONTAINER (adbuttonaff), alignment9);

  hbox9 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox9);
  gtk_container_add (GTK_CONTAINER (alignment9), hbox9);

  image9 = gtk_image_new_from_stock ("gtk-home", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image9);
  gtk_box_pack_start (GTK_BOX (hbox9), image9, FALSE, FALSE, 0);

  label25 = gtk_label_new_with_mnemonic (_("Afficher"));
  gtk_widget_show (label25);
  gtk_box_pack_start (GTK_BOX (hbox9), label25, FALSE, FALSE, 0);

  adbuttonchercher = gtk_button_new ();
  gtk_widget_show (adbuttonchercher);
  gtk_fixed_put (GTK_FIXED (fixed1), adbuttonchercher, 232, 88);
  gtk_widget_set_size_request (adbuttonchercher, 104, 29);

  alignment16 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment16);
  gtk_container_add (GTK_CONTAINER (adbuttonchercher), alignment16);

  hbox16 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox16);
  gtk_container_add (GTK_CONTAINER (alignment16), hbox16);

  image16 = gtk_image_new_from_stock ("gtk-find", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image16);
  gtk_box_pack_start (GTK_BOX (hbox16), image16, FALSE, FALSE, 0);

  label32 = gtk_label_new_with_mnemonic (_("Rechercher"));
  gtk_widget_show (label32);
  gtk_box_pack_start (GTK_BOX (hbox16), label32, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) adbutton2, "clicked",
                    G_CALLBACK (on_adbutton2_clicked),
                    NULL);
  g_signal_connect ((gpointer) adbutton3, "clicked",
                    G_CALLBACK (on_adbutton3_clicked),
                    NULL);
  g_signal_connect ((gpointer) adbutton1, "clicked",
                    G_CALLBACK (on_adbutton1_clicked),
                    NULL);
  g_signal_connect ((gpointer) adbuttonaff, "clicked",
                    G_CALLBACK (on_adbuttonaff_clicked),
                    NULL);
  g_signal_connect ((gpointer) adbuttonchercher, "clicked",
                    G_CALLBACK (on_adbuttonchercher_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Foyer_ESPRIT, Foyer_ESPRIT, "Foyer_ESPRIT");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, ADlabel1, "ADlabel1");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, adbutton2, "adbutton2");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, alignment10, "alignment10");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, hbox10, "hbox10");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, image10, "image10");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, label26, "label26");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, adbutton3, "adbutton3");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, alignment11, "alignment11");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, hbox11, "hbox11");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, image11, "image11");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, label27, "label27");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, adbutton1, "adbutton1");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, alignment12, "alignment12");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, hbox12, "hbox12");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, image12, "image12");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, label28, "label28");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, adbuttonaff, "adbuttonaff");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, alignment9, "alignment9");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, hbox9, "hbox9");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, image9, "image9");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, label25, "label25");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, adbuttonchercher, "adbuttonchercher");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, alignment16, "alignment16");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, hbox16, "hbox16");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, image16, "image16");
  GLADE_HOOKUP_OBJECT (Foyer_ESPRIT, label32, "label32");

  return Foyer_ESPRIT;
}

GtkWidget*
create_Ajouter_Foyer (void)
{
  GtkWidget *Ajouter_Foyer;
  GtkWidget *fixed2;
  GtkWidget *adentryNom1;
  GtkWidget *adentryPrenom1;
  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *adentryID1;
  GtkObject *adspinbutton1_adj;
  GtkWidget *adspinbutton1;
  GtkWidget *label3;
  GtkWidget *label4;
  GtkWidget *label5;
  GtkWidget *label6;
  GtkWidget *adcombobox1;
  GtkWidget *adradiobutton3;
  GSList *adradiobutton3_group = NULL;
  GtkWidget *adradiobutton2;
  GtkWidget *adradiobutton1;
  GtkWidget *adretour1;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image2;
  GtkWidget *label17;
  GtkWidget *adbutton4;
  GtkWidget *alignment13;
  GtkWidget *hbox13;
  GtkWidget *image13;
  GtkWidget *label29;

  Ajouter_Foyer = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Ajouter_Foyer), _("windowaj"));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (Ajouter_Foyer), fixed2);

  adentryNom1 = gtk_entry_new ();
  gtk_widget_show (adentryNom1);
  gtk_fixed_put (GTK_FIXED (fixed2), adentryNom1, 200, 16);
  gtk_widget_set_size_request (adentryNom1, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (adentryNom1), 8226);

  adentryPrenom1 = gtk_entry_new ();
  gtk_widget_show (adentryPrenom1);
  gtk_fixed_put (GTK_FIXED (fixed2), adentryPrenom1, 200, 64);
  gtk_widget_set_size_request (adentryPrenom1, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (adentryPrenom1), 8226);

  label1 = gtk_label_new (_("Prenom"));
  gtk_widget_show (label1);
  gtk_fixed_put (GTK_FIXED (fixed2), label1, 16, 64);
  gtk_widget_set_size_request (label1, 80, 16);

  label2 = gtk_label_new (_("Niveau"));
  gtk_widget_show (label2);
  gtk_fixed_put (GTK_FIXED (fixed2), label2, 16, 168);
  gtk_widget_set_size_request (label2, 72, 24);

  adentryID1 = gtk_entry_new ();
  gtk_widget_show (adentryID1);
  gtk_fixed_put (GTK_FIXED (fixed2), adentryID1, 200, 120);
  gtk_widget_set_size_request (adentryID1, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (adentryID1), 8226);

  adspinbutton1_adj = gtk_adjustment_new (1, 1, 5, 1, 10, 10);
  adspinbutton1 = gtk_spin_button_new (GTK_ADJUSTMENT (adspinbutton1_adj), 1, 0);
  gtk_widget_show (adspinbutton1);
  gtk_fixed_put (GTK_FIXED (fixed2), adspinbutton1, 216, 168);
  gtk_widget_set_size_request (adspinbutton1, 60, 27);

  label3 = gtk_label_new (_("ID"));
  gtk_widget_show (label3);
  gtk_fixed_put (GTK_FIXED (fixed2), label3, 24, 128);
  gtk_widget_set_size_request (label3, 41, 17);

  label4 = gtk_label_new (_("Numero de chambre"));
  gtk_widget_show (label4);
  gtk_fixed_put (GTK_FIXED (fixed2), label4, 24, 280);
  gtk_widget_set_size_request (label4, 152, 24);

  label5 = gtk_label_new (_("Nom"));
  gtk_widget_show (label5);
  gtk_fixed_put (GTK_FIXED (fixed2), label5, 24, 16);
  gtk_widget_set_size_request (label5, 40, 16);

  label6 = gtk_label_new (_("Bloc"));
  gtk_widget_show (label6);
  gtk_fixed_put (GTK_FIXED (fixed2), label6, 0, 224);
  gtk_widget_set_size_request (label6, 88, 24);

  adcombobox1 = gtk_combo_box_new_text ();
  gtk_widget_show (adcombobox1);
  gtk_fixed_put (GTK_FIXED (fixed2), adcombobox1, 256, 280);
  gtk_widget_set_size_request (adcombobox1, 49, 31);
  gtk_combo_box_append_text (GTK_COMBO_BOX (adcombobox1), _("1"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (adcombobox1), _("2"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (adcombobox1), _("3"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (adcombobox1), _("4"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (adcombobox1), _("5"));

  adradiobutton3 = gtk_radio_button_new_with_mnemonic (NULL, _("C"));
  gtk_widget_show (adradiobutton3);
  gtk_fixed_put (GTK_FIXED (fixed2), adradiobutton3, 384, 224);
  gtk_widget_set_size_request (adradiobutton3, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (adradiobutton3), adradiobutton3_group);
  adradiobutton3_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (adradiobutton3));

  adradiobutton2 = gtk_radio_button_new_with_mnemonic (NULL, _("B"));
  gtk_widget_show (adradiobutton2);
  gtk_fixed_put (GTK_FIXED (fixed2), adradiobutton2, 264, 224);
  gtk_widget_set_size_request (adradiobutton2, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (adradiobutton2), adradiobutton3_group);
  adradiobutton3_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (adradiobutton2));

  adradiobutton1 = gtk_radio_button_new_with_mnemonic (NULL, _("A"));
  gtk_widget_show (adradiobutton1);
  gtk_fixed_put (GTK_FIXED (fixed2), adradiobutton1, 136, 224);
  gtk_widget_set_size_request (adradiobutton1, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (adradiobutton1), adradiobutton3_group);
  adradiobutton3_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (adradiobutton1));

  adretour1 = gtk_button_new ();
  gtk_widget_show (adretour1);
  gtk_fixed_put (GTK_FIXED (fixed2), adretour1, 168, 328);
  gtk_widget_set_size_request (adretour1, 96, 29);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (adretour1), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image2 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox2), image2, FALSE, FALSE, 0);

  label17 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label17);
  gtk_box_pack_start (GTK_BOX (hbox2), label17, FALSE, FALSE, 0);

  adbutton4 = gtk_button_new ();
  gtk_widget_show (adbutton4);
  gtk_fixed_put (GTK_FIXED (fixed2), adbutton4, 312, 328);
  gtk_widget_set_size_request (adbutton4, 96, 32);

  alignment13 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment13);
  gtk_container_add (GTK_CONTAINER (adbutton4), alignment13);

  hbox13 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox13);
  gtk_container_add (GTK_CONTAINER (alignment13), hbox13);

  image13 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image13);
  gtk_box_pack_start (GTK_BOX (hbox13), image13, FALSE, FALSE, 0);

  label29 = gtk_label_new_with_mnemonic (_("Confirmer"));
  gtk_widget_show (label29);
  gtk_box_pack_start (GTK_BOX (hbox13), label29, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) adradiobutton3, "toggled",
                    G_CALLBACK (on_adradiobutton3_toggled),
                    NULL);
  g_signal_connect ((gpointer) adradiobutton2, "toggled",
                    G_CALLBACK (on_adradiobutton2_toggled),
                    NULL);
  g_signal_connect ((gpointer) adradiobutton1, "toggled",
                    G_CALLBACK (on_adradiobutton1_toggled),
                    NULL);
  g_signal_connect ((gpointer) adretour1, "clicked",
                    G_CALLBACK (on_adretour1_clicked),
                    NULL);
  g_signal_connect ((gpointer) adbutton4, "clicked",
                    G_CALLBACK (on_adbutton4_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Ajouter_Foyer, Ajouter_Foyer, "Ajouter_Foyer");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, adentryNom1, "adentryNom1");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, adentryPrenom1, "adentryPrenom1");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, label1, "label1");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, label2, "label2");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, adentryID1, "adentryID1");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, adspinbutton1, "adspinbutton1");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, label3, "label3");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, label4, "label4");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, label5, "label5");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, label6, "label6");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, adcombobox1, "adcombobox1");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, adradiobutton3, "adradiobutton3");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, adradiobutton2, "adradiobutton2");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, adradiobutton1, "adradiobutton1");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, adretour1, "adretour1");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, image2, "image2");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, label17, "label17");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, adbutton4, "adbutton4");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, alignment13, "alignment13");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, hbox13, "hbox13");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, image13, "image13");
  GLADE_HOOKUP_OBJECT (Ajouter_Foyer, label29, "label29");

  return Ajouter_Foyer;
}

GtkWidget*
create_Modifier_Foyer (void)
{
  GtkWidget *Modifier_Foyer;
  GtkWidget *fixed3;
  GtkWidget *adentryNom2;
  GtkWidget *adentryprenom2;
  GtkWidget *adentryID2;
  GtkWidget *adentryNiveau2;
  GtkWidget *adentrychambre;
  GtkWidget *adentryBloc3;
  GtkWidget *label11;
  GtkWidget *label12;
  GtkWidget *label9;
  GtkWidget *label7;
  GtkWidget *label10;
  GtkWidget *label8;
  GtkWidget *adbutton5;
  GtkWidget *alignment14;
  GtkWidget *hbox14;
  GtkWidget *image14;
  GtkWidget *label30;
  GtkWidget *adretour2;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label18;

  Modifier_Foyer = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Modifier_Foyer), _("windowmod"));

  fixed3 = gtk_fixed_new ();
  gtk_widget_show (fixed3);
  gtk_container_add (GTK_CONTAINER (Modifier_Foyer), fixed3);

  adentryNom2 = gtk_entry_new ();
  gtk_widget_show (adentryNom2);
  gtk_fixed_put (GTK_FIXED (fixed3), adentryNom2, 184, 56);
  gtk_widget_set_size_request (adentryNom2, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (adentryNom2), 8226);

  adentryprenom2 = gtk_entry_new ();
  gtk_widget_show (adentryprenom2);
  gtk_fixed_put (GTK_FIXED (fixed3), adentryprenom2, 184, 88);
  gtk_widget_set_size_request (adentryprenom2, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (adentryprenom2), 8226);

  adentryID2 = gtk_entry_new ();
  gtk_widget_show (adentryID2);
  gtk_fixed_put (GTK_FIXED (fixed3), adentryID2, 184, 16);
  gtk_widget_set_size_request (adentryID2, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (adentryID2), 8226);

  adentryNiveau2 = gtk_entry_new ();
  gtk_widget_show (adentryNiveau2);
  gtk_fixed_put (GTK_FIXED (fixed3), adentryNiveau2, 184, 120);
  gtk_widget_set_size_request (adentryNiveau2, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (adentryNiveau2), 8226);

  adentrychambre = gtk_entry_new ();
  gtk_widget_show (adentrychambre);
  gtk_fixed_put (GTK_FIXED (fixed3), adentrychambre, 184, 200);
  gtk_widget_set_size_request (adentrychambre, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (adentrychambre), 8226);

  adentryBloc3 = gtk_entry_new ();
  gtk_widget_show (adentryBloc3);
  gtk_fixed_put (GTK_FIXED (fixed3), adentryBloc3, 184, 160);
  gtk_widget_set_size_request (adentryBloc3, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (adentryBloc3), 8226);

  label11 = gtk_label_new (_("Entrez ID "));
  gtk_widget_show (label11);
  gtk_fixed_put (GTK_FIXED (fixed3), label11, 16, 24);
  gtk_widget_set_size_request (label11, 128, 16);

  label12 = gtk_label_new (_("Nouveau nom"));
  gtk_widget_show (label12);
  gtk_fixed_put (GTK_FIXED (fixed3), label12, 24, 64);
  gtk_widget_set_size_request (label12, 112, 17);

  label9 = gtk_label_new (_("Nouveau niveau"));
  gtk_widget_show (label9);
  gtk_fixed_put (GTK_FIXED (fixed3), label9, 24, 128);
  gtk_widget_set_size_request (label9, 120, 16);

  label7 = gtk_label_new (_("Nouveau N de chambre"));
  gtk_widget_show (label7);
  gtk_fixed_put (GTK_FIXED (fixed3), label7, 8, 208);
  gtk_widget_set_size_request (label7, 176, 16);

  label10 = gtk_label_new (_("Nouveau bloc"));
  gtk_widget_show (label10);
  gtk_fixed_put (GTK_FIXED (fixed3), label10, 16, 168);
  gtk_widget_set_size_request (label10, 120, 16);

  label8 = gtk_label_new (_("Nouveau prenom"));
  gtk_widget_show (label8);
  gtk_fixed_put (GTK_FIXED (fixed3), label8, 24, 96);
  gtk_widget_set_size_request (label8, 120, 17);

  adbutton5 = gtk_button_new ();
  gtk_widget_show (adbutton5);
  gtk_fixed_put (GTK_FIXED (fixed3), adbutton5, 264, 248);
  gtk_widget_set_size_request (adbutton5, 104, 32);

  alignment14 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment14);
  gtk_container_add (GTK_CONTAINER (adbutton5), alignment14);

  hbox14 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox14);
  gtk_container_add (GTK_CONTAINER (alignment14), hbox14);

  image14 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image14);
  gtk_box_pack_start (GTK_BOX (hbox14), image14, FALSE, FALSE, 0);

  label30 = gtk_label_new_with_mnemonic (_("Confirmer"));
  gtk_widget_show (label30);
  gtk_box_pack_start (GTK_BOX (hbox14), label30, FALSE, FALSE, 0);

  adretour2 = gtk_button_new ();
  gtk_widget_show (adretour2);
  gtk_fixed_put (GTK_FIXED (fixed3), adretour2, 80, 248);
  gtk_widget_set_size_request (adretour2, 96, 32);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (adretour2), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label18 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label18);
  gtk_box_pack_start (GTK_BOX (hbox3), label18, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) adbutton5, "clicked",
                    G_CALLBACK (on_adbutton5_clicked),
                    NULL);
  g_signal_connect ((gpointer) adretour2, "clicked",
                    G_CALLBACK (on_adretour2_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Modifier_Foyer, Modifier_Foyer, "Modifier_Foyer");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, fixed3, "fixed3");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, adentryNom2, "adentryNom2");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, adentryprenom2, "adentryprenom2");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, adentryID2, "adentryID2");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, adentryNiveau2, "adentryNiveau2");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, adentrychambre, "adentrychambre");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, adentryBloc3, "adentryBloc3");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, label11, "label11");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, label12, "label12");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, label9, "label9");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, label7, "label7");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, label10, "label10");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, label8, "label8");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, adbutton5, "adbutton5");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, alignment14, "alignment14");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, hbox14, "hbox14");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, image14, "image14");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, label30, "label30");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, adretour2, "adretour2");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, image3, "image3");
  GLADE_HOOKUP_OBJECT (Modifier_Foyer, label18, "label18");

  return Modifier_Foyer;
}

GtkWidget*
create_Supprimer_Foyer (void)
{
  GtkWidget *Supprimer_Foyer;
  GtkWidget *fixed4;
  GtkWidget *adentryNom4;
  GtkWidget *adretour3;
  GtkWidget *alignment4;
  GtkWidget *hbox4;
  GtkWidget *image4;
  GtkWidget *label19;
  GtkWidget *adbutton6;
  GtkWidget *alignment8;
  GtkWidget *hbox8;
  GtkWidget *image8;
  GtkWidget *label24;
  GtkWidget *adcheckbutton1;
  GtkWidget *alignment15;
  GtkWidget *hbox15;
  GtkWidget *image15;
  GtkWidget *label31;
  GtkWidget *label14;

  Supprimer_Foyer = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Supprimer_Foyer), _("windowsupp"));

  fixed4 = gtk_fixed_new ();
  gtk_widget_show (fixed4);
  gtk_container_add (GTK_CONTAINER (Supprimer_Foyer), fixed4);

  adentryNom4 = gtk_entry_new ();
  gtk_widget_show (adentryNom4);
  gtk_fixed_put (GTK_FIXED (fixed4), adentryNom4, 88, 88);
  gtk_widget_set_size_request (adentryNom4, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (adentryNom4), 8226);

  adretour3 = gtk_button_new ();
  gtk_widget_show (adretour3);
  gtk_fixed_put (GTK_FIXED (fixed4), adretour3, 56, 184);
  gtk_widget_set_size_request (adretour3, 96, 32);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (adretour3), alignment4);

  hbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox4);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox4);

  image4 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox4), image4, FALSE, FALSE, 0);

  label19 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label19);
  gtk_box_pack_start (GTK_BOX (hbox4), label19, FALSE, FALSE, 0);

  adbutton6 = gtk_button_new ();
  gtk_widget_show (adbutton6);
  gtk_fixed_put (GTK_FIXED (fixed4), adbutton6, 176, 184);
  gtk_widget_set_size_request (adbutton6, 96, 32);

  alignment8 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment8);
  gtk_container_add (GTK_CONTAINER (adbutton6), alignment8);

  hbox8 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox8);
  gtk_container_add (GTK_CONTAINER (alignment8), hbox8);

  image8 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image8);
  gtk_box_pack_start (GTK_BOX (hbox8), image8, FALSE, FALSE, 0);

  label24 = gtk_label_new_with_mnemonic (_("Supprimer"));
  gtk_widget_show (label24);
  gtk_box_pack_start (GTK_BOX (hbox8), label24, FALSE, FALSE, 0);

  adcheckbutton1 = gtk_check_button_new ();
  gtk_widget_show (adcheckbutton1);
  gtk_fixed_put (GTK_FIXED (fixed4), adcheckbutton1, 104, 144);
  gtk_widget_set_size_request (adcheckbutton1, 118, 24);

  alignment15 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment15);
  gtk_container_add (GTK_CONTAINER (adcheckbutton1), alignment15);

  hbox15 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox15);
  gtk_container_add (GTK_CONTAINER (alignment15), hbox15);

  image15 = gtk_image_new_from_stock ("gtk-ok", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image15);
  gtk_box_pack_start (GTK_BOX (hbox15), image15, FALSE, FALSE, 0);

  label31 = gtk_label_new_with_mnemonic (_("verification"));
  gtk_widget_show (label31);
  gtk_box_pack_start (GTK_BOX (hbox15), label31, FALSE, FALSE, 0);

  label14 = gtk_label_new (_("Entrez ID a supprimer"));
  gtk_widget_show (label14);
  gtk_fixed_put (GTK_FIXED (fixed4), label14, 40, 40);
  gtk_widget_set_size_request (label14, 248, 40);

  g_signal_connect ((gpointer) adretour3, "clicked",
                    G_CALLBACK (on_adretour3_clicked),
                    NULL);
  g_signal_connect ((gpointer) adbutton6, "clicked",
                    G_CALLBACK (on_adbutton6_clicked),
                    NULL);
  g_signal_connect ((gpointer) adcheckbutton1, "toggled",
                    G_CALLBACK (on_adcheckbutton1_toggled),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Supprimer_Foyer, Supprimer_Foyer, "Supprimer_Foyer");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, fixed4, "fixed4");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, adentryNom4, "adentryNom4");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, adretour3, "adretour3");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, image4, "image4");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, label19, "label19");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, adbutton6, "adbutton6");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, alignment8, "alignment8");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, hbox8, "hbox8");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, image8, "image8");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, label24, "label24");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, adcheckbutton1, "adcheckbutton1");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, alignment15, "alignment15");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, hbox15, "hbox15");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, image15, "image15");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, label31, "label31");
  GLADE_HOOKUP_OBJECT (Supprimer_Foyer, label14, "label14");

  return Supprimer_Foyer;
}

GtkWidget*
create_Afficher_Foyer (void)
{
  GtkWidget *Afficher_Foyer;
  GtkWidget *fixed5;
  GtkWidget *adtreeview1;
  GtkWidget *label15;
  GtkWidget *adbuttonactualiser;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label16;
  GtkWidget *adretour4;
  GtkWidget *alignment5;
  GtkWidget *hbox5;
  GtkWidget *image5;
  GtkWidget *label20;

  Afficher_Foyer = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Afficher_Foyer), _("windowaff"));

  fixed5 = gtk_fixed_new ();
  gtk_widget_show (fixed5);
  gtk_container_add (GTK_CONTAINER (Afficher_Foyer), fixed5);

  adtreeview1 = gtk_tree_view_new ();
  gtk_widget_show (adtreeview1);
  gtk_fixed_put (GTK_FIXED (fixed5), adtreeview1, 32, 40);
  gtk_widget_set_size_request (adtreeview1, 300, 200);

  label15 = gtk_label_new (_("LISTE DES ETUDIANTS"));
  gtk_widget_show (label15);
  gtk_fixed_put (GTK_FIXED (fixed5), label15, 104, 0);
  gtk_widget_set_size_request (label15, 192, 48);

  adbuttonactualiser = gtk_button_new ();
  gtk_widget_show (adbuttonactualiser);
  gtk_fixed_put (GTK_FIXED (fixed5), adbuttonactualiser, 200, 256);
  gtk_widget_set_size_request (adbuttonactualiser, 112, 40);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (adbuttonactualiser), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-refresh", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label16 = gtk_label_new_with_mnemonic (_("Actualiser"));
  gtk_widget_show (label16);
  gtk_box_pack_start (GTK_BOX (hbox1), label16, FALSE, FALSE, 0);

  adretour4 = gtk_button_new ();
  gtk_widget_show (adretour4);
  gtk_fixed_put (GTK_FIXED (fixed5), adretour4, 64, 256);
  gtk_widget_set_size_request (adretour4, 112, 37);

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (adretour4), alignment5);

  hbox5 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox5);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox5);

  image5 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image5);
  gtk_box_pack_start (GTK_BOX (hbox5), image5, FALSE, FALSE, 0);

  label20 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label20);
  gtk_box_pack_start (GTK_BOX (hbox5), label20, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) adtreeview1, "row_activated",
                    G_CALLBACK (on_adtreeview1_row_activated),
                    NULL);
  g_signal_connect ((gpointer) adbuttonactualiser, "clicked",
                    G_CALLBACK (on_adbuttonactualiser_clicked),
                    NULL);
  g_signal_connect ((gpointer) adretour4, "clicked",
                    G_CALLBACK (on_adretour4_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Afficher_Foyer, Afficher_Foyer, "Afficher_Foyer");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, fixed5, "fixed5");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, adtreeview1, "adtreeview1");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, label15, "label15");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, adbuttonactualiser, "adbuttonactualiser");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, image1, "image1");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, label16, "label16");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, adretour4, "adretour4");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, image5, "image5");
  GLADE_HOOKUP_OBJECT (Afficher_Foyer, label20, "label20");

  return Afficher_Foyer;
}

GtkWidget*
create_Rechercher_Foyer (void)
{
  GtkWidget *Rechercher_Foyer;
  GtkWidget *fixed6;
  GtkWidget *adentry44;
  GtkWidget *adlabel7;
  GtkWidget *adbuttoncher;
  GtkWidget *alignment6;
  GtkWidget *hbox6;
  GtkWidget *image6;
  GtkWidget *label22;
  GtkWidget *adretour5;
  GtkWidget *alignment7;
  GtkWidget *hbox7;
  GtkWidget *image7;
  GtkWidget *label23;

  Rechercher_Foyer = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (Rechercher_Foyer), _("Rechercher Foyer"));

  fixed6 = gtk_fixed_new ();
  gtk_widget_show (fixed6);
  gtk_container_add (GTK_CONTAINER (Rechercher_Foyer), fixed6);

  adentry44 = gtk_entry_new ();
  gtk_widget_show (adentry44);
  gtk_fixed_put (GTK_FIXED (fixed6), adentry44, 120, 64);
  gtk_widget_set_size_request (adentry44, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (adentry44), 8226);

  adlabel7 = gtk_label_new ("");
  gtk_widget_show (adlabel7);
  gtk_fixed_put (GTK_FIXED (fixed6), adlabel7, 128, 112);
  gtk_widget_set_size_request (adlabel7, 144, 72);

  adbuttoncher = gtk_button_new ();
  gtk_widget_show (adbuttoncher);
  gtk_fixed_put (GTK_FIXED (fixed6), adbuttoncher, 208, 200);
  gtk_widget_set_size_request (adbuttoncher, 136, 32);

  alignment6 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment6);
  gtk_container_add (GTK_CONTAINER (adbuttoncher), alignment6);

  hbox6 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox6);
  gtk_container_add (GTK_CONTAINER (alignment6), hbox6);

  image6 = gtk_image_new_from_stock ("gtk-find", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image6);
  gtk_box_pack_start (GTK_BOX (hbox6), image6, FALSE, FALSE, 0);

  label22 = gtk_label_new_with_mnemonic (_("Rechercher"));
  gtk_widget_show (label22);
  gtk_box_pack_start (GTK_BOX (hbox6), label22, FALSE, FALSE, 0);

  adretour5 = gtk_button_new ();
  gtk_widget_show (adretour5);
  gtk_fixed_put (GTK_FIXED (fixed6), adretour5, 64, 200);
  gtk_widget_set_size_request (adretour5, 128, 32);

  alignment7 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment7);
  gtk_container_add (GTK_CONTAINER (adretour5), alignment7);

  hbox7 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox7);
  gtk_container_add (GTK_CONTAINER (alignment7), hbox7);

  image7 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image7);
  gtk_box_pack_start (GTK_BOX (hbox7), image7, FALSE, FALSE, 0);

  label23 = gtk_label_new_with_mnemonic (_("Retour"));
  gtk_widget_show (label23);
  gtk_box_pack_start (GTK_BOX (hbox7), label23, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) adbuttoncher, "clicked",
                    G_CALLBACK (on_adbuttoncher_clicked),
                    NULL);
  g_signal_connect ((gpointer) adretour5, "clicked",
                    G_CALLBACK (on_adretour5_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (Rechercher_Foyer, Rechercher_Foyer, "Rechercher_Foyer");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, fixed6, "fixed6");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, adentry44, "adentry44");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, adlabel7, "adlabel7");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, adbuttoncher, "adbuttoncher");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, alignment6, "alignment6");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, hbox6, "hbox6");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, image6, "image6");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, label22, "label22");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, adretour5, "adretour5");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, alignment7, "alignment7");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, hbox7, "hbox7");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, image7, "image7");
  GLADE_HOOKUP_OBJECT (Rechercher_Foyer, label23, "label23");

  return Rechercher_Foyer;
}

