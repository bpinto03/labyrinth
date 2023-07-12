#ifndef __Option__
#define __Option__

#include "Cellule.h"

/*Gere les options en modifiant le contenu des adresses des variales
*:parametres: char *argv texte option, unsigned int *adresse options, Cellule *taille adresse taille, int *attente
*:retour: void*/
void gest_option(char *argv, unsigned int *graphique, Cellule *taille, int *attente, unsigned int *unique, unsigned int *acces, unsigned int *opti);

#endif
