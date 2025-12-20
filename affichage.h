#define HAUTEUR 10
#define LARGEUR 9
void afficherNumeroNiveau(int niveau); //afficher le numero du niveau (1 2 ou 3)
void afficherNombredeVies(int vies_restantes); //afficher le nombre de vies restantes du joueur à tout moment
void afficherTempsRestant(int temps_restant); //afficher le temps restant pour chaque niveau en seconde
void afficherRegles(); //afficher les règles du jeu lorsque souhaité par l'utilisateur
void afficherGrille (int grille[HAUTEUR][LARGEUR]); //afficher la grille de jeu dans la hauteur et la largeur sont constantes
void afficherCoupsRestants(int coups_restants); //afficher le nombre de coups restants à chaque moment 
void afficherItemsRestants(int itemsRestants[]); //afficher le nombre d'items restants à éliminer pour chque contrat



//*********************NOUVELLE VERSION****************************//
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <windows.h>

/* Dimensions de la grille */
#define HAUTEUR 12
#define LARGEUR 11

/* ============== VARIABLES ==================*/

extern int temps_restant;

/* =================== OUTILS CONSOLE =================== */

/* Déplace le curseur de la console */
void gotoxy(int x, int y);

/* Change la couleur du texte */
void text_color(int color);

/* =================== AFFICHAGE JEU =================== */

/* Affiche la grille de jeu */
void afficherGrille(int grille[HAUTEUR][LARGEUR]);

/* Affiche le numéro du niveau */
void afficherNumeroNiveau(int niveau);

/* Affiche le nombre de vies restantes */
void afficherNombredeVies(int vies_restantes);

/* Affiche le nombre de coups restants */
void afficherCoupsRestants(int coups_restants);

/* Affiche le temps restant (en secondes) */
void afficherTempsRestant(int temps_restant);

/* Affiche les règles du jeu */
void afficherRegles(void);

/* Affiche le contrat (items restants à éliminer) */
void afficherItemsRestants(int items[]);

#endif
