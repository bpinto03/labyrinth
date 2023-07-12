#ifndef __Union__
#define __Union__

#include "Cellule.h"

typedef struct unionfind_t{
    Cellule taille;
    Cellule **pere;
    unsigned int **rang;
}Unionfind_t;

/*initialise une structure unionfind_t
*:parametres: adresse de structure unionfind_t, Cellule taille
*:retour: 1 si pas de problème d'allocation 0 sinon*/
int init_union(Unionfind_t *union_t, Cellule taille);

/*Trouve le pere de cell dans une structure tableau de cellule
*:parametres: Unionfind_t union_t, Cellule cell
*:retour: Cellule pere de cell*/
Cellule TrouveCompresse(Cellule **pere, Cellule cell);

/*Fusionne la cellule cell1 et cell2 en optimisant avec le rang
*:parametres: Unionfind_t struct unionfind , Cellule cell1 cell2
:retour: void*/
void FusionRang(Unionfind_t *union_t, Cellule cell1, Cellule cell2);

/*Vérifie si un chemin existe entre cell1 et cell2 dans un labyrinthe
*:parametres: Unionfind_t structure unionfind
*:retour: int 1 si un chemin est valide 0 sinon*/
int chemin_valide(Unionfind_t union_t, Cellule cell1, Cellule cell2);

#endif
