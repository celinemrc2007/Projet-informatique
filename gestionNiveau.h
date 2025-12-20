
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
#include "sauvegarde.h"

/* ===== VARIABLES ===== */

extern char pseudo[MAX_PSEUDO];
extern int niveau;
extern int vies_restantes; 

/* ===== FONCTIONS ===== */

int get_niveau(void);

/* Initialise le contrar en fonction du niveau joué, lance le jeu */
void lancerNiveau(int compteurs_contrat[7]);

/* Gère la gestion de la perte de vie */
void gererPerteVies();

/* Gère lorsque le joueur gagne un niveau */
void gererVictoireNiveau();

/* Gère lorsque le joueur perd un niveau */
void gererEchecNiveau();

/* Gère lorsque le joueur gagne la partie */
void gererVictoirePartie();

/* Gère lorsque le joueur perd la partie */
void gererEchecPartie();

/* Assure la mise en place du bonus au niveau 3 */
void gererBonusNiveau3(ResultatFigure fig);

#endif
