#include <stdlib.h>
#include "Labyrinthe.h"

int init_laby(Labyrinthe *laby, Cellule taille){
    laby->taille = taille;
    init_murs(&(laby->murs_vert), taille.colonne - 1, taille.ligne);
    init_murs(&(laby->murs_horiz), taille.colonne, taille.ligne - 1);
    return 1;
}

int init_murs(int ***murs, int largeur, int hauteur){
    int i, j;

    if((*murs = malloc(sizeof(int *) * hauteur)) == NULL)
        return 0;

    for(i = 0; i < hauteur; i++)
        if(((*murs)[i] = malloc(sizeof(int) * largeur)) == NULL)
            return 0;

    for(i = 0; i < hauteur; i++)
        for(j = 0; j < largeur; j++)
            (*murs)[i][j] = 1;
    return 1;
}

int supprime_mur(Labyrinthe *laby, Cellule cell1, Cellule cell2){
    if(cell1.ligne == cell2.ligne - 1){
        if(laby->murs_horiz[cell1.ligne][cell1.colonne] == 0)
            return 0;
        laby->murs_horiz[cell1.ligne][cell1.colonne] = 0;
    }
    else if(cell1.ligne == cell2.ligne + 1){
      if(laby->murs_horiz[cell2.ligne][cell2.colonne] == 0)
          return 0;
        laby->murs_horiz[cell2.ligne][cell2.colonne] = 0;
    }
    else if(cell1.colonne == cell2.colonne - 1){
        if(laby->murs_vert[cell1.ligne][cell1.colonne] == 0)
            return 0;
        laby->murs_vert[cell1.ligne][cell1.colonne] = 0;
    }
    else{
        if(laby->murs_vert[cell2.ligne][cell2.colonne] == 0)
            return 0;
        laby->murs_vert[cell2.ligne][cell2.colonne] = 0;
    }
    return 1;
}

void supprime_mur_alea_opti(Labyrinthe *laby, Unionfind_t *union_t, unsigned int unique){
    Cellule cell1, cell2, vois[4];
    do{
        cell1 = cellule_alea(laby->taille.colonne, laby->taille.ligne);
        cellules_voisines(vois, laby->taille.colonne, laby->taille.ligne, cell1);
        cell2 = cellules_voisine_alea(vois);
    /*Regenere une cellule si on ne peut pas la supprimer*/
    }while((unique == 1 && chemin_valide(*union_t, cell1, cell2)) || supprime_mur(laby, cell1, cell2) == 0);
    FusionRang(union_t, cell1, cell2);
}

int supprime_mur_alea(Labyrinthe *laby, Unionfind_t *union_t, unsigned int unique){
    Cellule cell1, cell2, vois[4];
    cell1 = cellule_alea(laby->taille.colonne, laby->taille.ligne);
    cellules_voisines(vois, laby->taille.colonne, laby->taille.ligne, cell1);
    cell2 = cellules_voisine_alea(vois);
    if(unique == 1 && chemin_valide(*union_t, cell1, cell2))
        return 0;
    supprime_mur(laby, cell1, cell2);
    FusionRang(union_t, cell1, cell2);
    return 1;
}
