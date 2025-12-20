
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

#define HAUTEUR 10
#define LARGEUR 9
#define PAS_DE_FIGURE 0
#define SUITE_LIGNE 1
#define SUITE_COLONNE 2
#define CARRE 3
#define CROIX 4
#define TAILLE_CARRE 4
#define TAILLE_CROIX 5

typedef struct {
    int type;
    int ligne;
    int colonne;
    int taille;
} ResultatFigure;

// prototypes
void viderGrille(void);
void genererItems(void);
void viderCase(int i, int j);
int gererContrat(void);
ResultatFigure detecterSuiteEnLigne(void);
ResultatFigure detecterSuiteEnColonne(void);
ResultatFigure detecterCarre(void);
ResultatFigure detecterCroix(void);
ResultatFigure detecterFigure(void);
void eliminerSuiteEnLigne(ResultatFigure f);
void eliminerSuiteEnColonne(ResultatFigure f);
void eliminerCarre(ResultatFigure f);
void eliminerCroix(ResultatFigure f);
void eliminerFigure(ResultatFigure f);
void appliquerGravite(void);
void melangerItems(void);
int permuterSiValide(int l1, int c1, int l2, int c2);
void permuterItems(int l1, int c1, int l2, int c2);
int verifierAbsencesFiguresInitiales(void);
int jeu(void);
void placerMalus(int niveau);
void appliquerMalus(ResultatFigure fig, int *temps_restant);

extern int grille[HAUTEUR][LARGEUR];
extern int compteurs_contrat[7];
extern int coups_restants;
extern int temps_restants
extern int malusRouge[HAUTEUR][LARGEUR];

#endif

