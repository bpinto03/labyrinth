#include <stdlib.h>
#include "Cellule.h"

Cellule init_cellule(int ligne, int colonne){
    Cellule cell;
    cell.ligne = ligne;
    cell.colonne = colonne;
    cell.vide = 0;
    return cell;
}

int compare_cellule(Cellule cell1, Cellule cell2){
    if((cell1.ligne == cell2.ligne) && cell1.colonne == cell2.colonne)
        return 1;
    return 0;
}

void cellules_voisines(Cellule vois[4], int largeur, int hauteur, Cellule cell){
    int i;
    vois[0] = init_cellule(cell.ligne - 1, cell.colonne);
    vois[1] = init_cellule(cell.ligne, cell.colonne + 1);
    vois[2] = init_cellule(cell.ligne + 1, cell.colonne);
    vois[3] = init_cellule(cell.ligne, cell.colonne - 1);

    for(i = 0; i < 4; i++){
        if(vois[i].colonne < 0 || largeur - 1 < vois[i].colonne)
            vois[i].vide = 1;
        if(vois[i].ligne < 0 || hauteur - 1 < vois[i].ligne)
            vois[i].vide = 1;
    }
}

Cellule cellule_alea(int largeur, int hauteur){
    return init_cellule(rand() % hauteur, rand() % largeur);
}

Cellule cellules_voisine_alea(Cellule vois[4]){
    int i;
    do{
        i = rand() % 4;
    }
    while(vois[i].vide == 1);
    return vois[i];

}
