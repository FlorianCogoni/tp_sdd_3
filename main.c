#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "struct.h"
#include "insertion.h"
#include "affichage.h"
#include "pile.h"

int main()
{
	/* arbre_t * b = NULL;*/
	arbre_t * a = (arbre_t *) malloc(sizeof(arbre_t));
	a->lettre = 'a';
	a->lh = NULL;
	a->lv = NULL;
	insert(&a,"bonjouR",7);
	insert(&a,"boN",3);
	insert(&a,"bonsoiR",7);
	insert(&a,"arbrE",5);
	insert(&a,"arborescenT",11);
	insert(&a,"arboricolE",10);
	libere(a);
	/insert(&b,"saluT",5);
	libere(b);/
	return 0;
}
