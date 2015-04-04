#include "outils.h"

t_outils* allocation_outils()
{
    BITMAP* outils_btm;
    outils_btm=create_bitmap(FENETRE_LARGEUR-NOMBRE_CASE_LARGEUR*DIM_PIXEL, FENETRE_HAUTEUR);
    clear_to_color(outils_btm, makecol(220,220,220));

    t_outils* outils;
    outils=malloc_safe(sizeof(t_outils));

    outils->outils_btm=outils_btm;
    outils->nombre_outils=0;

    return outils;
}

void affichage_outils(t_outils* outils)
{
    blit(outils->outils_btm,page,0,0,0,0,outils->outils_btm->w,outils->outils_btm->h);
}
