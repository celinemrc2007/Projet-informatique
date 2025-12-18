#define HAUTEUR 10
#define LARGEUR 9
void afficherNumeroNiveau(int niveau); //afficher le numero du niveau (1 2 ou 3)
void afficherNombredeVies(int vies_restantes); //afficher le nombre de vies restantes du joueur à tout moment
void afficherTempsRestant(int temps_restant); //afficher le temps restant pour chaque niveau en seconde
void afficherRegles(); //afficher les règles du jeu lorsque souhaité par l'utilisateur
void afficherGrille (int grille[HAUTEUR][LARGEUR]); //afficher la grille de jeu dans la hauteur et la largeur sont constantes
void afficherCoupsRestants(int coups_restants); //afficher le nombre de coups restants à chaque moment 
void afficherItemsRestants(int itemsRestants[]); //afficher le nombre d'items restants à éliminer pour chque contrat
