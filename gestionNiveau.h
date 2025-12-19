// void lancerNiveau(int compteurs_contrat[7]); //appeler la fonction jeu et toutes les fonctions du module affichage
// //void bonus ();
// //void malus ();
// void gererVictoireNiveau ();
// void gererEchecNiveau (int *vies_restantes);
// void gererPerteVies(int *vies_restantes); //retirer une vie si le joueur a écoulé l'entièreté du temps ou des coups dont il disposait
// void gererVictoirePartie(int niveau);
// void gererEchecPartie(int *vies_restantes);
// void quitterProgramme();

//*********************NOUVELLE VERSION****************************//
#ifndef GESTION_NIVEAU_H
#define GESTION_NIVEAU_H

#include "jeu.h"

/* ===== VARIABLES ===== */

extern int niveau;

/* ===== FONCTIONS ===== */

int get_niveau(void);

void lancerNiveau(int compteurs_contrat[7]);

void gererPerteVies();

void gererVictoireNiveau(void);
void gererEchecNiveau();

void gererVictoirePartie(int niveau_final);
void gererEchecPartie();

void gererBonusNiveau3(ResultatFigure fig);

#endif
