#include <stdio.h>
#include <gtk/gtk.h>
#include "Gestion.h"
GtkBuilder *builder ;
void GEmprunt() {	
	builder = gtk_builder_new();
	gtk_builder_add_from_file (builder , "Main.glade" , NULL);
	GtkWidget * Window_emprunt;
	GtkWidget * GEmprunter , *GAfficher_Emprunteur , *GRendre , *GLivre_Emprunt;
	Window_emprunt = GTK_WIDGET(gtk_builder_get_object(builder,"Emprunt"));
	GEmprunter = GTK_WIDGET(gtk_builder_get_object(builder,"emprunter"));
	GAfficher_Emprunteur = GTK_WIDGET(gtk_builder_get_object(builder,"affiche_emprunteur"));
	GLivre_Emprunt = GTK_WIDGET(gtk_builder_get_object(builder,"Affiche_livre_emprunte"));	
	GRendre = GTK_WIDGET(gtk_builder_get_object(builder,"rendre"));	
	g_signal_connect(GEmprunter ,"clicked" ,            G_CALLBACK(Emprunter) , NULL) ;
	g_signal_connect(GAfficher_Emprunteur ,"clicked" ,  G_CALLBACK(Afficher_Emprunteur) , NULL) ;
	g_signal_connect(GLivre_Emprunt ,"clicked" ,               G_CALLBACK(Livre_Emprunt) , NULL) ;
	g_signal_connect(GRendre ,"clicked" ,        G_CALLBACK(Rendre) , NULL) ;
	gtk_widget_show_all(Window_emprunt);
}
void GAdherent() {
	builder = gtk_builder_new();
	gtk_builder_add_from_file (builder , "Main.glade" , NULL);
	GtkWidget * Window_Adherent;
	GtkWidget *GCharger , *GAjouter , *GRechercher ,*GSauvegarder, *GSupprimer , *GModifier;
	Window_Adherent = GTK_WIDGET(gtk_builder_get_object(builder,"Adherent"));
	GCharger = GTK_WIDGET(gtk_builder_get_object(builder,"Charger"));
	GAjouter = GTK_WIDGET(gtk_builder_get_object(builder,"Ajouter"));
	GRechercher = GTK_WIDGET(gtk_builder_get_object(builder,"Rechercher"));	
	GSauvegarder = GTK_WIDGET(gtk_builder_get_object(builder,"Exporter"));	
	GSupprimer = GTK_WIDGET(gtk_builder_get_object(builder,"Supprimer"));	
	GModifier = GTK_WIDGET(gtk_builder_get_object(builder,"Modifier"));	
	g_signal_connect(GCharger ,"clicked" ,    G_CALLBACK(Charger_Adherent) , NULL) ;
	g_signal_connect(GAjouter ,"clicked" ,    G_CALLBACK(Ajouter_Adherent) ,  NULL) ;
	g_signal_connect(GRechercher ,"clicked" , G_CALLBACK(Rechercher_Adherent) , NULL) ;
	g_signal_connect(GSauvegarder ,"clicked" ,G_CALLBACK(Sauvegarder_Adherent) , NULL) ;
	g_signal_connect(GSupprimer ,"clicked" ,  G_CALLBACK(Supprimer_Adherent) , NULL) ;
	g_signal_connect(GModifier ,"clicked" ,   G_CALLBACK(Modifier_Adherent) , NULL) ;
	gtk_widget_show_all(Window_Adherent);
}
void GLivre(){
	builder = gtk_builder_new();
	gtk_builder_add_from_file (builder , "Main.glade" , NULL);
	GtkWidget * Window_livres;
	GtkWidget *GCharger , *GAjouter , *GRechercher ,*GSauvegarder , *GSupprimer , *GModifier;
	Window_livres = GTK_WIDGET(gtk_builder_get_object(builder,"Livres"));
	GCharger = GTK_WIDGET(gtk_builder_get_object(builder,"Charger"));
	GAjouter = GTK_WIDGET(gtk_builder_get_object(builder,"Ajouter"));
	GRechercher = GTK_WIDGET(gtk_builder_get_object(builder,"Rechercher"));	
	GSauvegarder = GTK_WIDGET(gtk_builder_get_object(builder,"Exporter"));	
	GSupprimer = GTK_WIDGET(gtk_builder_get_object(builder,"Supprimer"));	
	GModifier = GTK_WIDGET(gtk_builder_get_object(builder,"Modifier"));	
	g_signal_connect(GCharger ,"clicked" ,      G_CALLBACK(Charger_Livre) , NULL);
	g_signal_connect(GAjouter ,"clicked" ,      G_CALLBACK(Ajouter_Livre) , NULL);
	g_signal_connect(GSupprimer ,"clicked" ,    G_CALLBACK(Supprimer_Livre) , NULL);
	g_signal_connect(GSauvegarder ,"clicked" ,  G_CALLBACK(Sauvegarder_Livre)  ,  NULL);
	g_signal_connect(GModifier ,"clicked" ,     G_CALLBACK(Modifier_Livre) , NULL);
	g_signal_connect(GRechercher ,"clicked" ,   G_CALLBACK(Rechercher_Livre) , NULL);
	gtk_widget_show_all(Window_livres);
}
int main(int argc ,char **argv) {
	gtk_init(&argc , &argv);
	builder = gtk_builder_new();
	gtk_builder_add_from_file (builder , "Main.glade" , NULL);
	GtkWidget * window;
	GtkWidget * button_emprunt , *button_livre , *button_adherent;
	window = GTK_WIDGET(gtk_builder_get_object(builder,"Main_window"));
	button_emprunt = GTK_WIDGET(gtk_builder_get_object(builder,"button_emprunt"));
	button_adherent = GTK_WIDGET(gtk_builder_get_object(builder,"button_adherent"));
	button_livre = GTK_WIDGET(gtk_builder_get_object(builder,"button_livre"));
	g_signal_connect(button_emprunt ,"clicked" , G_CALLBACK(GEmprunt) , NULL) ;
	g_signal_connect(button_adherent ,"clicked" ,  G_CALLBACK(GAdherent) ,NULL) ;
	g_signal_connect(button_livre ,"clicked" , G_CALLBACK(GLivre) , NULL) ;
	gtk_widget_show_all(window);
	gtk_main();
	return 0 ;
};
