#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> 
#define HAUTEUR 10
#define LARGEUR 9
#define DUREE 120000
int niveau=1;

void lancerNiveau(int xcurseur, int ycurseur, int temps_restant) {
	xcurseur=LARGEUR/2;
	ycurseur=HAUTEUR/2;
	jeu(temps_restant);
	viderGrille();
	genererItems();
	assurerGrilleJouable();
	afficherGrille();
	afficherNumeroDuNiveau(niveau);
	afficherNombreDeVies(vies);
	afficherTempsRestants(temps_fin, temps_restant);
	afficherCoupsRestants(coups_restants);
	afficherRegles();
	afficherItemsRestants(type_items);

	switch(niveau) {
		case 1: printf("");			//Afficher 1e contrat du niveau 1
			break;
		case 2: printf("");			//Afficher le contrat du niveau 2
			malus(ligne, colonne);	//Ajout du malus au niveau 2
			break;
		case 3: printf("");			//Afficher le contrat du niveau 3
			malus(ligne, colonne);	//Ajout du malus au niveau 3
			break;

	}
}

void gerePerteVies(int *nb_vies_restantes){
    if (*nb_vies_restantes > 0) {
        (*nb_vies_restantes)--; //utilisateur perd une vie s'il lui en reste
    }
}
void genererItems(char grille[10][9])
{
    char items[5] = {'X','O','&','@','%'};
    int i, j;

    srand(time(NULL));

    for (i = 0; i < 10; i++)
        for (j = 0; j < 9; j++)
            grille[i][j] = items[rand() % 7];
}

void gererContrat(char item, int *x, int *o, int *et, int *at, int *pourcent)
{
    if (item == 'X' && *x > 0) (*x)--;
    if (item == 'O' && *o > 0) (*o)--;
    if (item == '&' && *et > 0) (*et)--;
    if (item == '@' && *at > 0) (*at)--;
    if (item == '%' && *pourcent > 0) (*pourcent)--;
}	

