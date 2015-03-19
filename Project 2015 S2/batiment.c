#include "batiment.h"
#include "compalleg.h"
#include <stdio.h>
#include <stdlib.h>
#include "editeur.h"
#include "affichage.h"
#include "gestion.h"
# define TAILLE_X_MAISON 3
# define TAILLE_Y_MAISON 3
# define TAILLE_X_CASERNE 4
# define TAILLE_Y_CASERNE 6
# define TAILLE_X_USINE 4
# define TAILLE_Y_USINE 6
# define PRIX_MAISON 1000
# define PRIX_CASERNE 10000
# define PRIX_USINE 100000

///Initialisation à 0
void init_bat(t_batiment* bat, int ad, int x, int y, int TailleX, int TailleY, int prix)
{
    bat=malloc (sizeof (t_batiment));
    bat->adresse=ad;
    bat->tailleX=TailleX;
    bat->tailleY=TailleY;
    bat->prix=prix;
    bat->orientation=0; // inverse juste tailleX et Y
    bat->niveau=1;
    bat->PosX=x;//Coordonnées du point haut à gauche
    bat->PosY=y;
    bat->actif=1; //0 si lebatiment n'est pas actif
//    bat->image=NULL;
}

t_maison* init_maison(int x, int y,int adresse)
{
    t_maison*mais;
    mais=malloc(sizeof(t_maison));
    init_bat(mais->base, adresse, x, y, TAILLE_X_MAISON, TAILLE_Y_MAISON, PRIX_MAISON);
    mais->eau=0;
    mais->eau=0;
    mais->habitants=0;

return mais;
}



t_usine* init_usine(int x, int y,int adresse, int type)
{
    t_usine*usi;
    usi=malloc(sizeof(t_usine));
    init_bat(usi->base, adresse, x, y, TAILLE_X_USINE, TAILLE_Y_USINE, PRIX_USINE);
    usi->type=type;
    usi->capacite=5000;

return usi;
}

t_caserne* init_caserne(int x, int y,int adresse)
{
    t_caserne*cas;
    cas=malloc(sizeof(t_caserne));
    init_bat (cas->base, adresse, x, y, TAILLE_X_CASERNE, TAILLE_Y_CASERNE, PRIX_CASERNE);
    cas->zone=20; //PEUX CHANGER OU FIXE?? OU DEPEND DU NIVEAU


return cas;
}
