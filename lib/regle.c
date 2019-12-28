/* inplantation des regles du jeu */

#include <stdio.h>
#include "constantes.h"
#include "regle.h"
#include "coups.h"


bool horsOthellier(int l,int c) {
	if ((l<0) || (l>TAILLE-1)) {
		return true;
	}
	if ((c<0) || (c>TAILLE-1)) {
		return true;
	}
	return false;
}

// explore l'othellier d'une case vers une
// direction donnée
bool exploration(char othellier[TAILLE][TAILLE],int l,int c,int dirL,int dirC,char couleur,bool retourner) {
	bool trouve;
	if ((horsOthellier(l+dirL,c+dirC) || (othellier[l+dirL][c+dirC]==VIDE))) {
		// hors othellier ou case vide
		return false;
	}
	if (othellier[l+dirL][c+dirC]!=couleur) {
		// couleur differente, explo continue...
		return exploration(othellier,l+dirL,c+dirC,dirL,dirC,couleur,retourner);
	} else {
		if (othellier[l+dirL][c+dirC]==couleur) {
			// si c'est le moment de retourner les pions
			if (retourner) {
				inversionPiece(othellier,l,c,dirL,dirC,couleur);
			}
			return true;
		}
	}
}

void switchCouleur(char othellier[TAILLE][TAILLE],int l,int c) {
	if (othellier[l][c]==BLANC) {
		othellier[l][c]=NOIR;
	} else {
		othellier[l][c]=BLANC;
	}
}

// retournement d'une piece sur l'othellier
void inversionPiece(char othellier[TAILLE][TAILLE],int l,int c,int dirL,int dirC,char couleur) {
	switchCouleur(othellier,l,c);
	if ((othellier[l-dirL][c-dirC]!=couleur) && (othellier[l-dirL][c-dirC]!=VIDE)) {
		inversionPiece(othellier,l-dirL,c-dirC,dirL,dirC,couleur);
	}
}

// appelle exploration pour les huit directions
// possibles
bool explore8Directions(char othellier[TAILLE][TAILLE],int l,int c,char couleur,bool retourner) {
	int i;
	int j;
	bool inversionPossible=false;
	/*printf("%c veut jouer ligne %d, colonne %d\n",couleur,l,c);*/
	for (i=-1;i<2;i++) {
		for (j=-1;j<2;j++) {
			if ((i!=0) || (j!=0)) {
				if ((othellier[l+i][c+j]!=VIDE) && (othellier[l+i][c+j]!=couleur) &&  (!horsOthellier(l+i,c+j))) { 
					if (exploration(othellier,l+i,c+j,i,j,couleur,retourner)) {
						inversionPossible=true;
					}
				}
			}
		}
	}
	if ((inversionPossible) && (retourner)) {
		othellier[l][c]=couleur;
	}
	return inversionPossible;
}

