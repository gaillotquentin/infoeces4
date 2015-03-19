#include <stdio.h>
#include <stdlib.h>
#include "compalleg.h"
#include "editeur.h"
#include "affichage.h"

///Gestion de l'affichage complet de la matrice de jeu
void gestion_affichage_jeu(t_matrice_jeu *m)
{
    //Afficher la matrice
    affichage_matrice_jeu(m);

    //On copie la page sur le screen � chaque tour de boucle.
    afficher_page();
}

///Gerer l'ajout d'une route,maison,centrale ..
void gestion_ajout_jeu(t_matrice_jeu *m)
{
    //mettre � jour les globales
    rafraichir_clavier_souris();

    //Position de la souris sur la matrice de jeu.
    position_souris_matrice_jeu(m);

    //Si clique Gauche avec la souris alors on rajoute, on si le clique gauche reste appuy�
   /* if(mouse_b&1)//mouse_click&1 ou bouton == 'g'
    {
        //Position de la souris sur la matrice de jeu.
        position_souris_matrice_jeu(m);

        //Cr�ation d'une route
        creation_route(m);
    }
    */

    //Cr�ation d'habitation, temporaire!
    if(mouse_b&1)
    {
        creation_habitation(m);
    }

    //Si clique Droit on supprime le battiment en question.
    if(mouse_b&2) //bouton == 'd'
    {
        suppression_route(m);
    }
}