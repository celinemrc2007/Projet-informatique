#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> 
#include "affichage.h"
#include "sauvegarde.h"
#include "gestionClavier.h"
#include "gestionNiveaux.h"
#include "sauvegarde.h"

//variables globales 
int curseurL = 0;
int curseurC = 0;

int selectionActive = 0;
int selL, selC;
//Afficher le menu
int menu() {
    int choix;
    text_color(FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
    printf("===== MENU PRINCIPAL =====\n");
    printf("1. Lire les regles du jeu\n");
    printf("2. Commencer une nouvelle partie\n");
    printf("3. Reprendre une partie\n");
    printf("4. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    return choix;
}

void quitterProgramme(void)
{
    printf("\nMerci d'avoir joue. A bientot !\n");
    exit(0);
}

int main() {
    int choix;
    // initialisation du générateur pseudo-aléatoire
    srand(time(NULL));
    //boucle de retour au menu à la fin d'une partie
    do{
        //gestion du menu
        choix=menu();
        switch(choix){
            case 1 : /*lancement d'une partie*/
                    //hide_cursor();
                    clrscr();
                    jouer();
                    //show_cursor();
                    break;
            case 2 :
                    afficherRegles();
                    break;
            case 4:
                    quitterProgramme();
                    break;
        }
    }while(choix!=3);

    return 0;
}

