#include <stdio.h>
#include "Texte.h"

void afficher_laby_texte(Labyrinthe laby){
    int i, j;
    for(i = 0; i < laby.taille.ligne * 2; i++){
        for(j = 0; j < laby.taille.colonne; j++){
            if(i % 2 == 0){
                printf("+");
                if(i == 0 || laby.murs_horiz[i / 2 - 1][j] == 1)
                    printf("---");
                else
                    printf("   ");
            }
            else{
                if((i != 1 && j == 0) || laby.murs_vert[i / 2][j - 1] == 1)
                    printf("|   ");
                else
                    printf("    ");
            }
        }
        if(i % 2 == 0)
            printf("+");
        else if(i != laby.taille.ligne * 2 - 1)
            printf("|");
        printf("\n");
    }
    for(i = 0; i < laby.taille.colonne; i++){
        printf("+---");
    }

    printf("+\n");
}
