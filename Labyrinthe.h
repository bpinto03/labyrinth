#ifndef __Labyrinthe__
#define __Labyrinthe__

#include "Cellule.h"
#include "Union.h"

typedef struct labyrinthe{
    Cellule taille;
    int **murs_horiz;
    int **murs_vert;
}Labyrinthe;

/*Initialise un labyrinthe
*:parametres: adresse du labyrinthe à initialisé, Cellule taille du labyrinthe
*:retour: int, 0 s'il y a eu un probleme d'allocation 1 sinon*/
int init_laby(Labyrinthe *laby, Cellule taille);

/*Initialise un tableau d'int representant
*les murs du labyrinthe, 1 = mur, 0 = pas de mur
*:parametres: adresse de tableau d'int, int largeur / longueur
*:retour: int, 0 s'il y a eu un probleme d'allocation 1 sinon*/
int init_murs(int ***murs, int largeur, int hauteur);

/*Supprime le mur entre cell1 et cell2
:parametres: Adresse labyrinthe, Cellule cell1/cell2
:retour: 1 si le mur n'est pas deja supprime 0 sinon*/
int supprime_mur(Labyrinthe *laby, Cellule cell1, Cellule cell2);

/*Supprime un mur aleatoire dans labyrinthe non optimise
*:parametres: Labyrinthe adresse d'un labyrinthe, Unionfind_t Adresse structure union find, unsigned int option unique
*:retour: 1 si le mur a ete supprimer 0 sinon*/
int supprime_mur_alea(Labyrinthe *laby, Unionfind_t *union_t, unsigned int unique);

/*Supprime un mur aleatoire dans labyrinthe optimise
*:parametres: Labyrinthe adresse d'un labyrinthe, Unionfind_t Adresse structure union find, unsigned int option unique
*:retour: 1 si le mur a ete supprimer 0 sinon*/
void supprime_mur_alea_opti(Labyrinthe *laby, Unionfind_t *union_t, unsigned int unique);
#endif
