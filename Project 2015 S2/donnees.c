#include "bibliotheque.h"


t_donnees* allocation_donnees()
{
    BITMAP* donnees_bmp;
    donnees_bmp=create_bitmap(NOMBRE_CASE_LARGEUR*DIM_PIXEL, FENETRE_HAUTEUR-NOMBRE_CASE_HAUTEUR*DIM_PIXEL);
    clear_to_color(donnees_bmp, makecol(220,220,220));

    t_donnees* donnees;
    donnees=malloc_safe(sizeof(t_outils));

    donnees->donnees_bmp=donnees_bmp;

    return donnees;
}

void affichage_donnees(t_donnees* donnees)
{
    blit(donnees->donnees_bmp,page,0,0,FENETRE_LARGEUR-NOMBRE_CASE_LARGEUR*DIM_PIXEL,NOMBRE_CASE_HAUTEUR*DIM_PIXEL,donnees->donnees_bmp->w,donnees->donnees_bmp->h);
}
