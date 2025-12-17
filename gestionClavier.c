#include <stdio.h>
//variables globales 
int curseurL = 0;
int curseurC = 0;

int selectionActive = 0;
int selL, selC;

void selectionItem(char touche){
    int l2 = curseurL;
    int c2 = curseurC;

    // Si aucune sélection active → on sélectionne
    if (!selectionActive && touche == ' '){ // espace ou shift selon ton choix
        selectionActive = 1;
        selL = curseurL;
        selC = curseurC;
        return;
    }

    // Si un item est déjà sélectionné
    if (selectionActive){
        switch(touche){
            case 'q': c2--; break; // gauche
            case 's': c2++; break; // droite
            case 'z': l2--; break; // haut
            case 'w': l2++; break; // bas
            default: return;
        }

        // Vérification limites
        if (l2 < 0 || l2 >= HAUTEUR || c2 < 0 || c2 >= LARGEUR){
            selectionActive = 0;
            return;
        }

        // Tentative de permutation
        if (permuterSiValide(selL, selC, l2, c2)){
            // permutation valide → coups -1, élimination ensuite
        }

        // Dans tous les cas, on annule la sélection
        selectionActive = 0;
    }
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
