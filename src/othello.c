/* Othelle par Gilles Gaubert
   programme principal : contient la boucle de jeu
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "constantes.h"
#include "coups.h"
#include "ihm.h"
#include "regle.h"


void main() {
	char othellier[TAILLE][TAILLE];
	liste_t* listePossible=NULL;
	char couleur;
	int longueurListe=0;
	int scoreBlanc=0;
	int scoreNoir=0;
	bool perdu=false;

	// initialisation othellier avec position de
	// depart
	initOthellier(othellier);
	// affichage othellier
	affichageOthellier(othellier);
	// noir joue en premier
	couleur=NOIR;

	while ((!perdu) && (!othellierPlein(othellier))) {
		// boucle de jeu

		// construit la liste des coups possibles
		listePossible=listeCoupsPossibles(othellier,couleur);

		// calcul longueur liste
		longueurListe=listeCompte(listePossible);
		
		// affiche la liste des coups possible
		listeAffiche(listePossible,longueurListe);

		// si il y a des coups possibles
		if (longueurListe!=0) {
			// saisie du coup
			saisirEtJouerCoup(othellier,couleur);
		}
		
		// affichage othellier
		affichageOthellier(othellier);
		
		// affichage score
		score(othellier,&scoreBlanc,&scoreNoir);
		printf("Score : Blanc %d, Noir %d\n",scoreBlanc,scoreNoir);
	
		// y a t'il une seule couleur ?
		if ((scoreBlanc==0) || (scoreNoir==0)) {
			perdu=true;
		} else {
			// changer de joueur
			if (couleur==NOIR) {
				couleur=BLANC;
			} else {
				couleur=NOIR;
			}

			// free la liste chainee
			listeEfface(listePossible);
		}
	}

	// l'othellier est plein donc c'est fini
	// evaluer le score
	score(othellier,&scoreBlanc,&scoreNoir);
	if (scoreBlanc>scoreNoir) {
		puts("Les blancs gagnent !");
	} else {
		if (scoreBlanc<scoreNoir) {
			puts("Les noirs gagnent !");
		} else {
		puts("Match nul !");
		}
	}
}

