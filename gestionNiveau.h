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
