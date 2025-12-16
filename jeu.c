#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> 

#define HAUTEUR 10
#define LARGEUR 9
#define DUREE 120000
#define PAS_DE_FIGURE 0
#define SUITE_LIGNE 1
#define SUITE_COLONNE 2
#define CARRE 3
#define CROIX 4
#define TAILLE_CARRE 4
#define TAILLE_CROIX 5
#define TAILLE_BONUS_COUPS 5         //Ajout par nous
#define TAILLE_BONUS_EXPLOSION 6     //Bonus imposé par la consigne

char grille[HAUTEUR][LARGEUR];		//Déclaration de la variable globale grille (matrice de taille HAUTEUR*LARGEUR) utilisé dans la majorité des sous-programme de ce module
								  //Valeurs de 1 à 6 (5 items + malus) remplacés dans GenererItems par des symboles
typedef struct {
    int trouve;     // 0 = aucune figure, 1 = figure trouvée
    int ligne;
    int colonne;
    int taille;
	int type;	  //SUITE_LIGNE, SUITE_COLONNE, CARRE, CROIX
} ResultatFigure; //structure à utiliser pour eliminer une figure

void viderGrille() {
	for (int i=0; i<HAUTEUR; i++) {
		for (int j=0; j<LARGEUR; j++) {
			grille[i][j] = 0;
		}
	}
}

int verifierAbsencesFiduresInitiales () {
	if(detecterFigure != PAS_DE_FIGURE) {
		return 1;
	}
}

