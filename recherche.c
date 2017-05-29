/*
 ______________________________________________________________________________________
|                                                                                      |
|                              ___________________                                     |
|                             |                   |                                    |
|                             |    recherche.c    |                                    |
|                             |___________________|                                    |
|                                                                                      |
|______________________________________________________________________________________|

	Ce fichier contient les fonctions pour la question 3 : la recherche.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "struct.h"
#include "recherche.h"
#include "insertion.h"
#include "affichage.h"

#define NB_BLOCS 200 /* nombre de blocs (de l'arbre) maximal */

/*---------------------------------------------------------------------

 Cette fonction est une variante d'affichage, elle affiche le motif puis chaque
 mot du sous arbre.

*/

void affichageAvecMotif(arbre_t * a, char motif[])
{
	int fin=0; /* bouléen qui marque la fin */
	arbre_t * cour = a;
	pile_t * pPile = initPile(NB_BLOCS); /* la pile va nous servir à revenir aux pères */
	while (!fin)
	{
		while (cour != NULL) /* tant qu'on est pas au bout d'une branche */
		{
			empile(pPile,cour); /* on empile les adresses */
      			if (isupper(cour->lettre))  /* on affiche seulement les mots qui finissent par une majuscule */
			{
        printf("%s",motif); /* on affiche d'abord le motif */
				afficheMot(pPile); /* avant d'afficher le mot */
			}
			cour = cour->lv; /* on passe au fils (lien vertical) */
		}
		if (! estVide(pPile)) /* si il reste des frères */
		{
			depile(pPile,&cour);
			cour=cour->lh; /* on passe au frère (lien horizontal) */
		}
		else /* il ne reste pas de frère, le parcours est fini */
		{
			fin = 1;
		}
	}
	libererPile(pPile);
}


/*---------------------------------------------------------------------

 Cette fonction affiche les mots qui commençent par motif.
 	Elle prend en entrée la longueur du motif.

*/

void rechercheMotif(arbre_t * a, char motif[], int l)
{
  int i = 0; /* ne sert pas mais doit être mis en paramètre de recherche */
  int parente = 0;
  arbre_t * adr_motif = recherche(a, motif, l, &i, &parente); /* on récupère l'adresse du précédent de motif */
	switch (parente)
	{
        case 1 : /* le motif est en lien vertical */
		    affichageAvecMotif(adr_motif->lv,motif);
            break;

        case 2 : /* le motif est en lien horizontal */
            affichageAvecMotif(adr_motif->lh,motif);
            break;
        default : /*le motif est de taille 0*/
            affichageAvecMotif(a,motif);
            break;
	}
}
