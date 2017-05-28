#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "struct.h"
#include "recherche.h"
#include "insertion.h"
#include "affichage.h"


void affichageAvecMotif(arbre_t * a, char motif[])
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
        printf("%s",motif);
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


void rechercheMotif(arbre_t * a, char motif[],int l)
{
  /*int l = strlen(motif);*/
  int i = 0;
  int parente = 0;
  arbre_t * adr_motif = recherche(a, motif, l,&i,&parente);
	if (parente == 1)
	{
		affichageAvecMotif(adr_motif->lv,motif);
	}
	else
	{
		affichageAvecMotif(adr_motif->lh,motif);
	}
}
