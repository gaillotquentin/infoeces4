#include "bibliotheque.h"


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
    m = malloc_safe(sizeof(t_matrice_jeu));

    m->matjeu = malloc_safe(NOMBRE_CASE_LARGEUR*sizeof(t_case*));

    for(i=0; i<NOMBRE_CASE_LARGEUR; i++)
    {
        m->matjeu[i] = malloc_safe(NOMBRE_CASE_HAUTEUR*sizeof(t_case));
    }

    //Allocation des habitations
    m->habitation = allocation_habitation();

    //Initialiser l'ensemble des cases à 0 et le nombre de route et d'habitation
    for(i=0 ; i<NOMBRE_CASE_LARGEUR; i++)
    {
        for(j=0 ; j<NOMBRE_CASE_HAUTEUR; j++)
        {
            m->matjeu[i][j].nom = '0';
            m->matjeu[i][j].eau = 0;
            m->matjeu[i][j].elec = 0;
        }
    }
    m->nb_habitation = 0;
    m->nb_route = 0;

    BITMAP* matrice_btm;
    matrice_btm=create_bitmap(NOMBRE_CASE_LARGEUR*DIM_PIXEL, NOMBRE_CASE_HAUTEUR*DIM_PIXEL);
    clear_to_color(matrice_btm, makecol(255,255,255));
    m->matrice_btm=matrice_btm;
    m->outils=0;
    m->affichage=AFFICHAGE_0;

    return m;
}

///Malloc qui est correcte MARCHE PAS
void *malloc_safe(size_t size)
{
    void* ptr;
    ptr= malloc(size);
    if(ptr == NULL)
    {
        printf("ERREUR ALLOC");
        exit(EXIT_FAILURE);
    }
    else
        return ptr;
}

///Allocation d'une habitation
t_habitation* allocation_habitation()
{
    t_habitation *h;

    //On alloue 50 habitations au dépard :p
    h = malloc_safe(NOMBRE_MAX_HABITATION*sizeof(t_habitation));

    return h;
}

///Position de la souris dans la matrice de jeu
void position_souris_matrice_jeu(t_matrice_jeu *m)
{
    //Compteur
    int i=0;

    //Connaitre la position dans la matrice de jeu pour x.
    while(i*DIM_PIXEL+(FENETRE_LARGEUR-NOMBRE_CASE_LARGEUR*DIM_PIXEL)<mouse_x-DIM_PIXEL && mouse_x>DIM_PIXEL)
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

    if(mouse_x<FENETRE_LARGEUR-NOMBRE_CASE_LARGEUR*DIM_PIXEL || mouse_y>m->matrice_btm->h)
    {
        m->mouse_x=-1;
        m->mouse_y=-1;
    }

}

///Rajouter une ROUTE
void creation_route(t_matrice_jeu *m)
{
   //Si il n'y a rien sur la case, alors ..
   if(m->matjeu[m->mouse_x][m->mouse_y].nom == '0')
    {
        //on place une route
        m->matjeu[m->mouse_x][m->mouse_y].nom = 'r';
        m->nb_route++;
    }
}

///Supprimer une ROUTE
void suppression_route(t_matrice_jeu *m)
{
    //Si il une route sur la case, alors ..
   if(m->matjeu[m->mouse_x][m->mouse_y].nom == 'r')
    {
        //on la supprime
        m->matjeu[m->mouse_x][m->mouse_y].nom = '0';
        m->nb_route--;
    }
}

///Rajout d'une habitation
void creation_habitation(t_matrice_jeu *m)
{
    //Si il y a rien sur les cases : (en partant du pts en haut à gauche)
    if( test_construction(m, 3, 3) && test_route(m, 3, 3) )
    {
        //On assigne les habitations au grillage (matrice de jeu)
        ecriture_dans_nom_matrice(m, m->mouse_x, m->mouse_y, 3, 3, 'h');

        //On enregistre l'habitation dans notre répertoire d'habitation (structure)
        //On initialise
        initialiser_structure_habitation(m);

        //On rajoute l'habitation
        m->nb_habitation++;

        ///Le réaloc ne marche pas bien dans notre cas!
        /*
        //Si nombre d'habitation dépasse alors, on realloc!
        if(m->nb_habitation ==  NOMBRE_MAX_HABITATION)
        {
            realloc(m->habitation,NOMBRE_MAX_HABITATION*2);
        }
        */
    }
}

