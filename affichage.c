/*
 ______________________________________________________________________________________
|                                                                                      |
|                              ___________________                                     |
|                             |                   |                                    |
|                             |    affichage.c    |                                    |
|                             |___________________|                                    |
|                                                                                      |
|______________________________________________________________________________________|

	Ce fichier contient les fonctions pour la question 2 : l'affichage.

*/


#include <stdio.h>
#include <ctype.h>
#include "struct.h"
#include "pile.h"

#define NB_BLOCS 200 /* nombre de blocs (de l'arbre) maximal */

/*---------------------------------------------------------------------

 Cette fonction affiche le mot dont les adresses des lettres sont stockées dans
 une pile.

*/

void afficheMot(pile_t * pPile)
{
	int i;
  arbre_t ** cour = pPile->liste; /* cour va parcourir la pile */
	for (i=0;i<pPile->taille;i++)
  {
    printf("%c", tolower((*cour)->lettre)); /* on affiche chaque lettre en minuscule */
    cour ++; /* on avance cour */
  }
	printf("\n");
}


/*---------------------------------------------------------------------

 Cette fonction affiche les mots contenues dans un arbre.

*/


void affichage(arbre_t * a)
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
				afficheMot(pPile);
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
