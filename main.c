#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <unistd.h>
#include <time.h>

#include "Options.h"
#include "Labyrinthe.h"
#include "Union.h"
#include "Texte.h"
#include "Graphique.h"

#define TAILLEFX 800
#define TAILLEFY 800

int main(int argc, char *argv[]){
    unsigned int i, graphique, unique, compteur_suppr, acces, opti;
    int attente;
    long int debut, fin;
    char touche;
    Cellule taille, entree, sortie;
    Labyrinthe laby;
    Unionfind_t union_t;
    MLV_Event event;

    srand(time(NULL));
    taille = init_cellule(6, 8);
    entree = init_cellule(0, 0);
    graphique = 1;
    attente = -1;
    acces = 0;
    unique = 0;
    compteur_suppr = 0;
    opti = 0;
    /*Gestion des options*/
    for(i = 1; i < argc; i++){
        gest_option(argv[i], &graphique, &taille, &attente, &unique, &acces, &opti);
    }
    sortie = init_cellule(taille.ligne - 1, taille.colonne - 1);
    if(!init_laby(&laby, taille)|| !init_union(&union_t, taille)){
        printf("Plus de mémoire disponible pour initialiser un labyrinthe.\n");
        exit(EXIT_FAILURE);
    }
    if(!graphique)
        afficher_laby_texte(laby);
    else{
        MLV_create_window("Labyrinthe", "main", TAILLEFX + 1, TAILLEFY + 1);
        afficher_laby(laby, TAILLEFX, TAILLEFY);
        MLV_actualise_window();
    }
    debut = time(NULL);
    while(!chemin_valide(union_t, entree, sortie) || (acces && compteur_suppr < taille.ligne * taille.colonne - 1)){
        if(attente == -1){
            if(!graphique){
                touche = 0;
                scanf(" %c", &touche);
            }
            else{
                event = MLV_get_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
            }
        }
        if(attente != -1 || (!graphique && touche != 0) || (graphique && event == MLV_KEY)){
            if(opti != 2){
                compteur_suppr++;
                supprime_mur_alea_opti(&laby, &union_t, unique);
            }
            else
                compteur_suppr += supprime_mur_alea(&laby, &union_t, unique);
            if(opti == 0 && attente == -1){
                if(!graphique)
                    afficher_laby_texte(laby);
                else{
                    MLV_clear_window(MLV_COLOR_BLACK);
                    afficher_laby(laby, TAILLEFX, TAILLEFY);
                    MLV_actualise_window();
                }
            }
        }
        if(attente != -1)
            usleep(attente);
    }
    fin = time(NULL);
    if(!graphique)
        afficher_laby_texte(laby);
    else{
        MLV_clear_window(MLV_COLOR_BLACK);
        afficher_laby(laby, TAILLEFX, TAILLEFY);
        MLV_actualise_window();
        MLV_wait_seconds(5);
    }

    if(opti != 0)
        printf("\n\nExecution en %ld secondes\n", fin - debut);
    return 0;
}
