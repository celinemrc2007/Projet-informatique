
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>
// #include <windows.h>
// #include <conio.h> 
// #include "jeu.h"
// #include "affichage.h"
// #include "sauvegarde.h"
// #include "gestionClavier.h"
// #include "gestionNiveau.h"

// #define HAUTEUR 10
// #define LARGEUR 9
// #define DUREE 120
// #define PAS_DE_FIGURE 0
// #define SUITE_LIGNE 1
// #define SUITE_COLONNE 2
// #define CARRE 3
// #define CROIX 4
// #define TAILLE_CARRE 4
// #define TAILLE_CROIX 5
// #define TAILLE_BONUS_COUPS 5         //Ajout par nous
// #define TAILLE_BONUS_EXPLOSION 6     //Bonus imposé par la consigne

// int grille[HAUTEUR][LARGEUR];      //Déclaration de la variable globale grille (matrice de taille HAUTEUR*LARGEUR) utilisé dans la majorité des sous-programme de ce module
//                                     //Valeurs de 0 à 5 (Vide + 5 items)
// int compteurs_contrat[7];
// int temps_restant;
// int coups_restants;

// typedef struct {
//     int type;     //SUITE_LIGNE (1), SUITE_COLONNE (2), CARRE (3), CROIX (4), PAS_DE_FIGURE (0)
//     int ligne;
//     int colonne;
//     int taille;
// } ResultatFigure; //structure à utiliser pour eliminer une figure

// void viderGrille() {
//     for (int i=0; i<HAUTEUR; i++) {
//         for (int j=0; j<LARGEUR; j++) {
//             grille[i][j] = 0;
//         }
//     }
// }

// void genererItems()
// {
//     int i, j;
//     srand(time(NULL));

//     for (i = 0; i < HAUTEUR; i++) {
//         for (j = 0; j < LARGEUR; j++) {
//             grille[i][j] = 1 + (rand() % 5);
//         }
//     }
// }

// // Vider la case et mettre à jour les compteurs pour la gestion du contrat
// void viderCase(int i, int j) {
//     int item = grille[i][j];
//     if (compteurs_contrat[item] > 0) compteurs_contrat[item]--;
//     grille[i][j] = 0;
// }

// int gererContrat()
// {
//     for (int i=1 ; i <= 5 ; i++) {
//         if (compteurs_contrat[i] > 0) return 0;
//     }
//     return 1;
// }   

// ResultatFigure detecterSuiteEnLigne(){
//     int i, j;
//     ResultatFigure resultatL = {PAS_DE_FIGURE, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
//     //boucle for pour parcourir les lignes donc la hauteur
//     for(i=0; i<HAUTEUR; i++){
//         int compteur = 1; //sert à mesurer la longueur d’une suite d’items identiques consécutifs. s'incrémente quand deux cases consécutives sont égales
//         //boucle for pour parcourir les colonnes donc la largeur
//         for(j=1; j<LARGEUR; j++){
//             if(grille[i][j]==grille[i][j-1] && grille[i][j] != 0){ //comparaison de deux cases consécutives
//                 compteur++;

//             } else {
//                 if(compteur>=3){ //on a une suite valide si elle fait au moins 3 cases
//                     resultatL.type = 0; //type PAS_DE_FIGURE
//                     resultatL.ligne = i; //on veut le numero de la ligne où se trouve la suite
//                     resultatL.colonne = j - compteur + 1;//on veut le numero de la première colonne où commence la suite
//                     resultatL.taille = compteur; //taille de la suite (3, 4, 5 ou 6)
//                     return resultatL;
//                 }
//                 compteur = 1; // reinitialisation si les deux cases consécutives ne sont pas identiques
//             }   
//         }
//     }
//     return resultatL; //aucune suite trouvée
// }

// void eliminerSuiteEnLigne(ResultatFigure resultatL) {
//     if(resultatL.taille >= 6) {
//         // On élimine tous les item identiques
//         int item = grille[resultatL.ligne][resultatL.colonne];
//         for (int i = 0; i < HAUTEUR; i++) {
//             for (int j = 0; j < LARGEUR; j++) {
//                 if (grille[i][j] == item) viderCase(i, j);
//             }
//         }
//     } else {
//         for (int i=0; i<resultatL.taille; i++) {                      
//             viderCase (resultatL.ligne, resultatL.colonne); //Parcourir les cases de la suite de gauche à droite
//         }
//     }
// }


