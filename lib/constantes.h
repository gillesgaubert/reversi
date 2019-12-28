/* constantes.h */


#ifndef INCL_CONSTANTES_H
#define INCL_CONSTANTES_H


typedef struct liste_s {
	int ligne;
	int colonne;
	struct liste_s* suivant;
} liste_t;


extern const char VIDE;
extern const char NOIR;
extern const char BLANC;
extern const int TAILLE;


#endif

