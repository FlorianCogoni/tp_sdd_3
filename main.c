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
	char mot[] = "bonjour";
	arbre_t * a = (arbre_t *) malloc(sizeof(arbre_t));
	a->lettre = 'a';
	a->lh = NULL;
	a->lv = NULL;
	insert(a,mot,7);
	return 0;
}
