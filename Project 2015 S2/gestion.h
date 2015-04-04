#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "compalleg.h"
#include "editeur.h"
#include "affichage.h"
#include "outils.h"

//Gestion de l'affichage de la matrice de jeu
void gestion_affichage_jeu(t_matrice_jeu *m);

//Gestion de l'ajout d'une route, maison, centrale ..
void gestion_ajout_jeu(t_matrice_jeu *m);

void gestion_outils(t_outils* outils);

#endif // GESTION_H_INCLUDED
