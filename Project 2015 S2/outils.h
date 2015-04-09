#ifndef OUTILS_H_INCLUDED
#define OUTILS_H_INCLUDED

#define OUTILS_HABITATION 1
#define OUTILS_ELEC 2
#define OUTILS_EAU 3
#define OUTILS_ROUTE 4
#define OUTILS_CASERNE 5

#define AFFICHAGE_0 0
#define AFFICHAGE_1 1
#define AFFICHAGE_2 2

#include "bibliotheque.h"

typedef struct outils
{
    BITMAP* outils_bmp;
    int outils_courant;
    int affichage;
}t_outils;

t_outils* allocation_outils();

void affichage_outils(t_outils* outils);

int selection_outils(t_outils* outils);

int selection_affichage(t_outils* outils);

#endif // OUTILS_H_INCLUDED
