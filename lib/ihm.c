/* affichage de l'othellier */

#include <stdio.h>
#include "constantes.h"

/*
const char noir='X';
const char blanc='O';
const char vide=' ';
*/

void initOthellier(char othellier[TAILLE][TAILLE]) {
	int i;
	int j;
	for (i=0;i<TAILLE;i++) {
		for (j=0;j<TAILLE;j++) {
			if (((i==3) && (j==3)) || ((i==4) && (j==4))) {
				othellier[i][j]=NOIR;
			} else if (((i==4) && (j==3)) || ((i==3) && (j==4))) {
				othellier[i][j]=BLANC;
			} else {
				othellier[i][j]=VIDE;
			}
		}
	}
}


void affichageOthellier(char othellier[TAILLE][TAILLE]) {
	printf("   A B C D E F G H\n");
	printf("  /---------------\\\n");
	int i;
	int j;
	for (i=1;i<(TAILLE+1);i++) {
		printf("%d |",i);
		for (j=0;j<TAILLE;j++) {
			printf("%c|",othellier[i-1][j]);
		}
		printf("\n");
	}
	printf("  \\---------------/\n");
}
/*
void main() {
	char othellier[8][8];
	initOthellier(othellier);
	affichageOthellier(othellier);
}
*/

