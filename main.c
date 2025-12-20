
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>
// #include <conio.h>
// #include <windows.h> 
// #include "affichage.h"
// #include "sauvegarde.h"
// #include "gestionClavier.h"
// #include "gestionNiveau.h"
// #include "sauvegarde.h"
// #include "jeu.h"

// void clrscr(void)
// {
//     printf("\x1B[2J");
// }

// //Afficher le menu
// int menu() {
//     int choix;
//     //text_color(FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
//     printf("===== MENU PRINCIPAL =====\n");
//     printf("1. Lire les regles du jeu\n");
//     printf("2. Commencer une nouvelle partie\n");
//     printf("3. Reprendre une partie\n");
//     printf("4. Quitter\n");
//     printf("Votre choix : ");
//     scanf("%d", &choix);

//     return choix;
// }
// int main() {
//     int choix;
//     // initialisation du générateur pseudo-aléatoire
//     srand(time(NULL));
//     //boucle de retour au menu à la fin d'une partie
//     do{
//         //gestion du menu
//         choix=menu();
//         switch(choix){
//             case 2 : /*lancement d'une partie*/
//                     //hide_cursor();
//                     clrscr();
//                     jeu();
//                     //show_cursor();
//                     break;
//             case 1 :
//                     afficherRegles();
//                     break;
//         }
//     }while(choix!=3);

//     return 0;
// }

//*********************************NOUVELLE VERSION******************************//

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
#include "jeu.h"

// Efface l'écran
void clrscr(void)
{
    printf("\x1B[2J\x1B[H"); // efface écran et replace le curseur en haut à gauche
}

// Afficher le menu principal
int menu() {
    int choix;
    printf("\n===== MENU PRINCIPAL =====\n");
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
    srand((unsigned int)time(NULL)); // initialisation générateur aléatoire

    do {
        choix = menu();
        switch(choix) {

            case 1: // Afficher règles
                clrscr();
                afficherRegles();
                printf("\nAppuyez sur une touche pour revenir au menu...\n");
                _getch();
                clrscr();
                break;

            case 2: { // Nouvelle partie
                clrscr();
                char pseudo[50];
                printf("Entrez votre pseudo : ");
                scanf("%49s", pseudo);
                clrscr();

                // Initialiser partie : niveau 1, vies 3
                int niveau = 1;
                int vies = 3;

                // Sauvegarder automatiquement le pseudo pour reprise
                sauvegarderPartie(pseudo, niveau, vies);

                // Lancer le niveau
                lancerNiveau(compteurs_contrat);
                break;
            }

            case 3: { // Reprendre partie
                clrscr();
                char pseudo[50];
                printf("Entrez votre pseudo : ");
                scanf("%49s", pseudo);
                clrscr();

                int niveau, vies;
                if (chargerPartie(pseudo, &niveau, &vies)) {
                    printf("Sauvegarde chargee ! Niveau %d, Vies %d\n", niveau, vies);
                    Sleep(1500);
                    clrscr ();

                    // Récupération des compteurs de contrat pour ce niveau
                    lancerNiveau(compteurs_contrat);
                } else {
                    printf("Aucune sauvegarde pour ce pseudo.\n");
                    Sleep(1500);
                }
                break;
            }

            case 4: // Quitter
                printf("Merci d'avoir joue !\n");
                break;

            default:
                printf("Choix invalide, veuillez reessayer.\n");
                Sleep(1000);
                break;
        }

    } while (choix != 4);

    return 0;
}
