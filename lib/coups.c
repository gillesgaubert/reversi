/* coups.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "coups.h"
#include "constantes.h"
#include "regle.h"


// pour le bug i/o apres scanf %c
void viderBuffer() {
	char caractere;
	while ((caractere=getchar())!=EOF && caractere!='\n');
}

// gere la saisie et apelle coupLegal et enfin met à jour
// le tableau othellier
void saisirEtJouerCoup(char othellier[TAILLE][TAILLE],char couleur) {
	char colonne;
	// c et l colonne et ligne sont des entiers indice
	// de othellier
	int c;
	int l;
	bool coupPossible=false;
	bool legal=false;

	do {
		if (couleur==BLANC) {
			puts("C'est au joueur blanc (O) de jouer :");
		} else {
			puts("C'est au joueur noir (X) de jouer :");
		}

		printf("Donnez la colonne (A-H) : ");
		scanf("%c",&colonne);
		// il faut vider le buffer apres un scanf %c
		viderBuffer();
		printf("Donnez la ligne (1-8) : ");
		scanf("%d",&l);
		viderBuffer();
		// on transforme les valeurs entrees pour etre
		// utilisees comme indice du tableau
		c=(int)(colonne)-(int)('A');
		l--;
		
		legal=coupLegal(othellier,l,c);
		if (legal) {
			// le coup est donc sur une case de l'othellier
			// qui n'est pas deja occupee mais est-il permis
			// par la regle du jeux ?
			coupPossible=explore8Directions(othellier,l,c,couleur,true);
			if (!coupPossible) {
				puts("Non ce coup n'est pas permis dans le jeu d'othello, recommencez !");
			}
		}
	} while ((!legal) || (!coupPossible));
}

// teste si coup sur othellier et si emplacement
// n'est pas deja occupe
bool coupLegal(char othellier[TAILLE][TAILLE],int l,int c) {
	if (horsOthellier(l,c)) {
		puts("Coup illegal ou en dehors de l'othellier, recommencez !");
		return false;
	}
	if (othellier[l][c]!=VIDE) {
		puts("Cette case est déjà occupée, recommencez !");
		return false;
	}
	return true;
}

// fonction appellee pour voir si partie finie
bool othellierPlein(char othellier[TAILLE][TAILLE]) {
	int i=0;
	int j=0;
	while (i<TAILLE) {
		while (j<TAILLE) {
			if (othellier[i][j]==VIDE) {
				return false;
			}
			j++;
		}
		i++;
	}
	return true;
}
			

// evaluation du score des deux joueurs
void score(char othellier[TAILLE][TAILLE],int* ptrScoreBlanc,int* ptrScoreNoir) {
	int i;
	int j;
	int scB=0;
	int scN=0;
	*ptrScoreNoir=0;
	for (i=0;i<TAILLE;i++) {
		for (j=0;j<TAILLE;j++) {
			if (othellier[i][j]==BLANC) {
				scB++;
			} else if (othellier[i][j]==NOIR) {
				scN++;
			}
		}
	}
	*ptrScoreBlanc=scB;
	*ptrScoreNoir=scN;
}

// fonctions de manipulation des listes chainnees
// pour la liste des coups possibles

// creation liste des coups possibles
liste_t* listeCoupsPossibles(char othellier[TAILLE][TAILLE],char couleur) {
	int i;
	int j;
	bool possibilite=false;
	liste_t* listePossible=NULL;
	
	printf("Liste des coups jouables pour %c:\n",couleur);
	
	for (i=0;i<TAILLE;i++) {
		for (j=0;j<TAILLE;j++) {
			if (othellier[i][j]==VIDE) {
				possibilite=explore8Directions(othellier,i,j,couleur,false);
				if (possibilite) {
					if (listePossible==NULL) {
						listePossible=listeNouveau(i,j);
					} else {
						listeAjout(listePossible,i,j);
					}
				}
			}
		}
	}
	return listePossible;
}

// creation maillon liste chainee
liste_t* listeNouveau(int l,int c) {
	liste_t* res=malloc(sizeof(liste_t));
	res->ligne=l;
	res->colonne=c;
	res->suivant=NULL;
	return res;
}

// ajout de maillon
void listeAjout(liste_t* tete,int l,int c) {
	liste_t* curseur=tete;
	while (curseur->suivant!=NULL) {
		curseur=curseur->suivant;
	}
	curseur->suivant=listeNouveau(l,c);
}

// comptage de maillons
int listeCompte(liste_t* tete) {
	int resultat=0;
	while (tete!=NULL) {
		++resultat;
		tete=tete->suivant;
	}
	return resultat;
}

// affiche liste
void listeAffiche(liste_t* tete,int longueur) {
	while (longueur--) {
		printf("(%c - %d)  ",(char)((int)('A')+(tete->colonne)),(tete->ligne)+1);
		tete=tete->suivant;
	}
	printf("\n");
}

// efface liste
void listeEfface(liste_t* maillon) {
	while (maillon!=NULL) {
		liste_t* suivant=maillon->suivant;
		free(maillon);
		maillon=suivant;
	}
}

