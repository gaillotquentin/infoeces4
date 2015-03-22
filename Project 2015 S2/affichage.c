#include "affichage.h"
#include "compalleg.h"
#include <stdio.h>
#include <stdlib.h>

///Affichafe de la grille sur la page
void affichage_grille_page()
{
    int i=0;

    for(i=0 ; i<=NOMBRE_CASE_LARGEUR ;i++)
    {
        line(page,i*DIM_PIXEL,0,i*DIM_PIXEL,FENETRE_HAUTEUR,makecol(120,120,120));
    }

    for(i=0 ; i<=NOMBRE_CASE_HAUTEUR ;i++)
    {
        line(page,0,i*DIM_PIXEL,FENETRE_LARGEUR,i*DIM_PIXEL,makecol(120,120,120));
    }
}

///Affichage de la matrice de jeu
void affichage_matrice_jeu(t_matrice_jeu *m)
{
    int i,j;

    //effacer tout.
    effacer_page();

    //Afficher la grille de jeu.
    affichage_grille_page();

    //Affichage de tout les batiments !
    for(i=0 ; i<NOMBRE_CASE_LARGEUR ; i++)
    {
        for(j=0 ; j<NOMBRE_CASE_HAUTEUR ; j++)
        {
            //affichage des routes uniquement.
            affichage_route(m,i,j);

            affichage_habitation(m,i,j);
            //affichage .. etc ...
        }
    }

    //Afficher le buffer
    afficher_page();
}

//Affichage des routes sur la matrice
void affichage_route(t_matrice_jeu *m, int i, int j)
{
    if(m->matjeu[i][j].nom == 'r')
            {
                rectfill(page,i*DIM_PIXEL, j*DIM_PIXEL,(i+1)*DIM_PIXEL,(j+1)*DIM_PIXEL,makecol(0,0,0));
            }
}

//Affichage d'une habitation
void affichage_habitation(t_matrice_jeu *m, int i, int j)
{
    if(m->matjeu[i][j].nom == 'h')
            {
                rectfill(page,i*DIM_PIXEL, j*DIM_PIXEL,(i+1)*DIM_PIXEL,(j+1)*DIM_PIXEL,makecol(255,0,0));
            }
}