// ResultatFigure detecterSuiteEnColonne(){
//     int i, j;
//     ResultatFigure resultatC = {PAS_DE_FIGURE, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
//     //boucle for pour parcourir les colonnes donc la largeur
//     for(j=0; j<LARGEUR; j++){
//         int compteur = 1; //sert à mesurer la longueur d’une suite d’items identiques consécutifs. s'incrémente quand deux cases consécutives sont égales
//         //boucle for pour parcourir les lignes donc la hauteur
//         for(i=1; i<HAUTEUR; i++){
//             if(grille[i][j]==grille[i-1][j] && grille[i][j] != 0){ //comparaison de deux cases consécutives
//                 compteur++;

//             } else {
//                 if(compteur>=3){//on a une suite valide si elle fait au moins 3 cases
//                     resultatC.type = 2; //type SUITE_EN_COLONNE
//                     resultatC.ligne = i-compteur + 1; //on veut le numero de la première ligne où commence la suite
//                     resultatC.colonne = j;
//                     resultatC.taille = compteur; //taille de la suite (3, 4, 5 ou 6)
//                     return resultatC;
//                 }
//                 compteur = 1; //reinitialisation si les deux cases consécutives ne sont pas identiques
//             }
//         }
//     }
//     return resultatC; //aucune suite trouvée
// }


// void eliminerSuiteEnColonne(ResultatFigure resultatC) { 
//     if(resultatC.taille >= 6) {
//         // On élimine tous les item identiques
//         int item = grille[resultatC.ligne][resultatC.colonne];
//         for (int i = 0; i < HAUTEUR; i++) {
//             for (int j = 0; j < LARGEUR; j++) {
//                 if (grille[i][j] == item) viderCase(i, j);
//             }
//         }
//     } else {
//         for (int i=0; i<resultatC.taille; i++) {
//             viderCase(resultatC.ligne, resultatC.colonne); //Parcourir les cases de la suite de haut en bas et affecter 0 à chacune de ces cases
//         }   
//     }
// }

// ResultatFigure detecterCarre(){
//     int i, j;
//     ResultatFigure resultatCr = {0, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
//     //boucle for pour parcourir les lignes donc la hauteur
//     for(i=0; i<HAUTEUR-3; i++){
//         //boucle for pour parcourir les colonnes donc la largeur
//         for(j=0; j<LARGEUR-3; j++){

//             int c = grille[i][j]; //enregistrement du type d'item en entier dans la variable c
//             if(c==0) continue; //si la case est vide, on continue de chercher dans la grille

//             if(grille[i][j]== c && grille[i+1][j]== c && grille[i+2][j]== c && grille[i+3][j]== c && grille[i+3][j+1]== c && grille[i+3][j+2]== c && grille[i+3][j+3]== c && grille[i][j+1]== c && grille[i][j+2]== c && grille[i][j+3]== c && grille[i+1][j+3]== c && grille[i+2][j+3]== c){
//                 resultatCr.type = 3; //type CARRE
//                 resultatCr.ligne = i; //ligne où se trouve la case en haut à gauche du carré
//                 resultatCr.colonne = j; //colonne où se trouve la case en haut à gauche du carré
//                 resultatCr.taille = 4; //le carré fait 4 items de côté
//                 return resultatCr;
//             }
//         }
//     }
//     return resultatCr; //aucun carré trouvé
// }


// void eliminerCarre (ResultatFigure resultatCr) { //utilise resultatCr
//     for (int i=0; i<TAILLE_CARRE; i++) {
//         viderCase(resultatCr.ligne, resultatCr.colonne+i);                   //Parcourir la ligne la plus haute du carre de gauche à droite et affecter 0 à chacune de ces cases
//         viderCase(resultatCr.ligne+TAILLE_CARRE-1, resultatCr.colonne + i);  //Parcourir la ligne la plus basse du carre de gauche à droite et affecter 0 à chacune de ces cases
//     }   
//     for (int i=0; i<TAILLE_CARRE; i++) {
//         viderCase(resultatCr.ligne + i, resultatCr.colonne);                 //Parcourir la ligne la plus à gauche du carre de haut en bas en affectant 0 à chacune de ces cases
//         viderCase(resultatCr.ligne + i, resultatCr.colonne+TAILLE_CARRE-1);  //Parcourir la ligne la plus à droite du carre de haut en bas en affectant 0 à chacune de ces cases
//     }
// }


