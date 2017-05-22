/*
 ______________________________________________________________________________________
|                                                                                      |
|                              ___________________                                     |
|                             |                   |                                    |
|                             |      pile.h       |                                    |
|                             |___________________|                                    |
|                                                                                      |
|______________________________________________________________________________________|

	Ce fichier contient la structure de la pile ainsi que les prototypes des fonction
utiles pour les piles.

*/

#ifndef PILE
#define PILE

#include "struct.h"

#define TYPE arbre_t *

typedef struct pile
{
    int   tmax;
    int   taille;
    TYPE * liste;
} pile_t;

pile_t * initPile(int tmax);
void libererPile(pile_t * pPile);
int estVide(pile_t * pPile);
int empile(pile_t * pPile, TYPE elt);
int depile(pile_t * pPile, TYPE * elt);

#endif
