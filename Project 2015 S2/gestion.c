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

    //On copie la page sur le screen à chaque tour de boucle.
    afficher_page();
}

///Gerer l'ajout d'une route,maison,centrale ..
void gestion_ajout_jeu(t_matrice_jeu *m)
{
    //mettre à jour les globales
    rafraichir_clavier_souris();

    //Position de la souris sur la matrice de jeu.
    position_souris_matrice_jeu(m);

    //Si clique Gauche avec la souris alors ..
    if(bouton == 'g')
    {
        //Création d'une route
        creation_route(m);
    }
}