// ResultatFigure detecterCroix(){
//     int i, j;
//     ResultatFigure resultatCx = {PAS_DE_FIGURE, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
//     //boucle for pour parcourir les lignes donc la hauteur
//     for(i=2; i<HAUTEUR-2; i++){ //au minimum le centre de la croix se trouve à la ligne 2
//         //boucle for pour parcourir les colonnes donc la largeur
//         for(j=2; j<LARGEUR-2; j++){ //au minimum le centre de la croix se trouve à la colonne 2

//             int c = grille[i][j]; //enregistrement du type d'item dans la variable c
//             if(c==0) continue; //si la case est vide, on continue de chercher dans la grille

//             if(grille[i][j]== c && grille[i-1][j]== c && grille[i-2][j]== c && grille[i+1][j]== c && grille[i+2][j]== c && grille[i][j-1]== c && grille[i][j-2]== c && grille[i][j+1]== c && grille[i][j+2]== c){
//                 resultatCx.type = 4;  //type CROIX
//                 resultatCx.ligne = i; //ligne où se trouve la case centrale de la croix
//                 resultatCx.colonne = j; //colonne où se trouve la case centrale de la croix
//                 resultatCx.taille = 5; //la croix fait 5 items par branche 
//                 return resultatCx;
//             }
//         }
//     }
//     return resultatCx; //aucune croix trouvée
// }


// void eliminerCroix (ResultatFigure resultatCx) { //utilise resultatCx
//     for (int i=0; i<TAILLE_CROIX; i++) {
//         viderCase(resultatCx.ligne, resultatCx.colonne + i - 2);    //Se placer au centre de la croix, aller 2 cases vers la gauche et parcourir les cases de gauche à droite en affectant 0 à chacune de ces cases
//     }   
//     for (int i=0; i<TAILLE_CROIX; i++) {
//         viderCase(resultatCx.ligne + i - 2, resultatCx.colonne);       //Se placer au centre de la croix, aller 2 cases vers la haut et parcourir les cases haut en bas en affectant 0 à chacune de ces cases
//     }
// }


// ResultatFigure detecterFigure(){
//     ResultatFigure resultatglobal;
//     //Croix
//     resultatglobal = detecterCroix(); //enregistrement resultatCx dans resultatglobal
//     if (resultatglobal.type != 0) {  // Croix trouvée
//         return resultatglobal;
//     }
//     //Carre
//     resultatglobal = detecterCarre(); //enregistrement resultatCr dans resultatglobal
//     if (resultatglobal.type != 0) {   // Carré trouvé
//         return resultatglobal;
//     }
//     //Suite en ligne 
//     resultatglobal = detecterSuiteEnLigne(); //enregistrement resultatL dans resultatglobal
//     if (resultatglobal.type != 0) {   // Suite en ligne trouvée
//         return resultatglobal;
//     }
//     //Suite en colonne
//     resultatglobal = detecterSuiteEnColonne(); //enregistrement resultatC dans resultatglobal
//     if (resultatglobal.type != 0) {   // Suite en colonne trouvée
//         return resultatglobal;
//     }
//     // Pas de figure détectée
//     resultatglobal.type = 0;
//     resultatglobal.ligne = -1;
//     resultatglobal.colonne = -1;
//     resultatglobal.taille = 0;
//     return resultatglobal;
// }



// void eliminerFigure (ResultatFigure resultatglobal) {            //Elimine la fonction adéquate en fonction du type de la figure 
//     switch(resultatglobal.type) {                                                           
//     case 1 : eliminerSuiteEnLigne (resultatglobal); //type SUITE_EN_LIGNE
//         break;
//     case 2 : eliminerSuiteEnColonne (resultatglobal); //type SUITE_EN_COLONNE
//         break;
//     case 3 : eliminerCarre(resultatglobal); //type CARRE
//         break;
//     case 4 : eliminerCroix (resultatglobal); //type CROIX
//         break;
//     }
// }

// int verifierAbsencesFiguresInitiales () {
//     ResultatFigure fig = detecterFigure();
//     if(fig.type != PAS_DE_FIGURE) {
//         return 1;
//     }
//     return 0; 
// }

// bool ligneNonPleine(int ligne) {
//     for (int j=0 ; j<LARGEUR ; j++) {
//         if (grille[ligne][j] == 0) return true;
//     }
//     return false;
// }

