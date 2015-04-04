#include <stdio.h>
#include <stdlib.h>
#include "compalleg.h"
#include "affichage.h"
#include "gestion.h"
#include "outils.h"

int main()
{
    ///Initialisation
    //Initialiser Allegro
    initialiser_allegro();

    //Structure de jeu.
    t_matrice_jeu *m;
    m=allocation_matrice_jeu();

    //boite a outils
    t_outils* outils;
    outils=allocation_outils();

    /// Boucle pour attente appui sur echap
    while (!key[KEY_ESC])
    {
        //Gestion de l'édition de la matrice jeu
        gestion_ajout_jeu(m);

        //Affichage de la matrice jeu
        gestion_affichage_jeu(m);

        //gestion de la boite a outils
        gestion_outils(outils);

        affichage_page();

        //attendre 10ms
        rest(10);
    }

    ///Fermer Allegro
    fermer_allegro();

    return 0;
}
END_OF_MAIN();
