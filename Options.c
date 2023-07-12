#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Options.h"

void gest_option(char *argv, unsigned int *graphique, Cellule *taille, int *attente, unsigned int *unique, unsigned int *acces, unsigned int *opti){
    unsigned int k, j, graine;
    char ligne[5], colonne[5], graine_char[10], attente_char[20], opti_char[2];

    j = 9;
    k = 0;
    if(strcmp("--mode=texte", argv) == 0){
        *graphique = 0;
        return;
    }
    if(strncmp("--taille=", argv, 9) == 0){
        do{
            if(argv[j] != 'x')
                if(k == 0)
                    ligne[j - 9] = argv[j];
                else
                    colonne[j - k] = argv[j];

            else
                k = j + 1;
            j++;
        }while(j < 16 && argv[j] != '\0');
        ligne[5] = '\0';
        colonne[j - k] = '\0';
        taille->ligne = atoi(ligne);
        taille->colonne = atoi(colonne);
        return;
    }
    if(strncmp("--graine=", argv, 9) == 0){
        while(argv[j] != '\0'){
            graine_char[j - 9] = argv[j];
            j++;
        }
        graine_char[10] = '\0';
        graine = atoi(graine_char);
        srand(graine);
        return;
    }
    if(strncmp("--attente=", argv, 10) == 0){
        j++;
        while(argv[j] != '\0'){
            attente_char[j - 10] = argv[j];
            j++;
        }
        attente_char[20] = '\0';
        *attente = atoi(attente_char) * 10000;
        return;
    }
    if(strcmp("--unique", argv) == 0){
        *unique = 1;
        return;
    }
    if(strcmp("--acces", argv) == 0){
        *acces = 1;
        return;
    }
    if(strncmp("--opti=", argv, 7) == 0){
        opti_char[0] = argv[7];
        opti_char[1] = '\0';
        *opti = atoi(opti_char);
        if(*opti != 0)
            *attente = 0;
        return;
    }
}
