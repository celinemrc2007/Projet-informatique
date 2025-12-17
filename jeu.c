
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

char grille[HAUTEUR][LARGEUR];      //Déclaration de la variable globale grille (matrice de taille HAUTEUR*LARGEUR) utilisé dans la majorité des sous-programme de ce module
                                  //Valeurs de 0 à 6 (5 items + malus) remplacés dans GenererItems par des symboles
typedef struct {
    int type;     //SUITE_LIGNE (1), SUITE_COLONNE (2), CARRE (3), CROIX (4), PAS_DE_FIGURE (0)
    int ligne;
    int colonne;
    int taille;
} ResultatFigure; //structure à utiliser pour eliminer une figure

void viderGrille() {
    for (int i=0; i<HAUTEUR; i++) {
        for (int j=0; j<LARGEUR; j++) {
            grille[i][j] = 0;
        }
    }
}

int verifierAbsencesFiguresInitiales () {
    if(detecterFigure() != PAS_DE_FIGURE) {
        return 1;
    }
}
void genererItems(char grille[10][9])
{
    char items[5] = {'X','O','&','@','%'};
    int i, j;

    srand(time(NULL));

    for (i = 0; i < 10; i++)
        for (j = 0; j < 9; j++)
            grille[i][j] = items[rand() % 7];
}

void gererContrat(char item, int *x, int *o, int *et, int *at, int *pourcent)
{
    if (item == 'X' && *x > 0) (*x)--;
    if (item == 'O' && *o > 0) (*o)--;
    if (item == '&' && *et > 0) (*et)--;
    if (item == '@' && *at > 0) (*at)--;
    if (item == '%' && *pourcent > 0) (*pourcent)--;
}   

