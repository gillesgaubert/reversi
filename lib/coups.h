/* coups.h */

#ifndef INCL_COUPS_H
#define INCL_COUPS_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constantes.h"
#include "regle.h"


void viderBuffer();

void saisirEtJouerCoup(char othellier[TAILLE][TAILLE],char couleur);

bool coupLegal(char othellier[TAILLE][TAILLE],int l,int c);

bool othellierPlein(char othellier[TAILLE][TAILLE]);

void score(char othellier[TAILLE][TAILLE],int* ptrScoreBlanc,int* ptrScoreNoir);

liste_t* listeCoupsPossibles(char othellier[TAILLE][TAILLE],char couleur);

liste_t* listeNouveau(int l,int c);

void listeEfface(liste_t* maillon);

void listeAjout(liste_t* tete,int l,int c);

int listeCompte(liste_t* tete);

void listeAffiche(liste_t* tete,int longueur);

void listeEfface(liste_t* maillon);


#endif

