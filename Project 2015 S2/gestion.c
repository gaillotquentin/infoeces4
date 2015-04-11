#include "bibliotheque.h"


///Gestion de l'affichage complet de la matrice de jeu
void gestion_affichage_jeu(t_matrice_jeu *m)
{
    //Afficher la matrice
    affichage_matrice_jeu(m);

}

///Gerer l'ajout d'une route,maison,centrale ..
void gestion_ajout_jeu(t_matrice_jeu *m)
{
    //mettre à jour les globales
    rafraichir_clavier_souris();

    //Position de la souris sur la matrice de jeu.
    position_souris_matrice_jeu(m);

    //Si clique Gauche avec la souris alors on rajoute, on si le clique gauche reste appuyé
    if(mouse_b&1 && m->outils==OUTILS_ROUTE && m->mouse_x!=-1 && m->mouse_y!=-1)//mouse_click&1 ou bouton == 'g'
    {
        //Création d'une route
        creation_route(m);
    }

    //Création d'habitation, temporaire!
    if(mouse_b&1 && m->outils==OUTILS_HABITATION&& m->mouse_x!=-1 && m->mouse_y!=-1) //mouse_b&1
    {
        creation_habitation(m);
    }

    //Si clique Droit on supprime le battiment en question.
    if(mouse_b&2 && m->mouse_x!=-1 && m->mouse_y!=-1) //bouton == 'd'
    {
        suppression_route(m);

        suppression_batiment(m);
    }
}

void gestion_outils(t_outils* outils, t_matrice_jeu *m)
{
    outils->outils_courant=selection_outils(outils);
    outils->affichage=selection_affichage(outils);
    m->outils=outils->outils_courant;
    m->affichage=outils->affichage;
    printf("\n%d  %d",outils->outils_courant, outils->affichage);
    affichage_outils(outils);
}

void gestion_donnees(t_donnees* donnees)
{
    affichage_donnees(donnees);
}

