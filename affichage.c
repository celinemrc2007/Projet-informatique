// #include <stdio.h>
// #include <stdlib.h>
// #include <windows.h>
// #include <conio.h>
// #include "affichage.h"
// #include "gestionClavier.h"
// #define HAUTEUR 10
// #define LARGEUR 9
// #define COLONNE_INFO (LARGEUR * 2 + 10)

// void gotoxy(int x, int y)
// {
//     printf("\x1B[%d;%dH", y, x);
// }

// void text_color(int color)
// {
//     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//     SetConsoleTextAttribute(hConsole, color);
// }

// //X : 1                       O : 2                         & : 3                        @ : 4                  % : 5             

// void afficherNumeroNiveau(int niveau){ //afficher le numero du niveau (1 2 ou 3)
//     gotoxy(5, HAUTEUR + 5); //position ligne 1
//     printf("Niveau actuel : %d\n", niveau);
// } 


// void afficherNombredeVies(int vies_restantes){
//     gotoxy(COLONNE_INFO, 11);
//     printf("Vies restantes : %d\n", vies_restantes);
// }

// void afficherTempsRestant(int tempsrestant){ //afficher le temps restant pour chaque niveau en seconde
//     while(tempsrestant>=0){
//         int minutes = tempsrestant / 60;
//         int secondes = tempsrestant %60;
//         gotoxy(COLONNE_INFO, 7); //position ligne 2
//         printf("Temps restant : %02d:%02d\n", minutes, secondes); //affichage du temps restant avec deux chiffres pour minutes et secondes
//         Sleep(1000); //attendre 1 sec
//         tempsrestant--;
//     }
//     printf("\nLe temps est termine !\n");
// }

// void afficherRegles(){
//     gotoxy(0, 3); //position ligne 3
//     printf("======= Regles du jeu =======\n");
//     printf("Le but du jeu est d'eliminer le plus d'items possible lors d'un niveau. Il y a 3 niveaux par partie, pour chaque niveau, l'utilisateur doit repondre à un contrat lui indiquant le nombre d'items a eliminer et le temps imparti.\n");
//     printf("Chaque niveau peut etre sauvegarde avec un pseudo utilisateur, afin d'y retourner plus tard.\n");
//     printf("A vous de jouer !\n");
// }

// void afficherGrille(int grille[HAUTEUR][LARGEUR]){
//     int y, x;

//     gotoxy(0, 0);

//     for (y = 0; y < HAUTEUR + 2; y++) {
//         for (x = 0; x < LARGEUR + 2; x++) {

//             // Bordures
//             if (y == 0 || y == HAUTEUR + 1 || x == 0 || x == LARGEUR + 1) {
//                 text_color(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
//                 printf("# ");
//             }
//             //Intérieur : affichage de la grille
//             else {
//                 int item = grille[y-1][x-1]; //la grille commence à partir de (1,1)

//                 switch (item) {
//                     case 0: 
//                         printf("  "); break;
//                     case 1: //rouge
//                         text_color(FOREGROUND_RED);
//                         printf("X "); break;
//                     case 2: //bleu
//                         text_color(FOREGROUND_BLUE);
//                         printf("O "); break;
//                     case 3: //vert
//                         text_color(FOREGROUND_GREEN);
//                         printf("& "); break;
//                     case 4: //jaune
//                         text_color(FOREGROUND_RED | FOREGROUND_GREEN);
//                         printf("@ "); break;
//                     case 5: //magenta
//                         text_color(FOREGROUND_RED | FOREGROUND_BLUE);
//                         printf("%% "); break;
//                     default: 
//                         text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//                         printf("? "); break;
//                 }
//                 //revenir au blanc après chaque case
//                 text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//             }
//         }
//         printf("\n");
//     }
//     int curseurX = colonneCurseur () *2 + 2;
//     int curseurY = ligneCurseur () + 1;
//     gotoxy (curseurX - 1, curseurY);
//     printf(">");
//     gotoxy (curseurX + 1, curseur);
//     printf("<");
// }

// void afficherCoupsRestants(int coups_restants)
// {
//     gotoxy(COLONNE_INFO, 9);
//     printf("Coups restants : %d\n", coups_restants);
// }

    
// void afficherItemsRestants(int compteur_contrats[]) {
//     gotoxy(COLONNE_INFO, 0);
//     printf("Contrat :");
//     gotoxy(COLONNE_INFO, 1);
//     printf("X : %d\n", compteur_contrats[1]);
//     gotoxy(COLONNE_INFO, 2);
//     printf("O : %d\n", compteur_contrats[2]);
//     gotoxy(COLONNE_INFO, 3);
//     printf("& : %d\n", compteur_contrats[3]);
//     gotoxy(COLONNE_INFO, 4);
//     printf("@ : %d\n", compteur_contrats[4]);
//     gotoxy(COLONNE_INFO, 5);
//     printf("%% : %d\n", compteur_contrats[5]);
// }


//*********************NOUVELLE VERSION****************************//

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "affichage.h"
#include "gestionClavier.h"

#define HAUTEUR 10
#define LARGEUR 9
#define COLONNE_INFO (LARGEUR * 2 + 6) //chaque case fait deux caractères, +6 permet l'espace entre la grille et les infos
#define LIGNE_CONTRAT 1
#define LIGNE_NIVEAU  8
#define LIGNE_COUPS   10
#define LIGNE_TEMPS   12
#define LIGNE_VIES    14

/* =================== OUTILS CONSOLE =================== */

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
    gotoxy(COLONNE_INFO, 7);
    printf("Niveau : %d", niveau);
}

void afficherNombredeVies(int vies_restantes) {
    gotoxy(COLONNE_INFO, LIGNE_VIES);
    printf("Vies  : %d  ", vies_restantes);
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
    printf("Le but du jeu est d'eliminer le plus d'items possible lors d'un niveau. Il y a 3 niveaux par partie, pour chaque niveau, l'utilisateur doit repondre a un contrat lui indiquant le nombre d'items a eliminer et le temps imparti.\n");
    printf("Pour vous deplacer dans la grille de jeu, utilisez les touches suivantes : \n");
    printf("  z : haut\n");
    printf("  s : bas\n");
    printf("  q : gauche\n");
    printf("  d : droite\n");
    printf("Appuyez sur shift pour selectionner un item.\n");
    printf("Chaque niveau peut etre sauvegarde avec un pseudo utilisateur, afin d'y retourner plus tard.\n");
    printf("A vous de jouer !\n");
    printf("\nAppuyez sur une touche pour revenir au menu :)");
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
    printf("%% : %d  a", items[5]);
    gotoxy(0,15); // pour printf debug
}