// void appliquerGravite () {
//     // On parcourt la grille de bas en haut
//     for (int i=HAUTEUR-1 ; i>0 ; i--) {
//         // Tant qu'il y a une case vide sur la ligne courante i
//         while (ligneNonPleine(i)) {
//             for (int j=0 ; j<LARGEUR ; j++) {
//                 if (grille[i][j] == 0) {
//                     for (int ligne = i-1 ; ligne >=0 ; ligne++) {
//                         // On décale les cases vers le bas en partant du bas 
//                         grille[ligne+1][j] = grille[ligne][j];
//                     }
//                     // On vide la case du haut
//                     grille[0][j] = 0;
//                 }
//             }
//             // Animation chute des items ligne par ligne
//             afficherGrille(grille);
//             Sleep(40);
//         }
//     }
// }

// void assurerGrilleJouable () {
    
// }

// void permuterItems(int l1, int c1, int l2, int c2){
//     //permutation temporaire
//     char temp = grille[l1][c1];
//     grille[l1][c1] = grille[l2][c2];
//     grille[l2][c2] = temp;
// }

// void melangerItems() {                                  //Echange les coordonnées de deux items choisis aléatoirement
//     int l1, c1, l2, c2, temp;
//     l1 = rand() % HAUTEUR;
//     l2 = rand() % HAUTEUR;
//     c1 = rand() % LARGEUR;
//     c2 = rand() % LARGEUR;

//     permuterItems(l1, c1, l2, c2);
// }

// /*
// int sontAdjacentes(int l1, int c1, int l2, int c2){ //verifier si les deux cases sont à côtés l'une de l'autre
//     return (abs(l1 - l2) + abs(c1 - c2)) == 1; //calcule de la valeur absolue de la difference entre les deux lignes (vaudra 0 ou 1) et les deux colonnes (vaudra 0 ou 1)
// }
// */

//  int permuterSiValide(int l1, int c1, int l2, int c2) {
//     ResultatFigure fig; //variable qui contiendra le retour de la fonction detecterFigure
//     //tester si les cases sont à côté
//     //if (!sontAdjacentes(l1, c1, l2, c2)) {
//     //    return 0; // permutation invalide
//     //}
    
//     //permutation temporaire
//     permuterItems(l1, c1, l2, c2);

//     //tester si au moins une figure est détectée après la permutation
//     fig = detecterFigure();
//     if (fig.type != PAS_DE_FIGURE) { //s'il y a au moins une figure detectée
//         //permutation valide -> on laisse les cases
//         return 1; 
//     }
//     //si aucune figure -> on annule la permutation
//     permuterItems(l1, c1, l2, c2);
//     return 0;
// }

// int jeu () {
//     char touche_pressee;
//     int vies_restantes = 3;
//     int coups_restants = 25;
//     float temps_fin = clock() + DUREE;
//     int x = LARGEUR / 2;
//     int y = HAUTEUR / 2;

//     srand(time(NULL));
//     viderGrille();
//     genererItems();
//     assurerGrilleJouable();
//     afficherGrille(grille);
//     afficherNombredeVies(vies_restantes);
//     afficherCoupsRestants(coups_restants);
//     afficherItemsRestants(compteurs_contrat);
//     do {
//             //printf("Il y a deja des combinaisons possibles. Melange en cours ...");
//             melangerItems();    
//     } while (verifierAbsencesFiguresInitiales () == 1);  
    
//     // Boucle principale du jeu
//     do {
//         float temps_restant = temps_fin - clock();
//         afficherTempsRestant(temps_restant);
//         touche_pressee = 0;
//         if (_kbhit()) {
//             touche_pressee = _getch();
//             afficherGrille(grille);
//         }
//         deplacementTouches(touche_pressee);
//         int l1, c1, l2, c2;
//         if (selectionItem(touche_pressee, &l1, &c1, &l2, &c2)) {
//             if (permuterSiValide(l1, c1, l2, c2)) {
//                 ResultatFigure fig; //variable qui contiendra le retour de la fonction detecterFigure
//                 fig = detecterFigure();
//                 coups_restants--;
//                 afficherCoupsRestants(coups_restants);
//                 do {
//                     eliminerFigure(fig);
//                     afficherItemsRestants(compteurs_contrat);
//                     appliquerGravite();
//                     fig = detecterFigure();
//                 }
//                 while (fig.type != PAS_DE_FIGURE);
//             } else {
//             printf("%c", 7); //bip pour avertir le joueur que le coup n'est pas possible
//             }
//         }
        