ResultatFigure detecterSuiteEnLigne(char grille[HAUTEUR][LARGEUR]){
    int i, j;
    ResultatFigure resultatL = {0, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
    //boucle for pour parcourir les lignes donc la hauteur
    for(i=0; i<HAUTEUR; i++){
        int compteur = 1; //sert à mesurer la longueur d’une suite d’items identiques consécutifs. s'incrémente quand deux cases consécutives sont égales
        //boucle for pour parcourir les colonnes donc la largeur
        for(j=1; j<LARGEUR; j++){
            if(grille[i][j]==grille[i][j-1] && grille[i][j] != ' '){ //comparaison de deux cases consécutives
                compteur++;
    
                if(compteur>=3){ //on a une suite valide si elle fait au moins 3 cases
                    resultatL.trouve = 1;
                    resultatL.ligne = i; //on veut le numero de la ligne où se trouve la suite
                    resultatL.colonne = j - compteur + 1;//on veut le numero de la première colonne où commence la suite
                    resultatL.taille = compteur; //taille de la suite (3, 4, 5 ou 6)
					resultatL.type = SUITE_LIGNE;
                    return resultatL;
                }
            }else compteur = 1; // reinitialisation
        }
    }
    return resultatL; //aucune suite trouvée
}


void eliminerSuiteEnLigne(resultatL) { 
	for (int i=0; i<taille; i++) {                      
		grille[resultatL.ligne][resultatL.colonne + i] = ' '; //Parcourir les cases de la suite de gauche à droite
	}	
}

ResultatFigure detecterSuiteEnColonne(char grille[HAUTEUR][LARGEUR]){
    int i, j;
    ResultatFigure resultatC = {0, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
    //boucle for pour parcourir les colonnes donc la largeur
    for(j=0; j<LARGEUR; j++){
        int compteur = 1; //sert à mesurer la longueur d’une suite d’items identiques consécutifs. s'incrémente quand deux cases consécutives sont égales
        //boucle for pour parcourir les lignes donc la hauteur
        for(i=1; i<HAUTEUR; i++){
            if(grille[i][j]==grille[i-1][j] && grille[i][j] != ' '){ //comparaison de deux cases consécutives
                compteur++;

                if(compteur>=3){//on a une suite valide si elle fait au moins 3 cases
                    resultatC.trouve = 1;
                    resultatC.ligne = i-compteur + 1; //on veut le numero de la première ligne où commence la suite
                    resultatC.colonne = j;
                    resultatC.taille = compteur; //taille de la suite (3, 4, 5 ou 6)
					resultatL.type = SUITE_COLONNE;
                    return resultatC;
                }
            }else compteur = 1; //reinitialisation si les deux cases consécutives ne sont pas identiques
        }
    }
    return resultatC; //aucune suite trouvée
}

void eliminerSuiteEnColonne(resultatC) { 
	for (int i=0; i<taille; i++) {
		grille[resultatC.ligne + i][resultatC.colonne] = 0; //Parcourir les cases de la suite de haut en bas et affecter 0 à chacune de ces cases
	}	
}




void eliminerCarre (resultatL, resultatC) {
	for (int i=0; i<TAILLE_CARRE; i++) {
		grille[resultatL.ligne][resultatL.colonne + i] = 0;                 //Parcourir la ligne la plus haute du carre de gauche à droite et affecter 0 à chacune de ces cases
		grille[ligne+TAILLE_CARRE-1][colonne + i] = 0;  //Parcourir la ligne la plus basse du carre de gauche à droite et affecter 0 à chacune de ces cases
	}	
	for (int i=0; i<TAILLE_CARRE; i++) {
		grille[resultatC.ligne + i][resultatC.colonne] = 0;                 //Parcourir la ligne la plus à gauche du carre de haut en bas en affectant 0 à chacune de ces cases
		grille[resultatC.ligne + i][resultatC.colonne+TAILLE_CARRE-1] = 0;  //Parcourir la ligne la plus à droite du carre de haut en bas en affectant 0 à chacune de ces cases
	}
}


ResultatFigure detecterCroix(char grille[HAUTEUR][LARGEUR]){
    int i, j;
    Centrecroix resultatCx = {0, -1, -1}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
    //boucle for pour parcourir les lignes donc la hauteur
    for(i=2; i<HAUTEUR-2; i++){ //au minimum le centre de la croix se trouve à la ligne 2
        //boucle for pour parcourir les colonnes donc la largeur
        for(j=2; j<LARGEUR-2; j++){ //au minimum le centre de la croix se trouve à la colonne 2

            char c = grille[i][j]; //enregistrement du type d'item dans la variable c
            if(c==' ') continue; //si la case est vide, on continue de chercher dans la grille

            if(grille[i][j]== c && grille[i-1][j]== c && grille[i-2][j]== c && grille[i+1][j]== c && grille[i+2][j]== c && grille[i][j-1]== c && grille[i][j-2]== c && grille[i][j+1]== c && grille[i][j+2]== c){
                resultatCx.trouve = 1;
                resultatCx.ligne = i; //ligne où se trouve la case centrale de la croix
                resultatCx.colonne = j; //colonne où se trouve la case centrale de la croix
				resultatCx.type = CROIX; 
                return resultatCx;
            }
        }
    }
    return resultatCx; //aucune croix trouvée
}

void eliminerCroix (resultatL, resultatC) { //utilise resultatCx
	for (int i=0; i<TAILLE_CROIX; i++) {
		grille[resultatL.ligne][resultatL.colonne + i - 2] = 0;				//Se placer au centre de la croix, aller 2 cases vers la gauche et parcourir les cases de gauche à droite en affectant 0 à chacune de ces cases
	}	
	for (int i=0; i<TAILLE_CROIX; i++) {
		grille[resultatC.ligne + i - 2][resultatC.colonne] = 0;				//Se placer au centre de la croix, aller 2 cases vers la haut et parcourir les cases haut en bas en affectant 0 à chacune de ces cases
	}	
}

void eliminerFigure (resultatL, resultatC) {			//Elimine la fonction adéquate en fonction du type de la figure 
	switch(resultat.type) {															
	case SUITE_LIGNE : eliminerSuiteEnLigne (resultatL);
		break;
	case SUITE_COLONNE : eliminerSuiteEnColonne (resultatC);
		break;
	case CARRE : eliminerCarre(resultatL, resultatC);
		break;
	case CROIX : eliminerCroix (resultatL, resultatC);
		break;
	}
}

void appliquerGravite () {


}

void assurerGrilleJouable () {
	
}

melangerItems() {									//Echange les coordonnées de deux items choisis aléatoirement
	int l1, int c1, int l2, int c2, int temp;
	l1 = rand() % HAUTEUR;
	l2 = rand() % HAUTEUR;
	c1 = rand() % LARGEUR;
	c2 = rand() % LARGEUR;

	temp = grille[l1][c1];							
	grille[l1][c1] = grille[l2][c2];				
	grille[l2][c2] = temp;
}


int jeu (int temps_restant) {
	int type, int ligne, int colonne, int taille;
	int touche_pressee;

	srand(time(NULL));
	 do {
	 		printf("Il y a deja des combinaisons possibles. Melange en cours ...");
			melangerItems();	
	} while (verifierAbsencesFiduresInitiales==1);	
	
	deplacementTouches(touche_pressee);
	selectionItems(touche_pressee);
	appliquerGravite();
	detecterSuiteEnLigne();
	eliminerSuiteEnLigne(ligne, colonne, taille);
	detecterSuiteEnColonne();
	eliminerSuiteEnColonne(ligne, colonne, taille);
	detecterCroix();
	eliminerCroix(ligne, colonne);
	detecterCarre();
	eliminerCarre(ligne, colonne);
	decterFigure();
	eliminerFigure(type_items, ligne, colonne, taille);

	if (gererContrat==1) {
		gererVictoireNiveau(duree, temps_restant);
	}
	if (temps_restant==0&&gererContrat!=1) {
		gererPerteVies(vies);
		gererEchecNiveau(vies);
	}
}

