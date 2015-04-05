#include "bibliotheque.h"


///Affichafe de la grille sur la page
void affichage_grille_page(t_matrice_jeu* m)
{
    int i=0;
    for(i=0 ; i<=NOMBRE_CASE_LARGEUR ;i++)
    {
        line(m->matrice_btm,i*DIM_PIXEL,0,i*DIM_PIXEL,FENETRE_HAUTEUR,makecol(120,120,120));
    }

    for(i=0 ; i<=NOMBRE_CASE_HAUTEUR ;i++)
    {
        line(m->matrice_btm,0,i*DIM_PIXEL,FENETRE_LARGEUR,i*DIM_PIXEL,makecol(120,120,120));
    }
    blit(m->matrice_btm, page,0,0,FENETRE_LARGEUR-NOMBRE_CASE_LARGEUR*DIM_PIXEL,0,m->matrice_btm->w,m->matrice_btm->h);
}

///Affichage de la matrice de jeu
void affichage_matrice_jeu(t_matrice_jeu *m)
{
    int i,j;

    //effacer tout.
    effacer_page();
    clear_to_color(m->matrice_btm, makecol(255,255,255));

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

    //Afficher la grille de jeu.
    affichage_grille_page(m);

    //Afficher le buffer
//    afficher_page();
}

//Affichage des routes sur la matrice
void affichage_route(t_matrice_jeu *m, int i, int j)
{

    if(m->matjeu[i][j].nom == 'r')
            {
                rectfill(m->matrice_btm,i*DIM_PIXEL, j*DIM_PIXEL,(i+1)*DIM_PIXEL,(j+1)*DIM_PIXEL,makecol(0,0,0));
            }
}

//Affichage d'une habitation
void affichage_habitation(t_matrice_jeu *m, int i, int j)
{
    if(m->matjeu[i][j].nom == 'h')
            {
                rectfill(m->matrice_btm,i*DIM_PIXEL, j*DIM_PIXEL,(i+1)*DIM_PIXEL,(j+1)*DIM_PIXEL,makecol(255,0,0));
            }
}

void affichage_page()
{
    //On copie la page sur le screen à chaque tour de boucle.
    afficher_page();
}

