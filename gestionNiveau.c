
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> 
#include "affichage.h"
#include "sauvegarde.h"
#include "gestionClavier.h"
#include "sauvegarde.h"
#include "gestionNiveaux.h"

#define HAUTEUR 10
#define LARGEUR 9
#define DUREE 120000
int niveau=1;

int get_niveau() { return niveau}

void lancerNiveau(int xcurseur, int ycurseur, int temps_restant, int compteurs_contrat[7]) {
	xcurseur=LARGEUR/2;
	ycurseur=HAUTEUR/2;
	jeu(temps_restant);
	viderGrille();
	genererItems();
	assurerGrilleJouable();
	afficherGrille();
	afficherNumeroDuNiveau(niveau);
	afficherNombreDeVies(vies);
	afficherTempsRestants(temps_fin, temps_restant);
	afficherCoupsRestants(coups_restants);
	afficherRegles();
	afficherItemsRestants(type_items);

	switch(niveau) {
		case 1: // Definir 1e contrat du niveau 1
			for (int i=1 ; i<=3 ; i++) compteurs_contrat[i] = 5;
			for (int i=4 ; i<=5 ; i++) compteurs_contrat[i] = 10;
			break;
		case 2:  // Definir 1e contrat du niveau 2
			for (int i=1 ; i<=3 ; i++) compteurs_contrat[i] = 8;
			for (int i=4 ; i<=5 ; i++) compteurs_contrat[i] = 10;
			break;
		case 3:  // Definir 1e contrat du niveau 3
			for (int i=1 ; i<=3 ; i++) compteurs_contrat[i] = 10;
			for (int i=4 ; i<=5 ; i++) compteurs_contrat[i] = 12;
			break;
	}
}

void gerePerteVies(int *vies_restantes){
    if (*nb_vies_restantes > 0) {
        (*nb_vies_restantes)--; //utilisateur perd une vie s'il lui en reste
    }
}
void gereVictoireNiveau(){
	printf("###############################################\n");
	printf("#                                             #\n");
	printf("     ! Bravo vous avez gagne le niveau !       \n");
	printf("#                                             #\n");
	printf("###############################################\n");	
	Sleep(5000); //affichage du message pendant 5 sec
}
void gererEchecNiveau(){
	printf("###############################################\n");
	printf("#                                             #\n");
	printf("      Dommage vous avez perdu le niveau :(     \n");
	printf("#                                             #\n");
	printf("###############################################\n");
	Sleep(5000);
}
void gererVictoirePartie(int niveau){
    if (niveau == 3){
        system("cls");
        printf("\n\n");
        printf("#############################################\n");
        printf("#                                           #\n");
        printf("#   FELICITATIONS !                         #\n");
        printf("#   Vous avez termine le JEU !              #\n");
        printf("#                                           #\n");
        printf("#############################################\n");
        printf("\nRetour au menu principal...\n");
        Sleep(10000); // pause 10 secondes
        menu(); // retour au menu
    }
}
void gererEchecPartie(){
    int vies = gererPerteVie();
    if (vies > 0){
        char choix;
        printf("Echec de la partie. Il vous reste %d vie(s).\n", vies);
        printf("Relancer le niveau ? (O/N)\n");
        choix = getch();
        if (choix == 'O' || choix == 'o'){
            lancerNiveau();
        }
        else{
            menu();
        }
    }
    else{
        printf("GAME OVER !\n");
        Sleep(3000);
        menu();
void gerePerteVies(int *vies_restantes){
    if (*nb_vies_restantes > 0) {
        (*nb_vies_restantes)--; //utilisateur perd une vie s'il lui en reste
    }
}
