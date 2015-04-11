#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED


#include "bibliotheque.h"

typedef struct donnees
{
    BITMAP* donnees_bmp;
}t_donnees;

t_donnees* allocation_donnees();

void affichage_donnees(t_donnees* donnees);

#endif // DONNEES_H_INCLUDED
