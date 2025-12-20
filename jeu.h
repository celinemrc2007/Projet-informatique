
void viderGrille ();
void assurerGrilleJouable ();
int verifierAbsencesFiduresInitiales ();
void appliquerGravite ();
void melangerItems ();
int jeu ();
void genererItems();
int gererContrat();







//*******************************NOUVELLE VERSION**********************//
#ifndef JEU_H
#define JEU_H

#define HAUTEUR 12
#define LARGEUR 11
#define PAS_DE_FIGURE 0
#define SUITE_LIGNE 1
#define SUITE_COLONNE 2
#define CARRE 3
#define CROIX 4
#define TAILLE_CARRE 4
#define TAILLE_CROIX 5

/* ========================== VARIABLES =======================*/

extern int grille[HAUTEUR][LARGEUR];
extern int compteurs_contrat[7];
extern int coups_restants;
extern int malusRouge[HAUTEUR][LARGEUR];

/* ========================== STRUCTURE =========================*/
typedef struct {
    int type;
    int ligne;
    int colonne;
    int taille;
} ResultatFigure;

/* ========================== OUTILS ====================*/

/* Vide le contenu de la grille de jeu */
void viderGrille(void);

/* Génèrer des items aléatoirement */
void genererItems(void);

/* Vide le contenu d'une case de jeu */
void viderCase(int i, int j);

/* ====================== CONTRAT ================*/

/* Gère l'avancement du contrat */
int gererContrat(void);

/* ============== DETECTION / ELIMINATION ============== */

/* Detecte une suite en ligne  d'au moins 3 items */
ResultatFigure detecterSuiteEnLigne(void);

/* Detecte une suite en colone d'au moin 3 items */
ResultatFigure detecterSuiteEnColonne(void);

/* Detecte un carré de 4 items de côté */
ResultatFigure detecterCarre(void);

/* Detecte une croix de 5 items par branche */
ResultatFigure detecterCroix(void);

/* Regroupe toutes les detections */
ResultatFigure detecterFigure(void);

/* Elimine suite en ligne */
void eliminerSuiteEnLigne(ResultatFigure resultatL);

/* Elimine suite en colonne */
void eliminerSuiteEnColonne(ResultatFigure resultatC);

/* Elimine carré */
void eliminerCarre(ResultatFigure resultatCr);

/* Elimine croix*/
void eliminerCroix(ResultatFigure resultatCx);

/* Elimine la bonne figure selon les combinaisons sur la grille de jeu */
void eliminerFigure(ResultatFigure resultatglobal);

/* ================= GRAVITE ================*/

/* Assure que la ligne est vide */
bool ligneNonPleine(int ligne);

/* Fait tomber les items du haut */
void appliquerGravite(void);

/* Assure qu'il n'y a pas de figure initiale */
void assurerAbsencesFiguresInitiales ();

/* ================ GRILLE JOUABLE =============*/

/* Verifie si la grille est jouable */
bool verifierGrilleJouable();
void assurerGrilleJouable();

/* ================== PERMUTATION =============*/

/* Permute l'emplacement des items */
void permuterItems(int l1, int c1, int l2, int c2);

/* Assure que la permutation soit valide */
int permuterSiValide(int l1, int c1, int l2, int c2);

/* Melange les items de manière aléatoire */
void melangerItems(void);

/* =================== BOUCLE DE JEU =============== */

/* Organise le déroulement du jeu pour chaque niveau */
int jeu(void);





#endif

