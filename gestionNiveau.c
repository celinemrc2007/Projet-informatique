

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> 
#include "affichage.h"
#include "sauvegarde.h"
#include "gestionClavier.h"
#include "sauvegarde.h"
#include "gestionNiveau.h"
#include "jeu.h"


#define HAUTEUR 10
#define LARGEUR 9
#define DUREE 120000
int niveau=1;

int *copie_contrat;

int get_niveau() { return niveau; }

void lancerNiveau(int compteurs_contrat[7]) {
	copie_contrat = compteurs_contrat;

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
	afficherNumeroNiveau(niveau);
	jeu();
}

void gererPerteVies(int *vies_restantes){
    if (*vies_restantes > 0) {
        (*vies_restantes)--; //utilisateur perd une vie s'il lui en reste
    }
}

void gererVictoireNiveau(){
	printf("###############################################\n");
	printf("#                                             #\n");
	printf("     ! Bravo vous avez gagne le niveau !       \n");
	printf("#                                             #\n");
	printf("###############################################\n");	
	Sleep(5000); //affichage du message pendant 5 sec
	gererVictoirePartie (niveau);
}
void gererEchecNiveau(int *vies_restantes){
	printf("###############################################\n");
	printf("#                                             #\n");
	printf("      Dommage vous avez perdu le niveau :(     \n");
	printf("#                                             #\n");
	printf("###############################################\n");
	Sleep(5000);
	gererPerteVies(vies_restantes);
	if(*vies_restantes == 0) {
		gererEchecPartie (vies_restantes);
	} else {
		//reprendrePartie ();
	}
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
    }
}
void gererEchecPartie(int *vies_restantes){
    gererPerteVies(vies_restantes);
    if (*vies_restantes > 0){
        char choix;
        printf("Echec de la partie. Il vous reste %d vie(s).\n", *vies_restantes);
        printf("Relancer le niveau ? (O/N)\n");
        scanf("%c", &choix);
        if (choix == 'O' || choix == 'o'){
            lancerNiveau(copie_contrat);
        }
        else{
          // A faire pb d'organisation menu(); // retour au menu  menu();
        }

    } else{
        printf("GAME OVER !\n");
        Sleep(3000);
       // A faire pb d'organisation menu(); // retour au menu menu();
    }
}


void gererBonusNiveau3(ResultatFigure fig){ //gestion des bonus apparaissant au niveau 3
    if (niveau == 3 &&fig.taille >=5){ //le bonus n'exite qu'au niveau 3 et la figure doit contenir  moins 5 éléments

        // Bonus coups restants si assemblage de 5 ou plus
        if (fig.taille >= 5){
            coups_restants += 5;

            // Sécurité, si le nombre de coups dépasse 99, on le plafonne à 99
            if (coups_restants > 99)
                coups_restants = 99;
        }
    }
}
