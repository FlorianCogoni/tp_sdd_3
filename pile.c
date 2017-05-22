/*
 ______________________________________________________________________________________
|                                                                                      |
|                              ___________________                                     |
|                             |                   |                                    |
|                             |      pile.c       |                                    |
|                             |___________________|                                    |
|                                                                                      |
|______________________________________________________________________________________|

	Ce fichier contient les fonctions utiles à la manipulation des piles.

*/

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"


/*---------------------------------------------------------------------

 Cette fonction initialise une pile (vide) de taille max tmax et renvoie
son adresse.

*/

pile_t * initPile(int tmax)
{
    pile_t * pPile = NULL;						/* initialisation de l'adresse de la pile */
    pPile = (pile_t *) malloc(sizeof(pile_t));				/* allocation de l'espace mémoire d'une taille de pile */
    if (pPile != NULL)
    {
        pPile->tmax = tmax;
        pPile->taille = 0;
        pPile->liste = (TYPE *) malloc(tmax * sizeof(TYPE));		/* allocation de l'espace mémoire pour la liste de la pile */
    }
    return pPile;
}



/*---------------------------------------------------------------------

 Cette procédure libère l'espace occupé par une pile à l'aide de son
adresse.

*/

void libererPile(pile_t * pPile)
{
	free(pPile->liste);	/* on libère la liste de la pile */
	free(pPile);		/* on libère la structure pile */
}


/*---------------------------------------------------------------------

 Cette fonction renvoie un booléen qui indique si la pile est vide ou
non à l'aide de son adresse.
			1 si la pile est vide
			0 sinon

*/

int estVide(pile_t * pPile)
{
    return (pPile->taille == 0);
}

int estPleine(pile_t *pPile)
{
  return (pPile->taille == pPile->tmax);
}


/*---------------------------------------------------------------------

 Cette fonction empile un élément elt sur une pile donnée par son adresse.
Si la pile est pleine, on ne peut pas empiler.

Cette fonction renvoie un code d'erreur :
			1 si l'empilage s'est bien passé
			0 sinon

*/

int empile(pile_t * pPile, TYPE elt)
{
    int code = 0;			/* on initialise le code d'erreur */
    if (estPleine(pPile))   /* si la pile est pleine (taille = taille max) */
    {
        printf("\npile pleine\n");
    }
    else
    {
        pPile->liste[pPile->taille] = elt;	/* elt est mis à la suite de la liste */
        pPile->taille += 1;			/* on augmente la taille de la liste */
        code = 1;				/* on actualise le code d'erreur */
    }
    return code;
}



/*---------------------------------------------------------------------

 Cette fonction dépile d'une pile donnée par son adresse, un élément (le
sommet) et stocke son adresse dans elt.
Si la pile est vide, on ne peut pas dépiler.

Cette fonction renvoie un code d'erreur :
			1 si le dépilage s'est bien passé
			0 sinon

*/

int depile(pile_t * pPile, TYPE * elt)
{
    int code = 0;					/* on initialise le code d'erreur */
    if (!estVide(pPile))				/* si la pile n'est pas vide */
    {
        *elt = pPile->liste[pPile->taille - 1];		/* on récupère l'adresse de l'élément */
        pPile->taille -= 1;				/* on diminue la taille de la pile */
        code = 1;					/* on actualise le code d'erreur */
    }
    else  						/* la pile est vide */
	{
        printf("\npile vide\n");
    }
    return code;
}
