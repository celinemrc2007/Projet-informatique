#ifndef GESTION_CLAVIER_H
#define GESTION_CLAVIER_H

#include <stdbool.h>

/* Curseur partagé avec affichage.c */
extern int curseurL;
extern int curseurC;

/* Accès curseur pour affichage */
int ligneCurseur(void);
int colonneCurseur(void);

/* Gestion clavier */
void deplacementTouches(char touche);

/* Sélection / tentative de permutation */
bool selectionItem(char touche, int *l1, int *c1, int *l2, int *c2);

#endif
