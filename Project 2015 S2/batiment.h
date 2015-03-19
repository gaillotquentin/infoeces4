#ifndef BATIMENT_H_INCLUDED
#define BATIMENT_H_INCLUDED
typedef struct batiment
{
    int adresse;
    int tailleX;
    int tailleY;
    int orientation; // inverse juste tailleX et Y
    int prix;
    int niveau;
    int PosX;//Coordonnées du point haut à gauche
    int PosY;
    int actif; //0 si lebatiment n'est pas actif
//    BITMAP* image;
}t_batiment;

typedef struct maison
{
    t_batiment* base;
    int habitants;
    int eau;  // Pour savoir si la maison est désservie ou pas
    int elec;
}t_maison;

typedef struct caserne
{
    t_batiment* base;
    int zone;
}t_caserne;

typedef struct usine
{
    t_batiment* base;
    int capacite;
    int type; //Chateau d'eau ou centrale
}t_usine;


/*Initialisation de la structure maison
Reçoit le pointeur sur la structure batiment (à modifier) son numéro unique (l'identifiant) les coordonées du batiment, sa taille fixe et le prix de départ */
void init_bat(t_batiment* bat, int ad, int x, int y, int TailleX, int TailleY, int prix);

/*Initialisation de la structure maison
Reçoit les coordonées et son numéro unique (l'identifiant)*/
t_maison* init_maison(int x, int y,int adresse);


/*Initialisation de la structure usine
Reçoit les coordonnées, l'identifiant et le type (centrale élcetrique ou chateau d'eau*/
t_usine* init_usine(int x, int y,int adresse, int type);


/*Initiialisation de la structure caserne
Reçoit les coordonnées et l'identifiant*/
t_caserne* init_caserne(int x, int y,int adresse);



#endif // BATIMENT_H_INCLUDED
