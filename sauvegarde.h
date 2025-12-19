#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H


#define MAX_PSEUDO 50
#define FICHIER_SAUVEGARDE "sauvegarde.txt"


/* Sauvegarde le pseudo, le dernier niveau gagné et les vies restantes */
void sauvegarderPartie(const char *pseudo, int niveau, int vies);


/* Charge une sauvegarde existante
Retourne 1 si trouvée, 0 sinon */
int chargerPartie(const char *pseudo, int *niveau, int *vies);


/* Vérifie si un pseudo existe déjà */
int pseudoExiste(const char *pseudo);


#endif
