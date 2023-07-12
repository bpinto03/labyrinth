#ifndef __Graphique__
#define __Graphique__

#include "Labyrinthe.h"

void tracer_laby(Labyrinthe laby, int taillefx, int taillefy);

void afficher_laby(Labyrinthe laby, int taillefx, int taillefy);

void trace_contours(Labyrinthe laby, int taille_case_horiz, int taille_case_vert);

void trace_murs(Labyrinthe laby, int taille_case_horiz, int taille_case_vert);


#endif