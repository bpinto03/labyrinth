#ifndef __Cellule__
#define __Cellule__

typedef struct cellule{
    int ligne;
    int colonne;
    int vide;
}Cellule;

/*Initialise une cellules
*:parametres: int ligne/colonne
:retour: Cellule cell initialisée*/
Cellule init_cellule(int ligne, int colonne);

/*Verifie si deux cellule sont égales
*:parametres: Cellule cell1/cell2
*:retour: 1 si cell1 = cell2 0 sinon*/
int compare_cellule(Cellule cell1, Cellule cell2);

/*Initialise une liste de cellules voisines à une cellule(ligne, colonne)
*:parametres: Liste de cellule, int largeur/hauteur maximale pour les lignes et colonnes, Cellule cellule
*dont les voisins vont être initialisés
*:retour: void*/
void cellules_voisines(Cellule vois[4], int largeur, int hauteur, Cellule cell);

/*Génére une cellule aléatoire avec comme coordonnées maximum largeur et hauteur
*:parametres: int largeur/hauteur
*:retour: Cellule cellule aleatoire*/
Cellule cellule_alea(int largeur, int hauteur);

/*Choisit une cellule voisine aleatoire*/
Cellule cellules_voisine_alea(Cellule vois[4]);

#endif
