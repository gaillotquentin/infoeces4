#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include "editeur.h"




//Boite à outils qui sera afficher PEUT ETRE PAS UTILE!
typedef struct boite_outils
{
    int nb_outils;
    //..
}t_outils;

//Affichage de la grille de jeu.
void affichage_grille_page();

//Affichage de la matrice de jeu.
void affichage_matrice_jeu(t_matrice_jeu *m);

//Affichage de la route
void affichage_route(t_matrice_jeu *m, int i, int j);


#endif // AFFICHAGE_H_INCLUDED
