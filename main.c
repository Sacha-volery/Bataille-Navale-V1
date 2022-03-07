//Sacha Volery
//Exercice Bataille navale
//14.02.2022

#include <stdio.h>
#include <time.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    int axeX, axeY, regle;
    int choix,ligne;
    int BNtableau[10][10] = {
            {0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
            {0, 0, 0, 0, 0, 0, 0,  0,  0,  0, 0},
            {0, 0, 0, 0, 0, 0, 10, 0,  0,  0},
            {0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
            {0, 0, 0, 0, 0, 0, 0,  0,  0,  105},
            {0, 0, 0, 0, 0, 0, 0,  0,  0,  105},
            {0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
            {0, 0, 0, 0, 0, 0, 0,  0,  10, 0},
            {0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
            {0, 0, 0, 0, 0, 0, 13, 13, 3,  0},
    };

    printf("    | A | B | C | D | E | F | G | H | I | J |");
    for (int ligne = 0; ligne <= 9; ligne++) {
        //printf("\n%2       d  |", ligne + 1);


        printf("\n");
    }
    printf("quelle mode voulez-vous\n"
           "1 : didactiel\n"
           "2 : jouer contre l'ordinateur\n");
    scanf("%d", &choix);
    switch (choix) {
        case 1:{
            printf("voici le didactiel :"
                   "\nle but du jeu est de placé ces bateaux sur la grille et coulé les autres bateaux en tirant sur la grille de notre adversaire ");
            break;
    }
    case 2 : {
        printf("voici le mode jouer tous seule :\n");
    }
    }

    printf("\n");
        printf(" | A | B | C | D | E | F | G | H | I | J |"); for (int ligne = 0; ligne <= 10; ligne++) {
        printf("\n");
        printf("%2d",ligne +1);
            for (int colonnes = 0; colonnes <= 10; colonnes++) {
                if (BNtableau[ligne][colonnes] == 0) { printf(" |"); }
                if ((BNtableau[ligne][colonnes] >= 1) && (BNtableau[ligne][colonnes] <= 5)) { printf(" |"); }
                if (BNtableau[ligne][colonnes] == 10) { printf(" x |"); }
                if ((BNtableau[ligne][colonnes] >= 11) && (BNtableau[ligne][colonnes] <= 15)) { printf(" I |"); }
                if ((BNtableau[ligne][colonnes] >= 101) && (BNtableau[ligne][colonnes] <= 105)) { printf(" $ |"); }
            }
            printf("\n"); }


    }








































