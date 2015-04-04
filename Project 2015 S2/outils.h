#ifndef OUTILS_H_INCLUDED
#define OUTILS_H_INCLUDED

#include "compalleg.h"

typedef struct outils
{
    BITMAP* outils_btm;
    int nombre_outils;

}t_outils;

t_outils* allocation_outils();

void affichage_outils(t_outils* outils);

#endif // OUTILS_H_INCLUDED
