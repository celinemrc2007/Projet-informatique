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

