//Sacha Volery
//Exercice Bataille navale
//14.02.2022

#include <stdio.h>
#include <time.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    int nbbateau;
    char RepCol[] = "A";
    int colonne, axeY, regle;
    int choix,ligne;
    int BNtableau[10][10] = {
            {5, 5, 0, 0, 0, 0, 0,  0,  0,  0},
            {0, 0, 0, 0, 0, 0, 0,  0,  0,  0},
            {0, 0, 0, 0, 1, 0, 0,  3,  0,  0},
            {0, 0, 0, 0, 1, 0, 0,  3,  0,  0},
            {0, 4, 0, 0, 1, 0, 0,  3,  0,  0},
            {0, 4, 0, 0, 0, 0, 0,  3,  0,  0},
            {0, 4, 0, 0, 0, 0, 0,  0,  0,  0},
            {0, 4, 0, 0, 0, 2, 2,  0,  0,  0},
            {0, 4, 0, 0, 0, 0, 0,  0,  0,  0},
            {0, 0, 0, 0, 0, 0, 0,  0, 0,   0},
    };

    printf("    | A | B | C | D | E | F | G | H | I | J |");
    for (int ligne = 0; ligne <= 9; ligne++) {



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

        do {
            printf("\nColonne ?(A-J)");
            scanf("%s", &RepCol);
            RepCol[0] = RepCol[0] & (0xFF - 0x20);
            colonne = RepCol[0] - 65;
            printf("\nLigne ?(1-10)");
            scanf("%d", &ligne);
            ligne -= 1;
            //Mise à jour tableau
            if (BNtableau[ligne][colonne] < 10)
                BNtableau[ligne][colonne] += 10;

            //Affichage du tableau
            printf("\n    A | B | C | D | E | F | G | H | I | J |");
            for (int ligne = 0; ligne < 10; ligne++) {
                printf("\n");
                printf("%2d", ligne + 1);
                for (int colonne = 0; colonne < 10; colonne++) {
                    if (BNtableau[ligne][colonne] < 10) {
                        printf(" [ ]");
                    }
                    if (BNtableau[ligne][colonne] == 10) {
                        printf(" [0]");
                    }
                    if (BNtableau[ligne][colonne] > 10) {
                        printf(" [x]");
                    }
                    if (BNtableau[ligne][colonne] > 20) {
                        printf(" [$]");
                    }
                }
            }
            //Quand c'est fini la bataille s'arrête
            nbbateau = 0;
            for (int ligne = 0; ligne < 10; ligne++) {
                for (int colonne = 0; colonne < 10; colonne++) {
                    if ((BNtableau[ligne][colonne] >= 1) && (BNtableau[ligne][colonne] <= 5)) {
                        nbbateau++;
                    }
                }
            }
            printf("\n\nil vous reste %d case(s)", nbbateau);
        } while (nbbateau > 5);
        return 0;
    }
    }
}







































