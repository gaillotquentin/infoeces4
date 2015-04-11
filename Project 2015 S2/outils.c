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
    outils->affichage=AFFICHAGE_0;

    return outils;
}

void affichage_outils(t_outils* outils)
{
    blit(outils->outils_bmp,page,0,0,0,0,outils->outils_bmp->w,outils->outils_bmp->h);
    if(outils->outils_courant==OUTILS_HABITATION)
        rect(outils->outils_bmp,12,25,95,100,makecol(76,76,76));
    else
        rect(outils->outils_bmp,12,25,95,100,makecol(220,220,220));

    if(outils->outils_courant==OUTILS_ELEC)
        rect(outils->outils_bmp,12,107,95,185,makecol(76,76,76));
    else
        rect(outils->outils_bmp,12,107,95,185,makecol(220,220,220));

    if(outils->outils_courant==OUTILS_EAU)
        rect(outils->outils_bmp,12,194,95,261,makecol(76,76,76));
    else
        rect(outils->outils_bmp,12,194,95,261,makecol(220,220,220));

    if(outils->outils_courant==OUTILS_ROUTE)
        rect(outils->outils_bmp,12,263,95,340,makecol(76,76,76));
    else
        rect(outils->outils_bmp,12,263,95,340,makecol(220,220,220));

    if(outils->outils_courant==OUTILS_CASERNE)
        rect(outils->outils_bmp,12,351,95,435,makecol(76,76,76));
    else
        rect(outils->outils_bmp,12,351,95,435,makecol(220,220,220));

    if(outils->affichage==AFFICHAGE_0)
        rect(outils->outils_bmp,1,452,21,478,makecol(76,76,76));
    else
        rect(outils->outils_bmp,1,452,21,478,makecol(220,220,220));

    if(outils->affichage==AFFICHAGE_1)
        rect(outils->outils_bmp,38,452,69,478,makecol(76,76,76));
    else
        rect(outils->outils_bmp,38,452,69,478,makecol(220,220,220));

    if(outils->affichage==AFFICHAGE_2)
        rect(outils->outils_bmp,84,452,113,478,makecol(76,76,76));
    else
        rect(outils->outils_bmp,84,452,113,478,makecol(220,220,220));
}

int selection_outils(t_outils* outils)
{
    if(mouse_click)
    {
        if(mouse_x>=12 && mouse_x<=95)
        {
            if(mouse_y>=25 && mouse_y<=100)
                return OUTILS_HABITATION;
            else if(mouse_y>=107 && mouse_y<=185)
                return OUTILS_ELEC;
            else if(mouse_y>=194 && mouse_y<=261)
                return OUTILS_EAU;
            else if(mouse_y>=263 && mouse_y<=340)
                return OUTILS_ROUTE;
            else if(mouse_y>=348 && mouse_y<=436)
                return OUTILS_CASERNE;
            else
                return outils->outils_courant;
        }
        else
            return outils->outils_courant;
    }
    else
        return outils->outils_courant;
}

int selection_affichage(t_outils* outils)
{
    if(mouse_click)
    {
        if(mouse_y>=452 && mouse_y<=478)
        {
            if(mouse_x>=1 && mouse_x<=21)
                return AFFICHAGE_0;
            if(mouse_x>=38 && mouse_x<=69)
                return AFFICHAGE_1;
            if(mouse_x>=84 && mouse_x<=113)
                return AFFICHAGE_2;
            else
                return outils->affichage;
        }
        else
            return outils->affichage;
    }
    else
        return outils->affichage;
}
