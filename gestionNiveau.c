#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#include "affichage.h"
#include "gestionNiveau.h"
#include "jeu.h"
#include "sauvegarde.h"

#define ITEM_X 1
#define ITEM_O 2
#define ITEM_ET 3
#define ITEM_AROBASE 4
#define ITEM_POURCENT 5


/* ================= VARIABLES GLOBALES ================= */

int niveau = 1;                 // niveau courant
int vies_restantes = 3;
char pseudo[MAX_PSEUDO];
static int *copie_contrat = NULL; // pointeur vers le contrat courant

/* ================= PERMET DE PASSER LE PARAMETRE NIVEAU A CERTAINES SOUS-PROGRAMMES ================= */

int get_niveau(void) {
    return niveau;
}

/* ================= LANCEMENT NIVEAU ================= */

void lancerNiveau(int compteurs_contrat[7]) {
    system("cls");
    copie_contrat = compteurs_contrat;

    /* Initialisation du contrat selon le niveau */
    for (int i = 1; i <= 5; i++)
        compteurs_contrat[i] = 0;

    switch (niveau) {
        case 1:
            compteurs_contrat[ITEM_X] = 15;
            compteurs_contrat[ITEM_AROBASE] = 20;
            compteurs_contrat[ITEM_POURCENT] = 15;
            compteurs_contrat[ITEM_O] = 20;
            coups_restants = 20;
            temps_restant = 120; //2 min
            break;

        case 2:
            compteurs_contrat[ITEM_X] = 25;
            compteurs_contrat[ITEM_O] = 20;
            compteurs_contrat[ITEM_POURCENT] = 20;
            compteurs_contrat[ITEM_ET] = 25;
            coups_restants = 30;
            temps_restant = 105; //1 min 45
            break;

        case 3:
            compteurs_contrat[ITEM_X] = 30;
            compteurs_contrat[ITEM_O] = 20;
            compteurs_contrat[ITEM_POURCENT] = 20;
            compteurs_contrat[ITEM_ET] = 30;
            coups_restants = 30;
            temps_restant = 90; //1 min 30
            break;
    }

    afficherNumeroNiveau(niveau);
    int resultat_jeu = jeu();
    if(resultat_jeu==1) {
        gererVictoireNiveau ();
    }
    else {
        gererEchecNiveau();
    }
}

/* ================= GESTION VIES ================= */

void gererPerteVies() {
    if (vies_restantes > 0) {
        (vies_restantes)--;
        sauvegarderPartie (pseudo, niveau, vies_restantes);
    }

}

/* ================= VICTOIRE NIVEAU ================= */

void gererVictoireNiveau() {
    system("cls");
    if (niveau == 3) {
        gererVictoirePartie();
    } else {
        printf("###############################################\n");
        printf("#                                             #\n");
        printf("#   Bravo ! Vous avez gagne le niveau !       #\n");
        printf("#                                             #\n");
        printf("###############################################\n");

        Sleep(3000);
        niveau++;
        sauvegarderPartie (pseudo, niveau, vies_restantes);
        lancerNiveau(copie_contrat);
    }
}

/* ================= ECHEC NIVEAU ================= */

void gererEchecNiveau() {
    gererPerteVies();
    if (vies_restantes == 0) {
        gererEchecPartie();
    } else {
        system("cls");
        printf("###############################################\n");
        printf("#                                             #\n");
        printf("#   Dommage, niveau perdu...                  #\n");
        printf("#                                             #\n");
        printf("###############################################\n");

        Sleep(3000);

        //Demande à l'utilisateur s'il souhaite retenter le niveau ou quitter le programme
        char choix;
        printf("\nIl vous reste %d vie(s).\n", vies_restantes);      
        printf("Relancer le niveau ? (O/N) \n");
        printf("Saisir O pour oui. Saisir N pour non.");
        while(!_kbhit()) { Sleep(20); }
        choix = _getch();
        if (choix == 'O' || choix == 'o'){
            lancerNiveau(copie_contrat);
        }
    }
}

/* ================= VICTOIRE PARTIE ================= */

void gererVictoirePartie() {
    system("cls");
    printf("\n\n");
    printf("#############################################\n");
    printf("#                                           #\n");
    printf("#   FELICITATIONS !                         #\n");
    printf("#   Vous avez termine le JEU !              #\n");
    printf("#                                           #\n");
    printf("#############################################\n");
    Sleep(5000);
}

/* ================= ECHEC PARTIE ================= */

void gererEchecPartie() {
    system("cls");
    printf("###############################################\n");
    printf("#                                             #\n");
    printf("#                  GAME OVER !                #\n");
    printf("#                                             #\n");
    printf("###############################################\n");
    Sleep(3000);
}

/* ================= BONUS NIVEAU 3 ================= */

void gererBonusNiveau3(ResultatFigure fig) {

    if (niveau==3 && fig.taille == 5) {

        coups_restants += 5;

        if (coups_restants > 99)
            coups_restants = 99;
    }
}
