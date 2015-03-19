#ifndef EDITEUR_H_INCLUDED
#define EDITEUR_H_INCLUDED

//Définition d'une case.
typedef struct description_case
{
    char nom;
    int eau;
    int elec;
    //+++ (voisin etc..)

}t_case;

//Matrice du jeu en 45x34 cases
typedef struct matrice_jeu
{
    t_case **matjeu;
    int mouse_x;
    int mouse_y;

}t_matrice_jeu;

//Allocation de la matrice de jeu
t_matrice_jeu *allocation_matrice_jeu();

//Position de la souris dans la matrice 45x35 (ici 40x30)
void position_souris_matrice_jeu(t_matrice_jeu *m);

//Création d'une route sur la matrice
void creation_route(t_matrice_jeu *m);


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
