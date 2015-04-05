#include "bibliotheque.h"

t_donnees* allocation_donnees()
{
    BITMAP* donnees_btm;
    donnees_btm=create_bitmap(NOMBRE_CASE_LARGEUR*DIM_PIXEL, FENETRE_HAUTEUR-NOMBRE_CASE_HAUTEUR*DIM_PIXEL);
    clear_to_color(donnees_btm, makecol(220,220,220));

    t_donnees* donnees;
    donnees=malloc_safe(sizeof(t_outils));

    donnees->donnees_btm=donnees_btm;

    return donnees;
}

void affichage_donnees(t_donnees* donnees)
{
    blit(donnees->donnees_btm,page,0,0,FENETRE_LARGEUR-NOMBRE_CASE_LARGEUR*DIM_PIXEL,NOMBRE_CASE_HAUTEUR*DIM_PIXEL,donnees->donnees_btm->w,donnees->donnees_btm->h);
}
