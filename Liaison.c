#include <stdio.h>
struct donne_adherant {
   int numero; 
   char nom[14];
   char prenom[14];
   char email[30]; 
   char address{30];
   int emprunt;
 }
 typdef struct _Adherant {
   struct donne_adherant don_adh;
   Adherant * next;
 }Adherant;
 struct Auteur {
   char nom[14]; 
   char prenom[14];
 }
 struct donne_livre{
   int numero;
   char titre[30];
   char categorie[12];
   struct Auteur auteur;
   int num_adherant; // a intialiser par -1
 }
 typdef struct _livre {
   struct donne_livre d;
   Livre * next; 
 }Livre;
typedef Adherant* list_adherant;
typedef Livre * list_livre;
void Emprunter(int numero_adherant,int numero_livre); // donner le numero d'adherant  , rechercher par nom le livre
void Afficher_livre_Emprunte(list_livre list);
void Afficher_adherant_emprunteur(list_livre list); // eliminer la redendance des emprunteurs
void Rendre_livre(list_livre *list_lv ,list_adherant* list_adh ,int numero , int numero_adherant);
void Menu();
void Rendre_livre(list_livre *list_lv , list_adherant* list_adh,int numero , int numero_adherant) {
  Livre* livre =  Rechercher_Livre(*list_lv,numero);
  Adherant* adh = Rechercher_Adherant_num(*list_adh,numero_adherant);	
  livre->d.num_adherant = -1;
	adh->don_adh.emprunt -= 1;
  return;
}
void Afficher_livre_Emprunte(list_livre list){
  Livre * ptr = list;
  while(ptr->next != NULL) {
    if (ptr->d.num_adherant != -1) {
     		printf("%d %s %s %s %s %d\n", ptr->d.numero, ptr->d.titre, ptr->d.categorie, ptr->d.auteur.nom, ptr->d.auteur.prenom, ptr->d.num_adherant);
    }
    ptr = ptr->next;
  }
  return;
}  
void Emprunter(int numero_adherant , int numero_livre ,list_livre * list_lv , list_adherant *list_adh ) {
  Livre* livre =  Rechercher_Livre(*list_lv,numero_livre);
  Adherant* adh = Rechercher_Adherant_num(*list_adh,numero_adherant);
  if (livre->d.num_adherant != -1) {
    printf("ce livre est deja emprunté");
    return;
  }else {
    if (adh->don_adh.emprunt == 3) {
      printf("ce client a deja emprunté 3 livres")
      return;
    }
    livre->d.num_adherant = numero_adherant;
    adh->don_adh.emprunt += 1;
  }
  return;
}