
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h> 
#include "affichage.h"
#include "sauvegarde.h"
#include "gestionClavier.h"
#include "gestionNiveau.h"
#include "sauvegarde.h"
#include "jouer.h"

void clrscr(void)
{
    printf("\x1B[2J");
}

//Afficher le menu
int menu() {
    int choix;
    //text_color(FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
    printf("===== MENU PRINCIPAL =====\n");
    printf("1. Lire les regles du jeu\n");
    printf("2. Commencer une nouvelle partie\n");
    printf("3. Reprendre une partie\n");
    printf("4. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    return choix;
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
            case 2 : /*lancement d'une partie*/
                    //hide_cursor();
                    clrscr();
                    jeu();
                    //show_cursor();
                    break;
            case 1 :
                    afficherRegles();
                    break;
            case 3 : {
                char pseudo[50];
                int niveau, vies;

                printf("Entrez votre pseudo : ");
                scanf("%s", pseudo);

                if (chargerPartie(pseudo, &niveau, &vies)) {
                    printf("Sauvegarde chargee ! Niveau %d, Vies %d\n", niveau, vies);
                    lancerNiveau(niveau, vies);
                } else {
                    printf("Aucune sauvegarde pour ce pseudo.\n");
                    Sleep(1500);
                }
                break;
            }
        }
    }while(choix!=4);

    return 0;
}