//         if (gererContrat()==1) {
//             gererVictoireNiveau();
//         }
//         if (((temps_restant==0)||(coups_restants<=0))&&(gererContrat()!=1)) {
//             gererEchecNiveau(&vies_restantes);
//             afficherNombredeVies(vies_restantes);
//         }
//     }
//     while(false);

// }


//*********************NOUVELLE VERSION****************************//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

#include "affichage.h"
#include "jeu.h"
#include "gestionClavier.h"
#include "gestionNiveau.h"

/* ================= CONSTANTES ================= */

#define PAS_DE_FIGURE 0
#define SUITE_LIGNE 1
#define SUITE_COLONNE 2
#define CARRE 3
#define CROIX 4

#define TAILLE_CARRE 4
#define TAILLE_CROIX 5

#define PROBABILITE_MALUS 30        // %
#define DIMINUTION_DUREE_MALUS 10   // en secondes

/* ================= VARIABLES GLOBALES ================= */

int grille[HAUTEUR][LARGEUR];
int compteurs_contrat[7];

clock_t debut;
int temps_restant;
int coups_restants;
bool malus_actif = true;   // Pas de malus pour les figures detectées automatiquement 

/* ================= OUTILS ================= */

void viderGrille(void) {
    for (int i=0;i<HAUTEUR;i++)
        for (int j=0;j<LARGEUR;j++)
            grille[i][j] = 0;
}

void genererItems(void) {
    for (int i=0;i<HAUTEUR;i++) {
        for (int j=0;j<LARGEUR;j++) {
            if (grille[i][j] == 0) {
                grille[i][j] = 1 + rand() % 5;
                if ((niveau > 1) && (grille[i][j] == 5) && (rand() % 100 < PROBABILITE_MALUS)) {
                    grille[i][j] += 8;
                }
            }
        }
    }
}

void viderCase(int i, int j) {
    int item = grille[i][j];
    if (malus_actif && (item == 13) && (temps_restant > DIMINUTION_DUREE_MALUS)) {
        // On fait comme si le jeu avait demarré 10 secondes plus tot
        debut -= DIMINUTION_DUREE_MALUS * CLOCKS_PER_SEC;
        Beep(200,1000);
    }
    item = item%8;
    if (item > 0 && compteurs_contrat[item] > 0)
        compteurs_contrat[item]--;
    grille[i][j] = 0;
    afficherCoupsRestants(coups_restants);
    afficherTempsRestant(temps_restant);
    afficherItemsRestants(compteurs_contrat);
}

/* ================= CONTRAT ================= */

int gererContrat(void) {
    for (int i=1;i<=5;i++)
        if (compteurs_contrat[i] > 0)
            return 0;
    return 1;
}

/* ================= DETECTION / ELIMINATION ================= */