//Initialiser l'habitation
void initialiser_structure_habitation(t_matrice_jeu *m)
{
    m->habitation[m->nb_habitation].pos_x = m->mouse_x;
    m->habitation[m->nb_habitation].pos_y = m->mouse_y;
    m->habitation[m->nb_habitation].niveau = 0; //pour l'instant c'est une cabanne!
    m->habitation[m->nb_habitation].eau = 0;
    m->habitation[m->nb_habitation].elec = 0;
    m->habitation[m->nb_habitation].habitant = 10;
    m->habitation[m->nb_habitation].prix = 10;
}

///Supression d'une habitation
void suppression_batiment(t_matrice_jeu *m)
{
    int i,j;

    //Si il une route sur la case, alors ..
   if(m->matjeu[m->mouse_x][m->mouse_y].nom == 'h')
    {
        printf("nombre de bati :%d\n",m->nb_habitation);

        for(i=0 ; i<m->nb_habitation ; i++)
        {
           if(m->mouse_x >= m->habitation[i].pos_x && m->mouse_x <= m->habitation[i].pos_x+2 &&
              m->mouse_y >= m->habitation[i].pos_y && m->mouse_y <= m->habitation[i].pos_y+2)
            {
                printf("LOL\n");
                //on la supprime
                ecriture_dans_nom_matrice(m, m->habitation[i].pos_x, m->habitation[i].pos_y, 3, 3, '0');

                m->nb_habitation--;

                //Replacer les habitations correctement dans le tableau d'habitation
                if(m->nb_habitation != i) //Si l'habitation est la dernière on touche pas
                {
                    for(j=i ; j<m->nb_habitation ; j++)
                    {
                        m->habitation[j].pos_x = m->habitation[j+1].pos_x ;
                        m->habitation[j].pos_y = m->habitation[j+1].pos_y ;
                        m->habitation[j].niveau = m->habitation[j+1].niveau ;
                        m->habitation[j].eau = m->habitation[j+1].eau ;
                        m->habitation[j].elec = m->habitation[j+1].elec ;
                        m->habitation[j].habitant = m->habitation[j+1].habitant ;
                        m->habitation[j].prix = m->habitation[j+1].prix ;
                    }
                }
            }
        }
    }
}

int test_construction(t_matrice_jeu *m, int taille_x, int taille_y)
{
    int i,j;
    int test=0;

    for(i=0; i<taille_x; i++)
    {
        for(j=0; j<taille_y; j++)
        {
            if(m->matjeu[m->mouse_x+i][m->mouse_y+j].nom == '0')
                test++;
        }
    }

    if(test==(taille_x*taille_y) && m->mouse_x <= NOMBRE_CASE_LARGEUR-taille_x && m->mouse_y <= NOMBRE_CASE_HAUTEUR-taille_y)
        return 1;
    else
        return 0;
}

int test_route(t_matrice_jeu *m, int taille_x, int taille_y)
{
    int i;
    int test=0;

    for(i=0; i<taille_x; i++)
    {
        if(m->mouse_y-1>=0)
        {
            if(m->matjeu[m->mouse_x+i][m->mouse_y-1].nom == 'r')
                test++;
        }
        if(m->mouse_y+taille_y<NOMBRE_CASE_HAUTEUR)
        {
            if(m->matjeu[m->mouse_x+i][m->mouse_y+taille_y].nom == 'r')
                test++;
        }

    }
    for(i=0; i<taille_y; i++)
    {
        if(m->mouse_x-1>=0)
        {
            if(m->matjeu[m->mouse_x-1][m->mouse_y+i].nom == 'r')
                test++;
        }
        if(m->mouse_x+taille_x<NOMBRE_CASE_LARGEUR)
        {
            if(m->matjeu[m->mouse_x+taille_x][m->mouse_y+i].nom == 'r')
                test++;
        }
    }

    if(test!=0)
        return 1;
    else
        return 0;
}

void ecriture_dans_nom_matrice(t_matrice_jeu *m, int mouse_x, int mouse_y, int taille_x, int taille_y, char c)
{
    int i,j;

    for(i=0; i<taille_x; i++)
    {
        for(j=0; j<taille_y; j++)
        {
            m->matjeu[mouse_x+i][mouse_y+j].nom = c;
        }
    }
}
