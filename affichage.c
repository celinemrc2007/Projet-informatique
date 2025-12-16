#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define HAUTEUR 10
#define LARGEUR 9


void afficherNumeroNiveau(int niveau){ //afficher le numero du niveau (1 2 ou 3)
    gotoxy(0, 1); //position ligne 1
    printf("Niveau actuel : %d\n", niveau);
} 

void afficherNombredeVies(int *nb_vies_restantes){ //afficher le nombre de vies restantes du joueur à tout moment
    printf("Vies restantes : %d", *nb_vies_restantes);
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

void afficherGrille (char grille[HAUTEUR][LARGEUR]){
    int i, j;
//boucle pour parcourir les colonnes
    for(i=0; i<HAUTEUR; i++){
        //boucle pour parcourir les lignes
        for(j=0; j<LARGEUR; j++){
            printf("%c ", grille[i][j]); //affichage de la grille
        }
        printf("\n");
    }
}
