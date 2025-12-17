#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define HAUTEUR 10
#define LARGEUR 9
//X : 1                       O : 2                         & : 3                        @ : 4                  % : 5              malus : 6

void afficherNumeroNiveau(int niveau){ //afficher le numero du niveau (1 2 ou 3)
    gotoxy(0, 1); //position ligne 1
    printf("Niveau actuel : %d\n", niveau);
} 


void afficherNombredeVies(int nb_vies_restantes){
    printf("Vies restantes : %d\n", nb_vies_restantes);
}

void afficherTempsrestant(int tempsrestant){ //afficher le temps restant pour chaque niveau en seconde
    while(tempsrestant>=0){
        int minutes = tempsrestant / 60;
        int secondes = tempsrestant %60;
        gotoxy(0, 2); //position ligne 2
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

void afficherCadre(char grille[HAUTEUR][LARGEUR]) {
    gotoxy(0,0);
    text_color(FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN); //les # seront blancs
    
    for (int y = 0; y <= HAUTEUR+1; y++) { //boucle pour parcourir les lignes 
        for (int x = 0; x <= LARGEUR+1; x++) { //boucle pour parcourir les colonnes
            printf("%c ", grille[i][j]);
            if (y == 0 || y == HAUTEUR+1) printf("#");
            else if (x == 0 || x == LARGEUR+1) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
    int item;
    switch(item){
        case 0 : printf(" ");
        case 1 : printf("X"); 
        case 2 : printf("O");
        case 3 : printf("&");
        case 4 : printf("@");
        case 5 : printf("%");
        break;
    }
}


void afficherCoupsRestants(int coups)
{
    printf("Coups restants : %d\n", coups);
}

    
void afficherItemsRestants(int x, int o, int et, int at, int pourcent)
{
    printf("Items restants :\n");
    printf("X : %d\n", x);
    printf("O : %d\n", o);
    printf("& : %d\n", et);
    printf("@ : %d\n", at);
    printf("%% : %d\n", pourcent);
}

}
