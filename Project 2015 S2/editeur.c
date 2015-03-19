#include <stdio.h>
#include <stdlib.h>
#include "editeur.h"
#include "compalleg.h"


///REGLES DU JEU

// Elément de route, canalisation, ligne électrique : 1x1 case
// Elément de construction d’habitation : 3x3 cases
// Elément de bâtiments prédéfinis (usines, châteaux d’eau, casernes…) : 4x6 cases

//Pour construire une maison, il faut de l'eau, de l'électricité et une route !
//Pour qu’un réseau de canalisation ou d’électricité soit alimenté, il doit être connecté à un château d’eau ou une centrale électrique.
//Faire une boite à outils
//Afficher les quantités distribué et capacité max pr les chateaux d'eau(1000) + centrale(5000)!

// Un compteur temporel temps réel à la seconde apparait à l’écran et tourne jusqu’à la fin de la partie.
//Un compteur « monnaie » affiche la somme initiale en jeu : 500 000 ECEflouz. Cette somme sera décrémentée par les achats et incrémentée par les impôts.
//Un compteur « habitants » indique la somme totale d’habitant dans la ville.
//Un compteur « capacité électrique » et « capacité en eau »

//- Terrain vague (0 habitant) ou Ruine en cas de régression (0 habitant)
//- Cabane (10 habitants)
//- Maison (50 habitants)
//- Immeuble (100 habitants)
//- Gratte-ciel (1000 habitants)

//La banque dispose au départ de 500 000 ECE-flouz.
//Dépenses
//La construction de bâtiment a un coût :
//- Centrale : 100 000 ECE-flouz
//- Château d’eau : 100 000 ECE-flouz
//- Route : 10 ECE-flouz par unité de grille
//- Terrain vague : 1000 ECE-flouz
//Impôts et taxes
//Chaque habitant verse 10 ECE-flouz à chaque fin de cycle(15s) de l’habitation qu’il occupe.
//Une caserne coûte 10000 ECE-flouz.
//A chaque cycle d’une construction, un incendie peut se déclencher arbitrairement.(20 cases par route)
//Sauvegarder et charger + bouton pause!

///allocation de la structure matrice de jeu
t_matrice_jeu *allocation_matrice_jeu()
{
    //déclaration des variables/compteur
    t_matrice_jeu *m;
    int i=0,j=0;

    //Allocation de la matrice de jeu
    m = (t_matrice_jeu *) malloc(sizeof(t_matrice_jeu));

    m->matjeu = (t_case**) malloc(NOMBRE_CASE_LARGEUR*sizeof(t_case*));
    if(m->matjeu == NULL)
    {
       exit(EXIT_FAILURE);
       printf("ERREUR MALLOC MATJEU");
    }

    for(i=0; i<NOMBRE_CASE_LARGEUR; i++)
    {
        m->matjeu[i] = (t_case*) malloc(NOMBRE_CASE_HAUTEUR*sizeof(t_case));
        if(m->matjeu[i] == NULL)
        {
            exit(EXIT_FAILURE);
            printf("ERREUR MALLOC MATJEU");
        }
    }

    //Initialisé l'ensemble des cases à 0.
    for(i=0 ; i<NOMBRE_CASE_LARGEUR; i++)
    {
        for(j=0 ; j<NOMBRE_CASE_HAUTEUR; j++)
        {
            m->matjeu[i][j].nom = '0';
        }
    }

    return m;
}

///Position de la souris dans la matrice de jeu
void position_souris_matrice_jeu(t_matrice_jeu *m)
{
    //Compteur
    int i=0;

    //Connaitre la position dans la matrice de jeu pour x.
    while(i*DIM_PIXEL<mouse_x-DIM_PIXEL && mouse_x>DIM_PIXEL)
    {
        i++;
    }
    m->mouse_x = i;
    i=0;
    //Connaitre la position dans la matrice de jeu pour y.
    while(i*DIM_PIXEL<mouse_y-DIM_PIXEL && mouse_y>DIM_PIXEL)
    {
        i++;
    }
    m->mouse_y = i;
}

///Rajouter une route
void creation_route(t_matrice_jeu *m)
{
   //Si il n'y a rien sur la case, alors ..
   if(m->matjeu[m->mouse_x][m->mouse_y].nom == '0')
    {
        //on place une route
        m->matjeu[m->mouse_x][m->mouse_y].nom = 'r';
    }
}
