#include <stdlib.h>
#include "Union.h"

int init_union(Unionfind_t *union_t, Cellule taille){
    int i, j;
    union_t->taille = taille;
    if((union_t->pere = malloc(sizeof(Cellule *) * taille.ligne)) == NULL || (union_t->rang = malloc(sizeof(unsigned int *) * taille.ligne)) == NULL)
        return 0;

    for(i = 0; i < taille.ligne; i++)
        if((union_t->pere[i] = malloc(sizeof(Cellule) * taille.colonne)) == NULL || (union_t->rang[i] = malloc(sizeof(unsigned int) * taille.colonne)) == NULL)
             return 0;

    for(i = 0; i < taille.ligne; i++)
        for(j = 0; j < taille.colonne; j++){
            union_t->pere[i][j].ligne = i;
            union_t->pere[i][j].colonne = j;
            union_t->rang[i][j] = 0;
        }
    return 1;
}

Cellule TrouveCompresse(Cellule **pere, Cellule cell){
    Cellule res;
    if(compare_cellule(pere[cell.ligne][cell.colonne], cell))
        return cell;
    res = TrouveCompresse(pere, pere[cell.ligne][cell.colonne]);
    pere[cell.ligne][cell.colonne] = res;
    return res;
}

void FusionRang(Unionfind_t *union_t, Cellule cell1, Cellule cell2){
    Cellule pere_cell1, pere_cell2;
    pere_cell1 = TrouveCompresse(union_t->pere, cell1);
    pere_cell2 = TrouveCompresse(union_t->pere, cell2);

    if(!(compare_cellule(pere_cell1, pere_cell2))){
        if(union_t->rang[pere_cell1.ligne][pere_cell1.colonne] > union_t->rang[cell2.ligne][cell2.colonne]){
            union_t->pere[pere_cell2.ligne][pere_cell2.colonne] = cell1;
        }
        if(union_t->rang[pere_cell1.ligne][pere_cell1.colonne]  < union_t->rang[cell2.ligne][cell2.colonne] ){
            union_t->pere[pere_cell1.ligne][pere_cell1.colonne] = cell2;
        }
        if (union_t->rang[pere_cell1.ligne][pere_cell1.colonne] == union_t->rang[cell2.ligne][cell2.colonne]){
            union_t->pere[pere_cell2.ligne][pere_cell2.colonne] = cell1;
            union_t->rang[pere_cell1.ligne][pere_cell1.colonne]++;
        }

    }
}

int chemin_valide(Unionfind_t union_t, Cellule cell1, Cellule cell2){
    Cellule entree, sortie, pere_entree, pere_sortie;
    entree = init_cellule(cell1.ligne, cell1.colonne);
    sortie = init_cellule(cell2.ligne, cell2.colonne);

    pere_entree = TrouveCompresse(union_t.pere, entree);
    pere_sortie = TrouveCompresse(union_t.pere, sortie);

    if(compare_cellule(pere_entree, pere_sortie))
        return 1;
    return 0;
}
