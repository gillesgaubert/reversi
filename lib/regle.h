/* regle.h */

#ifndef INCL_REGLE_H
#define INCL_REGLE_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "constantes.h"


bool horsOthellier(int l,int c);

bool exploration(char othellier[TAILLE][TAILLE],int l,int c,int dirL,int dirC,char couleur,bool retourner);

void switchCouleur(char othellier[TAILLE][TAILLE],int l,int c);

void inversionPiece(char othellier[TAILLE][TAILLE],int l,int c,int dirL,int dirC,char couleur);

bool explore8Directions(char othellier[TAILLE][TAILLE],int l,int c,char couleur,bool retourner);


#endif