ResultatFigure detecterSuiteEnLigne(){
    int i, j;
    ResultatFigure resultatL = {0, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
    //boucle for pour parcourir les lignes donc la hauteur
    for(i=0; i<HAUTEUR; i++){
        int compteur = 1; //sert à mesurer la longueur d’une suite d’items identiques consécutifs. s'incrémente quand deux cases consécutives sont égales
        //boucle for pour parcourir les colonnes donc la largeur
        for(j=1; j<LARGEUR; j++){
            if(grille[i][j]==grille[i][j-1] && grille[i][j] != 0){ //comparaison de deux cases consécutives
                compteur++;

            } else {
                if(compteur>=3){ //on a une suite valide si elle fait au moins 3 cases
                    resultatL.type = 0; //type PAS_DE_FIGURE
                    resultatL.ligne = i; //on veut le numero de la ligne où se trouve la suite
                    resultatL.colonne = j - compteur + 1;//on veut le numero de la première colonne où commence la suite
                    resultatL.taille = compteur; //taille de la suite (3, 4, 5 ou 6)
                    return resultatL;
                }
                compteur = 1; // reinitialisation si les deux cases consécutives ne sont pas identiques
            }   
        }
    }
    return resultatL; //aucune suite trouvée
}


void eliminerSuiteEnLigne(ResultatFigure resultatL) { 
    for (int i=0; i<taille; i++) {                      
        grille[resultatL.ligne][resultatL.colonne + i] = 0; //Parcourir les cases de la suite de gauche à droite
    }   
}


ResultatFigure detecterSuiteEnColonne(){
    int i, j;
    ResultatFigure resultatC = {0, -1, -1, 0, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
    //boucle for pour parcourir les colonnes donc la largeur
    for(j=0; j<LARGEUR; j++){
        int compteur = 1; //sert à mesurer la longueur d’une suite d’items identiques consécutifs. s'incrémente quand deux cases consécutives sont égales
        //boucle for pour parcourir les lignes donc la hauteur
        for(i=1; i<HAUTEUR; i++){
            if(grille[i][j]==grille[i-1][j] && grille[i][j] != 0){ //comparaison de deux cases consécutives
                compteur++;

            } else {
                if(compteur>=3){//on a une suite valide si elle fait au moins 3 cases
                    resultatC.type = 2; //type SUITE_EN_COLONNE
                    resultatC.ligne = i-compteur + 1; //on veut le numero de la première ligne où commence la suite
                    resultatC.colonne = j;
                    resultatC.taille = compteur; //taille de la suite (3, 4, 5 ou 6)
                    return resultatC;
                }
                compteur = 1; //reinitialisation si les deux cases consécutives ne sont pas identiques
            }
        }
    }
    return resultatC; //aucune suite trouvée
}


void eliminerSuiteEnColonne(ResultatFigure resultatC) { 
    for (int i=0; i<taille; i++) {
        grille[resultatC.ligne + i][resultatC.colonne] = 0; //Parcourir les cases de la suite de haut en bas et affecter 0 à chacune de ces cases
    }   
}

ResultatFigure detecterCarre(){
    int i, j;
    ResultatFigure resultatCr = {0, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
    //boucle for pour parcourir les lignes donc la hauteur
    for(i=0; i<HAUTEUR-3; i++){
        //boucle for pour parcourir les colonnes donc la largeur
        for(j=0; j<LARGEUR-3; j++){

            int c = grille[i][j]; //enregistrement du type d'item en entier dans la variable c
            if(c==0) continue; //si la case est vide, on continue de chercher dans la grille

            if(grille[i][j]== c && grille[i+1][j]== c && grille[i+2][j]== c && grille[i+3][j]== c && grille[i+3][j+1]== c && grille[i+3][j+2]== c && grille[i+3][j+3]== c && grille[i][j+1]== c && grille[i][j+2]== c && grille[i][j+3]== c && grille[i+1][j+3]== c && grille[i+2][j+3]== c){
                resultatCr.type = 3; //type CARRE
                resultatCr.ligne = i; //ligne où se trouve la case en haut à gauche du carré
                resultatCr.colonne = j; //colonne où se trouve la case en haut à gauche du carré
                resultatCr.taille = 4; //le carré fait 4 items de côté
                return resultatCr;
            }
        }
    }
    return resultatCr; //aucun carré trouvé
}


void eliminerCarre (ResultatFigure resultatCr) { //utilise resultatCr
    for (int i=0; i<TAILLE_CARRE; i++) {
        grille[resultatCr.ligne][resultatCr.colonne + i] = 0;                 //Parcourir la ligne la plus haute du carre de gauche à droite et affecter 0 à chacune de ces cases
        grille[resultatCr.ligne+TAILLE_CARRE-1][resultatCr.colonne + i] = 0;  //Parcourir la ligne la plus basse du carre de gauche à droite et affecter 0 à chacune de ces cases
    }   
    for (int i=0; i<TAILLE_CARRE; i++) {
        grille[resultatCr.ligne + i][resultatCr.colonne] = 0;                 //Parcourir la ligne la plus à gauche du carre de haut en bas en affectant 0 à chacune de ces cases
        grille[resultatCr.ligne + i][resultatCr.colonne+TAILLE_CARRE-1] = 0;  //Parcourir la ligne la plus à droite du carre de haut en bas en affectant 0 à chacune de ces cases
    }
}


ResultatFigure detecterCroix(){
    int i, j;
    ResultatFigure resultatCx = {0, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
    //boucle for pour parcourir les lignes donc la hauteur
    for(i=2; i<HAUTEUR-2; i++){ //au minimum le centre de la croix se trouve à la ligne 2
        //boucle for pour parcourir les colonnes donc la largeur
        for(j=2; j<LARGEUR-2; j++){ //au minimum le centre de la croix se trouve à la colonne 2

            int c = grille[i][j]; //enregistrement du type d'item dans la variable c
            if(c==0) continue; //si la case est vide, on continue de chercher dans la grille

            if(grille[i][j]== c && grille[i-1][j]== c && grille[i-2][j]== c && grille[i+1][j]== c && grille[i+2][j]== c && grille[i][j-1]== c && grille[i][j-2]== c && grille[i][j+1]== c && grille[i][j+2]== c){
                resultatCx.type = 4;  //type CROIX
                resultatCx.ligne = i; //ligne où se trouve la case centrale de la croix
                resultatCx.colonne = j; //colonne où se trouve la case centrale de la croix
                resultatCx.taille = 5; //la croix fait 5 items par branche 
                return resultatCx;
            }
        }
    }
    return resultatCx; //aucune croix trouvée
}


void eliminerCroix (ResultatFigure resultatCx) { //utilise resultatCx
    for (int i=0; i<TAILLE_CROIX; i++) {
        grille[resultatCx.ligne][resultatCx.colonne + i - 2] = 0;               //Se placer au centre de la croix, aller 2 cases vers la gauche et parcourir les cases de gauche à droite en affectant 0 à chacune de ces cases
    }   
    for (int i=0; i<TAILLE_CROIX; i++) {
        grille[resultatCx.ligne + i - 2][resultatCx.colonne] = 0;               //Se placer au centre de la croix, aller 2 cases vers la haut et parcourir les cases haut en bas en affectant 0 à chacune de ces cases
    }   
}


ResultatFigure detecterFigure(){
    ResultatFigure resultatglobal;
    //Croix
    resultatglobal = detecterCroix(); //enregistrement resultatCx dans resultatglobal
    if (resultatglobal.type != 0) {  // Croix trouvée
        return resultatglobal;
    }
    //Carre
    resultatglobal = detecterCarre(); //enregistrement resultatCr dans resultatglobal
    if (resultatglobal.type != 0) {   // Carré trouvé
        return resultatglobal;
    }
    //Suite en ligne 
    resultatglobal = detecterSuiteEnLigne(); //enregistrement resultatL dans resultatglobal
    if (resultatglobal.type != 0) {   // Suite en ligne trouvée
        return resultatglobal;
    }
    //Suite en colonne
    resultatglobal = detecterSuiteEnColonne(); //enregistrement resultatC dans resultatglobal
    if (resultatglobal.type != 0) {   // Suite en colonne trouvée
        return resultatglobal;
    }
    // Pas de figure détectée
    resultatglobal.type = 0;
    resultatglobal.ligne = -1;
    resultatglobal.colonne = -1;
    resultatglobal.taille = 0;
    return resultatglobal;
}



void eliminerFigure (ResultatFigure resultatglobal) {            //Elimine la fonction adéquate en fonction du type de la figure 
    switch(resultatglobal.type) {                                                           
    case 1 : eliminerSuiteEnLigne (resultatglobal); //type SUITE_EN_LIGNE
        break;
    case 2 : eliminerSuiteEnColonne (resultatglobal); //type SUITE_EN_COLONNE
        break;
    case 3 : eliminerCarre(resultatglobal); //type CARRE
        break;
    case 4 : eliminerCroix (resultatglobal); //type CROIX
        break;
    }
    if (item >= 0 && item <= 6) {
        itemsRestants[item] --;
    }
}

bool ligneNonPleine(int ligne) {
    for (j=0 ; j<LARGEUR ; j++) {
        if (grille[ligne][j] == 0) return true;
    }
    return false;
}

void appliquerGravite () {
    // On parcourt la grille de bas en haut
    for (int i=HAUTEUR-1 ; i>0 ; i--) {
        // Tant qu'il y a une case vide sur la ligne courante i
        while (ligneNonPleine(i)) {
            for (int j=0 ; j<LARGEUR ; j++) {
                if (grille[i][j] == 0) {
                    for (int ligne = i-1 ; ligne >=0 ; ligne++) {
                        // On décale les cases vers le bas en partant du bas 
                        grille[ligne+1][j] = grille[ligne][j];
                    }
                    // On vide la case du haut
                    grille[0][j] = 0;
                }
            }
            // Animation chute des items ligne par ligne
            afficherGrille(grille[HAUTEUR][LARGEUR]);
            Sleep(40);
        }
    }
}

void assurerGrilleJouable () {
    
}

void melangerItems() {                                  //Echange les coordonnées de deux items choisis aléatoirement
    int l1, int c1, int l2, int c2, int temp;
    l1 = rand() % HAUTEUR;
    l2 = rand() % HAUTEUR;
    c1 = rand() % LARGEUR;
    c2 = rand() % LARGEUR;

    permuterItems(l1, c1, l2, c2);
}


void permuterItems(int l1, int c1, int l2, int c2){
    //permutation temporaire
    char temp =grille[l1][c1];
    grille[l1][c1]= grille[l2][c2];
    grille[l2][c2]= temp;
}

int sontAdjacentes(int l1, int c1, int l2, int c2){ //verifier si les deux cases sont à côtés l'une de l'autre
    return (abs(l1 - l2) + abs(c1 - c2)) == 1; //calcule de la valeur absolue de la difference entre les deux lignes (vaudra 0 ou 1) et les deux colonnes (vaudra 0 ou 1)
}

 int permuterSiValide(int l1, int c1, int l2, int c2){
    ResultatFigure fig; //variable qui contiendra le retour de la fonction detecterFigure
    //tester si les cases sont à côté
    if (!sontAdjacentes(l1, c1, l2, c2)) {
        return 0; // permutation invalide
    }
    //permutation temporaire
    permuterItems(l1, c1, l2, c2);

    //tester si au moins une figure est détectée après la permutation
    fig = detecterFigure();
    if(fig.type != 0){ //s'il y a au moins une figure detectée
        //permutation valide -> on laisse les cases
        return 1; 
    }
    //si aucune figure -> on annule la permutation
    permuterItems(l1, c1, l2, c2);
    return 0;
 }

//exemple d'utilisation 
if (permuterSiValide(l1, c1, l2, c2)) {
    // appel EliminerFigure + chute + score
} else {
    printf("%c", 7); //bip pour avertir le joueur que le coup n'est pas possible
}

int gererContrat(int *x, int *o, int *et, int *at, int *pourcent, char item, int taille)
{
    if (item == 'X') *x -= taille;
    if (item == 'O') *o -= taille;
    if (item == '&') *et -= taille;
    if (item == '@') *at -= taille;
    if (item == '%') *pourcent -= taille;

    if (*x <= 0 && *o <= 0 && *et <= 0 && *at <= 0 && *pourcent <= 0)
        return 1;

    return 0;
}


int jeu (int temps_restant) {
    int type, int ligne, int colonne, int taille;
    int touche_pressee;

    srand(time(NULL));
     do {
            printf("Il y a deja des combinaisons possibles. Melange en cours ...");
            melangerItems();    
    } while (verifierAbsencesFiguresInitiales == 1);  
    
    deplacementTouches(touche_pressee);
    selectionItems(touche_pressee);
    appliquerGravite();
    detecterSuiteEnLigne();
    eliminerSuiteEnLigne(ResultatFigure resultatL);
    detecterSuiteEnColonne();
    eliminerSuiteEnColonne(ResultatFigure resultatC);
    detecterCroix();
    eliminerCroix(ResultatFigure resultatCx);
    detecterCarre();
    eliminerCarre(ResultatFigure resultatCr);
    decterFigure();
    eliminerFigure(ResultatFigure resultatglobal);

    if (gererContrat==1) {
        gererVictoireNiveau(duree, temps_restant);
    }
    if (temps_restant==0&&gererContrat!=1) {
        gererPerteVies(vies);
        gererEchecNiveau(vies);
    }
    
}
