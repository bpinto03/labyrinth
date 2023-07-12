#include <stdlib.h>
#include <stdio.h>
#include "Graphique.h"
#include <MLV/MLV_all.h>

void trace_contours(Labyrinthe laby, int taille_case_horiz, int taille_case_vert){

    /*
    t_x_max = taille de la longueur de la fenetre
    t_y_max = taille de la largeur de la fenetre
    */

    int t_x_max, t_y_max;
    int i; 
    
    t_x_max = (laby.taille.colonne)*taille_case_horiz;
    t_y_max = (laby.taille.ligne)*taille_case_vert;

    /*Bordure haut*/

    MLV_draw_line(0, 0, t_x_max, 0, MLV_COLOR_RED);

    /*Bordure bas*/

    MLV_draw_line(0, t_y_max, t_x_max, t_y_max, MLV_COLOR_RED);

    /*Bordure gauche*/

    MLV_draw_line(0, taille_case_vert, 0, t_y_max,MLV_COLOR_RED);

    /*Bordure droite*/

    MLV_draw_line(t_x_max, 0, t_x_max, t_y_max-taille_case_vert,MLV_COLOR_RED);
}

void trace_murs(Labyrinthe laby, int taille_case_horiz, int taille_case_vert){
	int i,j, diff, diff2;
    diff = 0;
    diff2 = 0;

    if(laby.taille.ligne > laby.taille.colonne){
        diff = laby.taille.ligne - laby.taille.colonne;
    }

    if(laby.taille.ligne < laby.taille.colonne){
        diff2 = laby.taille.colonne - laby.taille.ligne;
    }
    /**/
	for(i=0; i < laby.taille.colonne+diff; i++){
        /**/
		for(j=0; j < laby.taille.ligne+diff2; j++){
            if(i < laby.taille.ligne-1){
                if(laby.murs_horiz[i][j] == 1){
                    MLV_draw_line(j*taille_case_horiz, (i+1)*taille_case_vert, (j*taille_case_horiz)+taille_case_horiz, (i+1)*taille_case_vert, MLV_COLOR_YELLOW);
                }
            }
            if(i < laby.taille.ligne){
        		if(laby.murs_vert[i][j] == 1){
                    MLV_draw_line((j+1)*taille_case_horiz, i*taille_case_vert, (j+1)*taille_case_horiz, (i*taille_case_vert)+taille_case_vert, MLV_COLOR_YELLOW);             
                }
            }
		}
	}
}

void tracer_laby(Labyrinthe laby, int taillefx, int taillefy){
	int taille_case_horiz, taille_case_vert;
	taille_case_horiz = taillefx / laby.taille.colonne;
	taille_case_vert = taillefy / laby.taille.ligne;
	trace_contours(laby,taille_case_horiz,taille_case_vert);
	trace_murs(laby,taille_case_horiz,taille_case_vert);
}

void afficher_laby(Labyrinthe laby, int taillefx, int taillefy){
	tracer_laby(laby, taillefx, taillefy);
	MLV_actualise_window();
}

