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

// Afficher le menu principal
int menu() {
    int choix;
    text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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
                system("cls");
                afficherRegles();
                printf("\nAppuyez sur une touche pour revenir au menu...\n");
                _getch();
                system("cls");
                break;

            case 2: { // Nouvelle partie
                system("cls");
                printf("Entrez votre pseudo : ");
                scanf("%49s", pseudo);
                system("cls");

                // Initialiser partie : niveau 1, vies 3
                niveau = 1;
                vies_restantes = 3;

                // Sauvegarder automatiquement le pseudo pour reprise
                sauvegarderPartie(pseudo, niveau, vies_restantes);

                // Lancer le niveau
                lancerNiveau(compteurs_contrat);
                break;
            }

            case 3: { // Reprendre partie
                system("cls");
                printf("Entrez votre pseudo : ");
                scanf("%49s", pseudo);
                system("cls");

                if (chargerPartie(pseudo, &niveau, &vies_restantes)) {
                    printf("Sauvegarde chargee ! Niveau %d, Vies %d\n", niveau, vies_restantes);
                    Sleep(1500);
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
