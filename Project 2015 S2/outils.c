#include "bibliotheque.h"

t_outils* allocation_outils()
{
    BITMAP* outils_bmp;
    outils_bmp=create_bitmap(FENETRE_LARGEUR-NOMBRE_CASE_LARGEUR*DIM_PIXEL, FENETRE_HAUTEUR);
    clear_to_color(outils_bmp, makecol(220,220,220));

    t_outils* outils;
    outils=malloc_safe(sizeof(t_outils));

    outils->outils_bmp=outils_bmp;
    outils->outils_bmp=load_bitmap("outils.bmp",NULL);
    outils->outils_courant=0;

    return outils;
}

void affichage_outils(t_outils* outils)
{
    blit(outils->outils_bmp,page,0,0,0,0,outils->outils_bmp->w,outils->outils_bmp->h);
}

int selection_outils(t_outils* outils)
{
    if(mouse_click)
    {
        if(mouse_x>=12 && mouse_x<=95)
        {
            if(mouse_y>=25 && mouse_y<=100)
                return OUTILS_HABITATION;
            if(mouse_y>=107 && mouse_y<=185)
                return OUTILS_ELEC;
            if(mouse_y>=194 && mouse_y<=261)
                return OUTILS_EAU;
            if(mouse_y>=263 && mouse_y<=340)
                return OUTILS_ROUTE;
        }
        else
            return outils->outils_courant;
    }
    else
        return outils->outils_courant;
}
