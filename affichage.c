#include <stdio.h>
#include <windows.h>
#include <conio.h>

void afficherNumeroNiveau(int niveau){ //afficher le numero du niveau (1 2 ou 3)
    printf("Niveau actuel : %d\n", niveau);
} 

void afficherNombredeVies(int *nb_vies_restantes){ //afficher le nombre de vies restantes du joueur à tout moment
    printf("Vies restantes : %d", *nb_vies_restantes);
}

void afficherTempsrestant(int tempsrestant){ //afficher le temps restant pour chaque niveau en seconde
    while(tempsrestant>=0){
        int minutes = tempsrestant / 60;
        int secondes = tempsrestant %60;
        system("cls");  //effacer l'ecran à chaque seconde
        printf("Temps restant : %02d:%02d\n", minutes, secondes); //affichage du temps restant avec deux chiffres pour minutes et secondes
        Sleep(1000); //attendre 1 sec
        tempsrestant--;
    }
    printf("\nLe temps est termine !\n");
}

void afficherRegles(){
    printf("======= Regles du jeu =======\n");
    printf("Le but du jeu est d'éliminer le plus d'items possible lors d'un niveau. Il y a 3 niveaux par partie, pour chaque niveau, l'utilisateur doit répondre à un contrat luiindiquant le nombre d'items à éliminer et le temps imparti.\n");
    printf("Chaque niveau peut être sauvegardé avec un pseudo utilisateur, afin d'y retourner plus tard.\n");
    printf("A vous de jouer !\n");
}
