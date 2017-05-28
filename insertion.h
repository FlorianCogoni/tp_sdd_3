/*
 ______________________________________________________________________________________
|                                                                                      |
|                              ___________________                                     |
|                             |                   |                                    |
|                             |    insertion.h    |                                    |
|                             |___________________|                                    |
|                                                                                      |
|______________________________________________________________________________________|

	Ce fichier contient les prototypes des fonctions de la question 1.

*/


#ifndef INSERTION
#define INSERTION

arbre_t * recherche(arbre_t * a, char mot[], int l,int * i, int * parente);
void insert(arbre_t ** a, char mot[], int l);
void insertionFichierTexte(arbre_t ** a, char nomFichier[]);
void liberer(arbre_t * a);

#endif
