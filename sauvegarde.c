// #include <stdio.h>
// #include <string.h>
// #include "sauvegarde.h"

// /* Format du fichier texte (1 sauvegarde par ligne)
// pseudo;niveau;vies
// ex: Alice;3;2
// */

// void sauvegarderPartie(const char *pseudo, int niveau, int vies) {
// FILE *f = fopen(FICHIER_SAUVEGARDE, "r");
// FILE *temp = fopen("temp.txt", "w");


// char p[MAX_PSEUDO];
// int n, v;
// int trouve = 0;


// if (f != NULL) {
// while (fscanf(f, "%49[^;];%d;%d\n", p, &n, &v) == 3) {
// if (strcmp(p, pseudo) == 0) { //si le pseudo existe -> met à jour la ligne 
// fprintf(temp, "%s;%d;%d\n", pseudo, niveau, vies); 
// trouve = 1;
// } else {
// fprintf(temp, "%s;%d;%d\n", p, n, v); //sinon -> ajoute une nouvelle ligne
// }
// }
// fclose(f);
// }


// if (!trouve) {
// fprintf(temp, "%s;%d;%d\n", pseudo, niveau, vies);
// }


// fclose(temp);


// remove(FICHIER_SAUVEGARDE);
// rename("temp.txt", FICHIER_SAUVEGARDE); //Utilise un fichier temporaire pour éviter de perdre les données
// }



// int chargerPartie(const char *pseudo, int *niveau, int *vies) {
// FILE *f = fopen(FICHIER_SAUVEGARDE, "r");
// char p[MAX_PSEUDO];
// int n, v;


// if (f == NULL)
// return 0; //pseudo inexistant



// while (fscanf(f, "%49[^;];%d;%d\n", p, &n, &v) == 3) { //recherche le pseudo dans le fichier
// if (strcmp(p, pseudo) == 0) {
// *niveau = n; //remplissage
// *vies = v; //remplissage
// fclose(f);
// return 1; //sauvegarde trouvée
// }
// }


// fclose(f);
// return 0;
// }




// int pseudoExiste(const char *pseudo) { //verifie si le pseudo est déjà eregistré
// FILE *f = fopen(FICHIER_SAUVEGARDE, "r");
// char p[MAX_PSEUDO];
// int n, v;


// if (f == NULL)
// return 0;


// while (fscanf(f, "%49[^;];%d;%d\n", p, &n, &v) == 3) {
// if (strcmp(p, pseudo) == 0) {
// fclose(f);
// return 1;
// }
// }


// fclose(f);
// return 0;
// }










//**************************************NOUVELLE VERSION****************************//

#include <stdio.h>
#include <string.h>
#include "sauvegarde.h"

/*
Format du fichier texte (1 sauvegarde par ligne)
pseudo;niveau;vies
ex: Alice;3;2
*/

void sauvegarderPartie(const char *pseudo, int niveau, int vies)
{
    FILE *f = fopen(FICHIER_SAUVEGARDE, "r");
    FILE *temp = fopen("temp.txt", "w");

    char p[MAX_PSEUDO];
    int n, v;
    int trouve = 0;

    if (temp == NULL) {
        printf("Erreur ouverture fichier temporaire\n");
        return;
    }

    /* Si le fichier de sauvegarde existe déjà */
    if (f != NULL) {
        while (fscanf(f, "%49[^;];%d;%d\n", p, &n, &v) == 3) {
            if (strcmp(p, pseudo) == 0) {
                /* Mise à jour de la sauvegarde */
                fprintf(temp, "%s;%d;%d\n", pseudo, niveau, vies);
                trouve = 1;
            } else {
                /* Recopie des autres sauvegardes */
                fprintf(temp, "%s;%d;%d\n", p, n, v);
            }
        }
        fclose(f);
    }

    /* Si le pseudo n'existait pas, on l'ajoute */
    if (!trouve) {
        fprintf(temp, "%s;%d;%d\n", pseudo, niveau, vies);
    }

    fclose(temp);

    /* Remplacement sécurisé du fichier */
    remove(FICHIER_SAUVEGARDE);
    rename("temp.txt", FICHIER_SAUVEGARDE);
}

int chargerPartie(const char *pseudo, int *niveau, int *vies)
{
    FILE *f = fopen(FICHIER_SAUVEGARDE, "r");
    char p[MAX_PSEUDO];
    int n, v;

    if (f == NULL)
        return 0; // aucune sauvegarde

    while (fscanf(f, "%49[^;];%d;%d\n", p, &n, &v) == 3) {
        if (strcmp(p, pseudo) == 0) {
            *niveau = n;
            *vies = v;
            fclose(f);
            return 1; // sauvegarde trouvée
        }
    }

    fclose(f);
    return 0; // pseudo non trouvé
}

int pseudoExiste(const char *pseudo)
{
    FILE *f = fopen(FICHIER_SAUVEGARDE, "r");
    char p[MAX_PSEUDO];
    int n, v;

    if (f == NULL)
        return 0;

    while (fscanf(f, "%49[^;];%d;%d\n", p, &n, &v) == 3) {
        if (strcmp(p, pseudo) == 0) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}
