#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

#include "affichage.h"
#include "gestionClavier.h"

#define COLONNE_INFO (LARGEUR * 2 + 6) //chaque case fait deux caractères, +6 permet l'espace entre la grille et les infos
#define LIGNE_CONTRAT 1
#define LIGNE_NIVEAU  (HAUTEUR + 3)
#define LIGNE_COUPS   8
#define LIGNE_TEMPS   10
#define LIGNE_VIES    (HAUTEUR + 5)

/* =================== GESTION CONSOLE =================== */

void gotoxy(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
}

void text_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

/* =================== AFFICHAGES INFOS =================== */

void afficherNumeroNiveau(int niveau) {
    char texte[20];
    sprintf(texte, "Niveau %d", niveau);

    int largeur_grille = LARGEUR * 2 + 4;
    int x = (largeur_grille - strlen(texte)) / 2;

    gotoxy(x, LIGNE_NIVEAU);
    printf("%s", texte);
}

void afficherNombredeVies(int vies_restantes) {
    gotoxy(0, LIGNE_VIES);
    printf("Vies : %d   ", vies_restantes);
}

void afficherCoupsRestants(int coups_restants) {
    gotoxy(COLONNE_INFO, LIGNE_COUPS);
    printf("Coups : %2d  ", coups_restants);
}

void afficherTempsRestant(int temps_restant) {
    int minutes = temps_restant / 60;
    int secondes = temps_restant % 60;

    gotoxy(COLONNE_INFO, LIGNE_TEMPS);
    printf("Temps : %02d:%02d  ", minutes, secondes);
}

/* =================== REGLES =================== */

void afficherRegles() {
    system("cls");
    printf("======= Regles du jeu =======\n");
    printf("Le but du jeu est d'eliminer le plus d'items possible lors d'un niveau.\n");
    printf("Il y a 3 niveaux par partie, pour chaque niveau, l'utilisateur doit repondre a un contrat lui indiquant le nombre d'items a eliminer et le temps imparti.\n");
    printf("Pour vous deplacer dans la grille de jeu, utilisez les touches suivantes : \n");
    printf("  z : haut\n");
    printf("  s : bas\n");
    printf("  q : gauche\n");
    printf("  d : droite\n");
    printf("Votre but est de former des suites de 4 items ou plus. Vous pouvez egalement former les figures ci-dessus:\n"); 
    printf("\n");
    printf("                                            XXXX           X\n");
    printf("                                            X  X           X\n");
    printf("                                            X  X         XXXXX\n");
    printf("                                            XXXX           X  \n");
    printf("                                                           X  \n");
    printf("\n");
    printf("Pour cela, echangez des items de place.\n");
    printf("Appuyez sur shift pour selectionner un item puis indiquer la direction de la permutation avec les touches ci-dessus.\n");
    printf("Chaque niveau peut etre sauvegarde avec un pseudo utilisateur, afin d'y retourner plus tard.\n");
    printf("A partir du niveau 2, mefiez-vous des items pourcent: ceux en rouge vous font perdre 10 secondes si vous les assemblez.\n");
    printf("A partir du niveau 3, si vous assemblez 5 items identique  la suite, vous gagnez 5 coups supplementaires.\n");
    printf("A vous de jouer !\n");
    printf("\nAppuyez n'importe quelle touche de votre clavier pour revenir au menu :)");
    _getch();
}

/* =================== GRILLE =================== */

void afficherGrille(int grille[HAUTEUR][LARGEUR]) {
    int y, x;

    gotoxy(0, 0);

    /* Bordure haute */
    for (x = 0; x < LARGEUR + 2; x++)
        printf("# ");
    printf("\n");

    /* Corps de la grille */
    for (y = 0; y < HAUTEUR; y++) {
        printf("# ");
        for (x = 0; x < LARGEUR; x++) {

            switch (grille[y][x]) {
                case 0: printf("  "); break;
                case 1: text_color(FOREGROUND_GREEN | FOREGROUND_BLUE); printf("X "); break;
                case 2: text_color(FOREGROUND_BLUE); printf("O "); break;
                case 3: text_color(FOREGROUND_GREEN); printf("& "); break;
                case 4: text_color(FOREGROUND_RED | FOREGROUND_GREEN); printf("@ "); break;
                case 5: text_color(FOREGROUND_RED | FOREGROUND_BLUE); printf("%% "); break;
                case 13: text_color(FOREGROUND_RED); printf("%% "); break;
                default: printf("? "); break;
            }
            text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        printf("#\n");
    }

    /* Bordure basse */
    for (x = 0; x < LARGEUR + 2; x++)
        printf("# ");
    printf("\n");

    /* Curseur */
    int curseurX = colonneCurseur() * 2 + 2;
    int curseurY = ligneCurseur() + 1;

    gotoxy(curseurX - 1, curseurY);
    printf(">");
    gotoxy(curseurX + 1, curseurY);
    printf("<");
    gotoxy(0,15); // pour printf debug
}

/* =================== CONTRAT =================== */

void afficherItemsRestants(int items[]) {
    gotoxy(COLONNE_INFO, 0);
    printf("Contrat :");
    gotoxy(COLONNE_INFO, 1);
    printf("X : %d  ", items[1]);
    gotoxy(COLONNE_INFO, 2);
    printf("O : %d  ", items[2]);
    gotoxy(COLONNE_INFO, 3);
    printf("& : %d  ", items[3]);
    gotoxy(COLONNE_INFO, 4);
    printf("@ : %d  ", items[4]);
    gotoxy(COLONNE_INFO, 5);
    printf("%% : %d  ", items[5]);
    gotoxy(0,15); // pour printf debug
}
