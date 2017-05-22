#include <stdio.h>
#include <ctype.h>
#include "struct.h"
#include "pile.h"

void afficheMot(pile_t * pPile)
{
	int i;
  arbre_t ** cour = pPile->liste;
	for (i=0;i<pPile->taille;i++)
  {
    printf("%c", tolower((*cour)->lettre));
    cour ++;
  }
}


void affichage(arbre_t * a)
{
	int fin=0;
	arbre_t * cour = a;
	pile_t * pPile = initPile(50);
	while (!fin)
	{
		while (cour != NULL)
		{
			empile(pPile,cour); /* on empile les adresses */
      			if (isupper(cour->lettre))  /*on affiche seulement les mots qui finissent par une majuscule*/
			{
				afficheMot(pPile);
			}
			cour = cour->lv; /* on passe au fils (lien vertical) */
		}
		if (! estVide(pPile))
		{
			depile(pPile,&cour);
			cour=cour->lh; /* on passe au frère (lien horizontal) */
		}
		else
		{
			fin = 1;
		}
	}
	libererPile(pPile);
}