ResultatFigure detecterSuiteEnLigne(){
    int i, j;
    ResultatFigure resultatL = {PAS_DE_FIGURE, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
    //boucle for pour parcourir les lignes donc la hauteur
    for(i=0; i<HAUTEUR; i++){
        int compteur = 1; //sert à mesurer la longueur d’une suite d’items identiques consécutifs. s'incrémente quand deux cases consécutives sont égales
        //boucle for pour parcourir les colonnes donc la largeur
        for(j=1; j<LARGEUR; j++){
            if(grille[i][j]%8==grille[i][j-1]%8 && grille[i][j] != 0){ //comparaison de deux cases consécutives
                compteur++;

            } else {
                    if(compteur>=3){ //on a une suite valide si elle fait au moins 3 cases
                    resultatL.type = SUITE_LIGNE ; //type SUITE_LIGNE
                    resultatL.ligne = i; //on veut le numero de la ligne où se trouve la suite
                    resultatL.colonne = j - compteur; //+ 1;//on veut le numero de la première colonne où commence la suite
                    resultatL.taille = compteur; //taille de la suite (3, 4, 5 ou 6)
                    return resultatL;
                }
                compteur = 1; // reinitialisation si les deux cases consécutives ne sont pas identiques
            }   
        }
        if(compteur>=3) { // Cas d'une suite en fin de ligne
            resultatL.type = SUITE_LIGNE ; //type SUITE_LIGNE
            resultatL.ligne = i; //on veut le numero de la ligne où se trouve la suite
            resultatL.colonne = j - compteur; //+ 1;//on veut le numero de la première colonne où commence la suite
            resultatL.taille = compteur; //taille de la suite (3, 4, 5 ou 6)
            return resultatL;
        }
    }
    return resultatL; //aucune suite trouvée
}

void eliminerSuiteEnLigne(ResultatFigure resultatL) {
    gererBonusNiveau3 (resultatL);
    if(resultatL.taille >= 6) {
        // On élimine tous les item identiques
        int item = grille[resultatL.ligne][resultatL.colonne]%8;
        for (int i = 0; i < HAUTEUR; i++) {
            for (int j = 0; j < LARGEUR; j++) {
                if (grille[i][j]%8 == item) viderCase(i, j);
            }
        }
    } else {
        for (int i=0; i<resultatL.taille; i++) {                      
            viderCase (resultatL.ligne, resultatL.colonne+i); //Parcourir les cases de la suite de gauche à droite
        }
    }
}


ResultatFigure detecterSuiteEnColonne(){
    int i, j;
    ResultatFigure resultatC = {PAS_DE_FIGURE, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
    //boucle for pour parcourir les colonnes donc la largeur
    for(j=0; j<LARGEUR; j++){
        int compteur = 1; //sert à mesurer la longueur d’une suite d’items identiques consécutifs. s'incrémente quand deux cases consécutives sont égales
        //boucle for pour parcourir les lignes donc la hauteur
        for(i=1; i<HAUTEUR; i++){
            if(grille[i][j]%8 == grille[i-1][j]%8 && grille[i][j] != 0){ //comparaison de deux cases consécutives
                compteur++;

            } else {
                if(compteur>=3){//on a une suite valide si elle fait au moins 3 cases
                    resultatC.type = SUITE_COLONNE; //type SUITE_EN_COLONNE
                    resultatC.ligne = i-compteur; //+ 1; //on veut le numero de la première ligne où commence la suite
                    resultatC.colonne = j;
                    resultatC.taille = compteur; //taille de la suite (3, 4, 5 ou 6)
                    return resultatC;
                }
                compteur = 1; //reinitialisation si les deux cases consécutives ne sont pas identiques
            }
        }
        if(compteur>=3) { // Cas d'une suite en fin de colonne
            resultatC.type = SUITE_COLONNE; //type SUITE_EN_COLONNE
            resultatC.ligne = i-compteur; //+ 1; //on veut le numero de la première ligne où commence la suite
            resultatC.colonne = j;
            resultatC.taille = compteur; //taille de la suite (3, 4, 5 ou 6)
            return resultatC;
        }
    }
    return resultatC; //aucune suite trouvée
}


void eliminerSuiteEnColonne(ResultatFigure resultatC) { 
    gererBonusNiveau3 (resultatC);
    if(resultatC.taille >= 6) {
        // On élimine tous les item identiques
        int item = grille[resultatC.ligne][resultatC.colonne]%8;
        for (int i = 0; i < HAUTEUR; i++) {
            for (int j = 0; j < LARGEUR; j++) {
                if (grille[i][j]%8 == item) viderCase(i, j);
            }
        }
    } else {
        for (int i=0; i<resultatC.taille; i++) {
            viderCase(resultatC.ligne+i, resultatC.colonne); //Parcourir les cases de la suite de haut en bas et affecter 0 à chacune de ces cases
        }   
    }
}

ResultatFigure detecterCarre(){
    int i, j;
    ResultatFigure resultatCr = {0, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
    //boucle for pour parcourir les lignes donc la hauteur
    for(i=0; i<HAUTEUR-3; i++){
        //boucle for pour parcourir les colonnes donc la largeur
        for(j=0; j<LARGEUR-3; j++){

            int c = grille[i][j]%8; //enregistrement du type d'item en entier dans la variable c
            if(c==0) continue; //si la case est vide, on continue de chercher dans la grille

            if(grille[i][j]%8 == c && grille[i+1][j]%8 == c && grille[i+2][j]%8 == c && grille[i+3][j]%8 == c &&
               grille[i+3][j+1]%8 == c && grille[i+3][j+2]%8 == c && grille[i+3][j+3]%8 == c &&
               grille[i][j+1]%8 == c && grille[i][j+2]%8 == c && grille[i][j+3]%8 == c && grille[i+1][j+3]%8 == c && grille[i+2][j+3]%8 == c) {
                resultatCr.type = CARRE; //type CARRE
                resultatCr.ligne = i; //ligne où se trouve la case en haut à gauche du carré
                resultatCr.colonne = j; //colonne où se trouve la case en haut à gauche du carré
                resultatCr.taille = TAILLE_CARRE; //le carré fait 4 items de côté
                return resultatCr;
            }
        }
    }
    return resultatCr; //aucun carré trouvé
}


void eliminerCarre (ResultatFigure resultatCr) { //utilise resultatCr
    for (int i=0; i<TAILLE_CARRE; i++) {
        viderCase(resultatCr.ligne, resultatCr.colonne+i);                   //Parcourir la ligne la plus haute du carre de gauche à droite et affecter 0 à chacune de ces cases
        viderCase(resultatCr.ligne+TAILLE_CARRE-1, resultatCr.colonne + i);  //Parcourir la ligne la plus basse du carre de gauche à droite et affecter 0 à chacune de ces cases
    }   
    for (int i=0; i<TAILLE_CARRE; i++) {
        viderCase(resultatCr.ligne + i, resultatCr.colonne);                 //Parcourir la ligne la plus à gauche du carre de haut en bas en affectant 0 à chacune de ces cases
        viderCase(resultatCr.ligne + i, resultatCr.colonne+TAILLE_CARRE-1);  //Parcourir la ligne la plus à droite du carre de haut en bas en affectant 0 à chacune de ces cases
    }
}


ResultatFigure detecterCroix(){
    int i, j;
    ResultatFigure resultatCx = {PAS_DE_FIGURE, -1, -1, 0}; //initialisation du retour de la fonction avec des valeurs invalides (-1) pour ne pas créer de bug
    //boucle for pour parcourir les lignes donc la hauteur
    for(i=2; i<HAUTEUR-2; i++){ //au minimum le centre de la croix se trouve à la ligne 2
        //boucle for pour parcourir les colonnes donc la largeur
        for(j=2; j<LARGEUR-2; j++){ //au minimum le centre de la croix se trouve à la colonne 2

            int c = grille[i][j]%8; //enregistrement du type d'item dans la variable c
            if(c==0) continue; //si la case est vide, on continue de chercher dans la grille

            if(grille[i][j]%8 == c && grille[i-1][j]%8 == c && grille[i-2][j]%8 == c && grille[i+1][j]%8 == c && grille[i+2][j]%8 == c &&
               grille[i][j-1]%8 == c && grille[i][j-2]%8 == c && grille[i][j+1]%8 == c && grille[i][j+2]%8 == c){
                resultatCx.type = CROIX;  //type CROIX
                resultatCx.ligne = i; //ligne où se trouve la case centrale de la croix
                resultatCx.colonne = j; //colonne où se trouve la case centrale de la croix
                resultatCx.taille = TAILLE_CROIX; //la croix fait 5 items par branche 
                return resultatCx;
            }
        }
    }
    return resultatCx; //aucune croix trouvée
}


void eliminerCroix (ResultatFigure resultatCx) { //utilise resultatCx
    for (int i=0; i<TAILLE_CROIX; i++) {
        viderCase(resultatCx.ligne, resultatCx.colonne + i - 2);    //Se placer au centre de la croix, aller 2 cases vers la gauche et parcourir les cases de gauche à droite en affectant 0 à chacune de ces cases
    }   
    for (int i=0; i<TAILLE_CROIX; i++) {
        viderCase(resultatCx.ligne + i - 2, resultatCx.colonne);       //Se placer au centre de la croix, aller 2 cases vers la haut et parcourir les cases haut en bas en affectant 0 à chacune de ces cases
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
    resultatglobal.type = PAS_DE_FIGURE;
    resultatglobal.ligne = -1;
    resultatglobal.colonne = -1;
    resultatglobal.taille = 0;
    return resultatglobal;
}



void eliminerFigure (ResultatFigure resultatglobal) {            //Elimine la fonction adéquate en fonction du type de la figure 
    int copie_grille[HAUTEUR][LARGEUR];
    for (int i=0;i<HAUTEUR;i++)
        for (int j=0;j<LARGEUR;j++)
            copie_grille[i][j] = grille[i][j];

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
    // Clignotement
    for (int c=0 ; c < 5 ; c++) {
        afficherGrille(grille);
        Sleep(100);
        afficherGrille(copie_grille);
        Sleep(100);
    }
    afficherGrille(grille);
}



/* ================= GRAVITÉ ================= */

bool ligneNonPleine(int ligne) {
    for (int j=0;j<LARGEUR;j++)
        if (grille[ligne][j] == 0) return true;
    return false;
}

void appliquerGravite(void) {
    for (int i=HAUTEUR-1;i>0;i--) {
        while (ligneNonPleine(i)) {
            for (int j=0;j<LARGEUR;j++) {
                if (grille[i][j] == 0) {
                    for (int k=i-1;k>=0;k--)
                        grille[k+1][j] = grille[k][j];
                    grille[0][j] = 1 + rand() % 5;  // Pas de malus rajouté
                }
            }
            afficherGrille(grille);
            Sleep(100);
        }
    }
}

void assurerAbsencesFiguresInitiales () {
    while (detecterFigure().type != PAS_DE_FIGURE)
        melangerItems();
}

/* ================= GRILLE JOUABLE ================= */

bool verifierGrilleJouable() {
    ResultatFigure fig;
    for (int i=0 ; i<LARGEUR-1 ; i++) {
        for (int j=0 ; j<HAUTEUR ; j++) {
            permuterItems(i, j, i+1, j);
            fig = detecterFigure();
            permuterItems(i, j, i+1, j);
            if (fig.type != PAS_DE_FIGURE) {
                return true;
            }
        }
    }
    for (int i=0 ; i<LARGEUR ; i++) {
        for (int j=0 ; j<HAUTEUR-1 ; j++) {
            permuterItems(i, j, i, j+1);
            fig = detecterFigure();
            permuterItems(i, j, i, j+1);
            if (fig.type != PAS_DE_FIGURE) {
                return true;
            }
        }
    }
    return false;
}

void assurerGrilleJouable() {
    while (verifierGrilleJouable() == false) {
        melangerItems();
    }
}

/* ================= PERMUTATION ================= */

void permuterItems(int l1,int c1,int l2,int c2) {
    int tmp = grille[l1][c1];
    grille[l1][c1] = grille[l2][c2];
    grille[l2][c2] = tmp;
}

int permuterSiValide(int l1,int c1,int l2,int c2) {
    permuterItems(l1,c1,l2,c2);
    if (detecterFigure().type != PAS_DE_FIGURE) {
        return 1;
    }
    permuterItems(l1,c1,l2,c2);
    Beep(200,500);
    Sleep(200);
    Beep(200,500);
    return 0;
}

void melangerItems() {                                  //Echange les coordonnées de deux items choisis aléatoirement
    int l1, c1, l2, c2, temp;
    l1 = rand() % HAUTEUR;
    l2 = rand() % HAUTEUR;
    c1 = rand() % LARGEUR;
    c2 = rand() % LARGEUR;

    permuterItems(l1, c1, l2, c2);
}   

/* ================= BOUCLE DE JEU ================= */

int jeu(void) {
    char touche;
    
    clock_t debut = clock();
    int temps_depart = temps_restant;

    srand(time(NULL));
    viderGrille();
    genererItems();
 
    assurerAbsencesFiguresInitiales ();
    assurerGrilleJouable();
    
    while (coups_restants > 0) {

        temps_restant = temps_depart - (clock() - debut) / CLOCKS_PER_SEC;
        if (temps_restant <= 0) return 2;

        afficherGrille(grille);
        afficherNumeroNiveau(niveau);
        afficherCoupsRestants(coups_restants);
        afficherTempsRestant(temps_restant);
        afficherNombredeVies(vies_restantes);
        afficherItemsRestants(compteurs_contrat);

        if (_kbhit()) {
            touche = _getch();
            deplacementTouches(touche);

            int l1,c1,l2,c2;
            if (selectionItem(touche,&l1,&c1,&l2,&c2)) {
                if (permuterSiValide(l1,c1,l2,c2)) {
                    coups_restants--;
                    ResultatFigure fig;
                    do {
                        fig = detecterFigure();
                        if (fig.type != PAS_DE_FIGURE) {
                            eliminerFigure(fig);
                            afficherItemsRestants(compteurs_contrat);
                            appliquerGravite();
                            genererItems ();
                            malus_actif = false;
                        }
                    } while (fig.type != PAS_DE_FIGURE);
                    assurerGrilleJouable ();
                    malus_actif = true;
                }
            }
        }

        if (gererContrat()) {
            afficherItemsRestants (compteurs_contrat);
            return 1;
        }
        Sleep(30);
    }
    return 3;
}
