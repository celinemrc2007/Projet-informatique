#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define HAUTEUR 10
#define LARGEUR 9
#define COLONNE_INFO (LARGEUR * 2 + 10)

//X : 1                       O : 2                         & : 3                        @ : 4                  % : 5              malus : 6
char grille[HAUTEUR][LARGEUR]; //variable globale

void afficherNumeroNiveau(int niveau){ //afficher le numero du niveau (1 2 ou 3)
    gotoxy(5, HAUTEUR + 2); //position ligne 1
    printf("Niveau actuel : %d\n", niveau);
} 


void afficherNombredeVies(int nb_vies_restantes){
    gotoxy(COLONNE_INFO, 11);
    printf("Vies restantes : %d\n", nb_vies_restantes);
}

void afficherTempsrestant(int tempsrestant){ //afficher le temps restant pour chaque niveau en seconde
    while(tempsrestant>=0){
        int minutes = tempsrestant / 60;
        int secondes = tempsrestant %60;
        gotoxy(COLONNE_INFO, 7); //position ligne 2
        printf("Temps restant : %02d:%02d\n", minutes, secondes); //affichage du temps restant avec deux chiffres pour minutes et secondes
        Sleep(1000); //attendre 1 sec
        tempsrestant--;
    }
    printf("\nLe temps est termine !\n");
}

void afficherRegles(){
    gotoxy(0, 3); //position ligne 3
    printf("======= Regles du jeu =======\n");
    printf("Le but du jeu est d'eliminer le plus d'items possible lors d'un niveau. Il y a 3 niveaux par partie, pour chaque niveau, l'utilisateur doit repondre à un contrat lui indiquant le nombre d'items a eliminer et le temps imparti.\n");
    printf("Chaque niveau peut etre sauvegarde avec un pseudo utilisateur, afin d'y retourner plus tard.\n");
    printf("A vous de jouer !\n");
}

void afficherGrille(){
    int y, x;

    gotoxy(0, 0);

    for (y = 0; y < HAUTEUR + 2; y++) {
        for (x = 0; x < LARGEUR + 2; x++) {

            // Bordures
            if (y == 0 || y == HAUTEUR + 1 || x == 0 || x == LARGEUR + 1) {
                text_color(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
                printf("#");
            }
            //Intérieur : affichage de la grille
            else {
                int item = grille[y-1][x-1]; //la grille commence à partir de (1,1)

                switch (item) {
                    case 0: 
                        printf("  "); break;
                    case 1: //rouge
                        text_color(FOREGROUND_RED);
                        printf("X "); break;
                    case 2: //bleu
                        text_color(FOREGROUND_BLUE);
                        printf("O "); break;
                    case 3: //vert
                        text_color(FOREGROUND_GREEN);
                        printf("& "); break;
                    case 4: //jaune
                        text_color(FOREGROUND_RED | FOREGROUND_GREEN)
                        printf("@ "); break;
                    case 5: //magenta
                        text_color(FOREGROUND_RED | FOREGROUND_BLUE);
                        printf("% "); break;
                    default: 
                        text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        printf("? "); break;
                }
                //revenir au blanc après chaque case
                text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
        }
        printf("\n");
    }
}



void afficherCoupsRestants(int coups) //a refaire
{
    gotoxy(COLONNE_INFO, 9);
    printf("Coups restants : %d\n", coups);
}

    
void afficherItemsRestants(int compteur_contrats[]) {
    gotoxy(COLONNE_INFO, 0);
    printf("Contrat :");
    gotoxy(colonne, 1);
    printf("X : %d\n", compteur_contrats[1]);
    gotoxy(colonne, 2);
    printf("O : %d\n", compteur_contrats[2]);
    gotoxy(colonne, 3);
    printf("& : %d\n", compteur_contrats[3]);
    gotoxy(colonne, 4);
    printf("@ : %d\n", compteur_contrats[4]);
    gotoxy(colonne, 5);
    printf("%% : %d\n", compteur_contrats[5]);
}

