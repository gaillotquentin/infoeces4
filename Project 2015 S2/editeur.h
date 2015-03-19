#ifndef EDITEUR_H_INCLUDED
#define EDITEUR_H_INCLUDED

#include <stdlib.h>

//D�finition d'une case.
typedef struct description_case
{
    char nom;
    int eau;
    int elec;
    //+++ (voisin etc..)

}t_case;

//Matrice d'une habitation
typedef struct habitations
{
    int niveau; //cabane, maison, building ..
    int eau; //ressource d'eau ?
    int elec; //ressource d'electricit� ?
    int habitant; //nb d'habitant
    int prix; //prix d'une habitation PAS OBLIGATOIRE
    int pos_x; //son emplacement (Coordonn�es d'un coin de r�f�rence = en haut � gauche)
    int pos_y; //son emplacement (3x3 cases)

}t_habitation;

//Matrice du jeu en 45x34 cases
typedef struct matrice_jeu
{
    t_case **matjeu; //Matrice de jeu
    int mouse_x; //Position en x de la souris dans la grille
    int mouse_y; //Position en y de la souris dans la grille

    int nb_habitation; //nombre d'habitation dans la grille
    t_habitation *habitation; //Tableau contenant la description des habitations.

    int nb_route; //nombre de route

}t_matrice_jeu;

//Allocation de la matrice de jeu
t_matrice_jeu *allocation_matrice_jeu();

//Allocation d'une habitation
t_habitation* allocation_habitation();

//Position de la souris dans la matrice 45x35 (ici 40x30)
void position_souris_matrice_jeu(t_matrice_jeu *m);

//Cr�ation d'une route sur la matrice
void creation_route(t_matrice_jeu *m);

//Supression d'une route sur la matrice de jeu
void suppression_route(t_matrice_jeu *m);

//Cr�ation d'habitation
void creation_habitation(t_matrice_jeu *m);

void *malloc_safe(size_t size);

/*
int terrain_vague;
    int cabane;
    int maison;
    int immeumble;
    int gratte_ciel;
    int elec;
    int eau;
    int feu;
    int habitant;
*/

#endif // EDITEUR_H_INCLUDED