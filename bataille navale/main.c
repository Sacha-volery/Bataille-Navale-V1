//Sacha Volery
//Exercice Bataille navale
//14.02.2022

#include <stdio.h>
#include <time.h>
#include <windows.h>

char Pseudo[30];
int nbtire;
int nbbateau;
char RepCol[] = "A";
int colonne;
int choix;
int ligne;
int variableAlea;

int Grille[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

void afficheFichier(char nomFichier[]) {
    //Cette fonction affiche le fichier texte
    //dont le nom est passé par la variable "nomFichier"
    char chaine[50] = "";//pour lire une ligne, longueur max 50
    FILE *fichier = NULL; // pointeur sur le fichier
    //ouverture du fichier en mode lecture seule
    fichier = fopen(nomFichier, "r");
    // teste si le fichier existe
    if (fichier == NULL) {
        printf("Le fichier n'existe pas!\n");
    } else {
        //lecture de la ligne suivante
        printf("\n*********************************************************\n");
        while (fgets(chaine, 50, fichier)) {
            printf("%s", chaine);//affichage ligne (y compris fin de ligne)
        }
        printf("\n*********************************************************\n");
        fclose(fichier); // fermeture du fichier
    }
}

void ajouteFichier(char nomFichier[], char ligne[]) {
    //Cette fonction ouvre le fichier nomFichier
    // et ajoute une ligne avec la chaine ligne[]
    FILE *fichier = NULL; // pointeur sur le fichier
    //ouverture du fichier en mode lecture seule
    fichier = fopen(nomFichier, "a");
    // teste si le fichier existe
    if (fichier == NULL) {
        printf("Le fichier n'existe pas!\n");
    } else {
        //Ecrire un saut de ligne puis la ligne
        fputs("\n", fichier);
        fputs(ligne, fichier);
        fclose(fichier); // fermeture du fichier
    }
}


void dateHeure(char chaine[]) {
    //Cette fonction va chercher la date et l'heure et l'écrit dans la variable qu'on lui donne
    time_t now;
    int h, min, s, day, month, year;//pour récupérer chaque détail

    time(&now);// Renvoie l'heure actuelle
    struct tm *local = localtime(&now);//structure qui contient chaque détail de l'heure
    h = local->tm_hour;
    min = local->tm_min;
    s = local->tm_sec;
    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;

    // Ecrire dans la chaine les détails du genre 28/03/2022 11:52:05
    sprintf(chaine, "%02d/%02d/%04d %02d:%02d:%02d", day, month, year, h, min, s);

}

void ajouteFichierAvecHeure(char nomFichier[]) {
    char dateheure[20] = "";//chaine pour écrire l'heure
    char saisie2[50] = "";

    //récupération de l'heure
    dateHeure(dateheure);
    //Concaténation heure + saisie
    sprintf(saisie2, "%s  %s | %d Tirs | ", dateheure,Pseudo,nbtire);
    //Ecriture dans le fichier
    ajouteFichier("../Score/Score.txt", saisie2);
}

void debutprogramme() {
    char dateheure[20] = "";//chaine pour écrire l'heure
    char saisie2[50] = "";

    //récupération de l'heure
    dateHeure(dateheure);
    //Concaténation heure + saisie
    sprintf(saisie2, "début du jeu: %s", dateheure);
    //Ecriture dans le fichier
    ajouteFichier("../Log.txt", saisie2);
}

void Finprogramme() {
    char dateheure[20] = "";//chaine pour écrire l'heure
    char saisie2[50] = "";

    //récupération de l'heure
    dateHeure(dateheure);
    //Concaténation heure + saisie
    sprintf(saisie2, "Fin du jeu: %s ", dateheure);
    //Ecriture dans le fichier
    ajouteFichier("../Log.txt", saisie2);
}

int lectureFichierVersTableau(char nomFichier[]) {
    //Cette procédure lit le fichier nomFichier (ex: ../BN1.txt dans le répertoire du main.c)
    //on s'attend à un fichier du genre:
    // 0011111000
    // 0000033000... etc
    //et le transforme en fichier BN[10][10]
    char chaine[20];
    FILE *fichier = NULL; // pointeur sur le fichier
    //ouverture du fichier en mode lecture seule
    fichier = fopen(nomFichier, "r");
    // teste si le fichier existe
    if (fichier == NULL) {
        printf("Le fichier n'existe pas!\n");
    } else {
        int ligne = 0;
        //lecture de la ligne suivante (de 0 à 9 max)
        while (fgets(chaine, 20, fichier) && ligne < 10) {
            int co = 0;
            //la boucle s'arrête soit quand on est à 9, soit quand ce n'est pas un chiffre
            while (co < 10 && chaine[co] >= 48 && chaine[co] <= 57) {
                Grille[ligne][co] = chaine[co] - 48;
                co++;
            }
            ligne++;
        }
        fclose(fichier); // fermeture du fichier
    }
}


int main() {
    SetConsoleOutputCP(65001);


    printf("\n                          Bataille Navale"
           "\n                       Créée par Sacha Volery"
           "\n            ___________________________________________");

    {

        printf("\n");
        printf("\n");

    }

    printf("\n");
    printf("\n");

    do {
        //Affichage du menu
        printf("    Quel mode voulez-vous ? \n", Pseudo);
        printf("    1 : Arrêter le programme\n");
        printf("    2 : Didacticiel\n");
        printf("    3 : Jouer contre l'ordinateur\n");
        printf("    4 : Visualiser le score\n");
        scanf("%d", &choix);


        switch (choix) {
            //case qui arrete le jeu
            case 1:
                printf("    Vous avez arreté le jeu !");
                exit(0);

            //case qui affiche le didacticiel
            case 2:
                printf("    Voici les règles du jeu :");
                printf("    \n\nLa bataille navale oppose deux joueurs qui s'affrontent. "
                       "\nLe but du jeu est de placer une flotte composée de 5 bateaux sur sa grille "
                       "\net de couler les 5 bateaux de notre adversaire en tirant sur sa grille."
                       "\n\nLes bateaux sont les suivants :"
                       "\n\n1 porte-avion (5 cases)"
                       "\n1 croiseur (4 cases)"
                       "\n1 contre-torpilleur (3 cases)"
                       "\n1 sous-marin (2 cases)"
                       "\n1 torpilleur (2 cases)"
                       "\n\nVoici les codes utilisés pour le résultat de chaque tir : "
                       "\n\ntouché = x "
                       "\ntiré dans l'eau = o \n\n");

                break;
            //case qui fais marcher le mode jouer contre l'ordinateur
            case 3 :
                debutprogramme();
                printf("Voici le mode jouer seul :\n");

                srand(time(NULL));
                variableAlea = rand() % 5 + 1;
                char nomfichier[30];
                sprintf(nomfichier, "../BNGrille/Grille%d.txt", variableAlea);
                lectureFichierVersTableau(nomfichier);
                printf(" %s", nomfichier);
                // affichage la grille pour que la personne choissise ou tirer
                printf("\n\n    A   B   C   D   E   F   G   H   I   J \n"
                       "1  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                       "2  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                       "3  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                       "4  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                       "5  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                       "6  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                       "7  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                       "8  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                       "9  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n"
                       "10 [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]\n");
                do {
                    //Sa nous choisis la ligne et la collone quand veut mettre
                    printf("\nChoisir une colonne entre A-J !");
                    scanf("%s", &RepCol);
                    RepCol[0] = RepCol[0] & (0xFF - 0x20);
                    colonne = RepCol[0] - 65;
                    printf("\nChoisir une ligne entre 1-10 !");
                    scanf("%d", &ligne);
                    ligne -= 1;
                    nbtire++;
                    //Mise à jour tableau
                    if (Grille[ligne][colonne] < 10)
                        Grille[ligne][colonne] += 10;

                    //Affichage du tableau
                    printf("\n    A | B | C | D | E | F | G | H | I | J |");
                    for (int ligne = 0; ligne < 10; ligne++) {
                        printf("\n");
                        printf("%2d", ligne + 1);
                        for (int colonne = 0; colonne < 10; colonne++) {
                            if (Grille[ligne][colonne] < 10) {
                                printf(" [ ]");
                            }
                            if (Grille[ligne][colonne] == 10) {
                                printf(" [o]");
                            }
                            if (Grille[ligne][colonne] > 10) {
                                printf(" [x]");
                            }
                            if (Grille[ligne][colonne] > 20) {
                                printf(" [$]");
                            }
                        }
                    }
                    //Quand c'est fini la bataille s'arrête
                    nbbateau = 0;
                    for (int ligne = 0; ligne < 10; ligne++) {
                        for (int colonne = 0; colonne < 10; colonne++) {
                            if ((Grille[ligne][colonne] >= 1) && (Grille[ligne][colonne] <= 5)) {
                                nbbateau++;
                            }
                        }
                    }
                    //Sa sert a afficher le nombre de case a toucher et le nombre de fois qu'on a tiré
                    printf("\n\nIl vous reste  %d case(s) à toucher", nbbateau);
                    printf("\nVous avez tiré %d fois", nbtire);
                } while (nbbateau > 0);
                Finprogramme();
                //Sa affiche quand a fini le jeu et en combien de coups on a fini la partie
                printf("\n\nBien joué tu as gagné tu as coulé tous les bateaux adverses , avec %d tirs", nbtire);
                printf("\n\nMaintenant entrez votre pseudo (sans accent s'il vous plait ");
                scanf("%s", &Pseudo);
                ajouteFichierAvecHeure("../Score/Score.txt");
                main();
                break;

                //la case pour le score
                 case 4:
                afficheFichier("../Score/Score.txt");
                break;

        }
    } while (choix > 0);
    return 0;
}

