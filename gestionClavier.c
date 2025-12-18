#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define HAUTEUR 10
#define LARGEUR 9

//variables globales 
int curseurL = HAUTEUR/2;
int curseurC = LARGEUR/2;

int ligneCurseur() { return curseurL; }
int colonneCurseur() { return curseurC; }

// Retourne true si le joueur essaie d'échanger 2 items
bool selectionItem (char touche, int *l1, int *c1, int *l2, int *c2) {
    *l1 = curseurL;
    *c1 = curseurC;
    *l2 = curseurL;
    *c2 = curseurC;
    switch(touche){
        case 'Q': // gauche
            if (curseurC > 0) {
                *c2--;
                return true;
            }
            break;
        case 'S': // droite
            if (curseurC < LARGEUR - 1) {
                *c2++;
                return true;
            }
            break;
        case 'Z': // haut
            if (curseurL > 0) {
                *l2--;
                return true;
            }
            break;
        case 'W': // bas
            if (curseurL < HAUTEUR - 1) {               
                *l2++;
                return true;
            }
            break;
    }
    return false;
}


void deplacementTouches(char touche){
    switch(touche){
        case 'q': // gauche
            if (curseurC > 0)
                curseurC--;
            break;

        case 's': // droite
            if (curseurC < LARGEUR - 1)
                curseurC++;
            break;

        case 'z': // haut
            if (curseurL > 0)
                curseurL--;
            break;

        case 'w': // bas
            if (curseurL < HAUTEUR - 1)
                curseurL++;
            break;
    }
}
