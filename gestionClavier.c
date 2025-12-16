#include <stdio.h>

void selectionItem(int *ligne, int *colonne)
{
    printf("Ligne : ");
    scanf("%d", ligne);
    printf("Colonne : ");
    scanf("%d", colonne);
}

void deplacementTouches(char touche, int *ligne, int *colonne)
{
    if (touche == 'z' && *ligne > 0) (*ligne)--;
    if (touche == 's' && *ligne < 9) (*ligne)++;
    if (touche == 'q' && *colonne > 0) (*colonne)--;
    if (touche == 'd' && *colonne < 8) (*colonne)++;
}
