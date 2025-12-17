//Afficher le menu
int menu() {
    int choix;
    text_color(FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
    printf("\n1. Jouer");
    printf("\n2. Regles du jeu");
    printf("\n3. Quitter\n");
    scanf("%d",&choix);
    return choix;
}
int main() {
    int choix;
    // initialisation du générateur pseudo-aléatoire
    srand(time(NULL));
    //boucle de retour au menu à la fin d'une partie
    do{
        //gestion du menu
        choix=menu();
        switch(choix){
            case 1 : /*lancement d'une partie*/
                    //hide_cursor();
                    clrscr();
                    jouer();
                    //show_cursor();
                    break;
            case 2 :
                    afficherRegles();
                    break;
        }
    }while(choix!=3);

    return 0;
}

