
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
