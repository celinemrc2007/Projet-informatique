
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> 
#define HAUTEUR 10
#define LARGEUR 9
#define DUREE 120000
#define PAS_DE_FIGURE 0
#define SUITE_LIGNE 1
#define SUITE_COLONNE 2
#define CARRE 3
#define CROIX 4
#define TAILLE_CARRE 4
#define TAILLE_CROIX 5
#define TAILLE_BONUS_COUPS 5         //Ajout par nous
#define TAILLE_BONUS_EXPLOSION 6     //Bonus imposé par la consigne
int niveau = 1;
int nb_vies_restantes = 3;

void lancerNiveau(int xcurseur, int ycurseur, int temps_restant) {
	xcurseur=LARGEUR/2;
	ycurseur=HAUTEUR/2;

	switch(niveau) {
		case 1: //Afficher 1e contrat du niveau 1
			jeu(temps_restant);
			viderGrille();
			genererItems();
			assurerGrilleJouable();
			afficherGrille();
			afficherNumeroDuNiveau(niveau);
			afficherNombreDeVies(nb_vies_restantes);
			afficherTempsRestants(temps_fin, temps_restant);
			afficherCoupsRestants(coups_restants);
			afficherRegles();
			afficherItemsRestants(type_items);		
			break;
		case 2: 
			printf("");			//Afficher le contrat du niveau 2
			jeu(temps_restant);
			viderGrille();
			genererItems();
			assurerGrilleJouable();
			afficherGrille();
			afficherNumeroDuNiveau(niveau);
			afficherNombreDeVies(nb_vies_restantes);
			afficherTempsRestants(temps_fin, temps_restant);
			afficherCoupsRestants(coups_restants);
			afficherRegles();
			afficherItemsRestants(type_items);
			//malus(ligne, colonne);	//Ajout du malus au niveau 2
			break;
		case 3: 
			printf("");			//Afficher le contrat du niveau 3
			jeu(temps_restant);
			viderGrille();
			genererItems();
			assurerGrilleJouable();
			afficherGrille();
			afficherNumeroDuNiveau(niveau);
			afficherNombreDeVies(nb_vies_restantes);
			afficherTempsRestants(temps_fin, temps_restant);
			afficherCoupsRestants(coups_restants);
			afficherRegles();
			afficherItemsRestants(type_items);
			//malus(ligne, colonne);	//Ajout du malus au niveau 3
			break;

	}
}

//une autre version mais incomplete je ne sais pas comment la completer
void lancerNiveau(){
    viderGrille();
    genererItems();
    assurerGrilleJouable();

    afficherNumeroDuNiveau(niveau);
    afficherNombreDeVies(nb_vies_restantes);

    // boucle principale du jeu
    int resultat = jeu(niveau);

    if (resultat == 1){
        gererVictoireNiveau();
        niveau++;

        if (niveau > 3){
            gererVictoirePartie();
        }
        else{
            lancerNiveau();
        }
    }
    else{
        gererEchecPartie();
    }
}


int gererPerteVie(){
    if (nb_vies_restantes > 0){
        nb_vies_restantes--;
    }
    return nb_vies_restantes;
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
    }
}
