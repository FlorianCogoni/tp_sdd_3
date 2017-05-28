#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "struct.h"
#include "insertion.h"
#include "affichage.h"
#include "recherche.h"
#include "pile.h"

int main()
{
	arbre_t * b = NULL;
	arbre_t * a = (arbre_t *) malloc(sizeof(arbre_t));
	a->lettre = 'a';
	a->lh = NULL;
	a->lv = NULL;
	printf("creations de l'arbre a contenant la lettre a et de l'arbre b vide effectuees\n\n");
	printf("test d'affichage de a, qui ne contient pas de mot :\n\n");
	affichage(a);
	printf("\n");
	printf("insertion de mots dans l'arbre a \n\n");
	insert(&a,"bonjouR",7);
	insert(&a,"boN",3);
	insert(&a,"bonsoiR",7);
	insert(&a,"arbrE",5);
	insert(&a,"arborescenT",11);
	insert(&a,"arboricolE",10);
	printf("test d'affichage sur a :\n\n");
	affichage(a);
	printf("\n");
	printf("test de rechercheMotif sur a avec le motif arb :\n\n");
	rechercheMotif(a,"arb",3);
	printf("\n");
	printf("test de recherche de motif inexistant dans a avec le motif co :\n\n");
	rechercheMotif(a,"co",2);
	printf("\n");
	printf("liberation de a\n\n");
	liberer(a);
	printf("test insertion dans b depuis le fichier test.txt\n\n");
	insertionFichierTexte(&b,"test.txt");
	printf("affichage de b : \n\n");
	affichage(b);
	printf("\n");
	printf("test d'insertion de mot deja existant avec vert \n\n");
	insert(&b,"verT",4);
	printf("2e affichage de b : \n\n");
	affichage(b);
	printf("\n");
	printf("liberation de b\n\n");
	liberer(b);
	printf("fin des tests\n");
	return 0;
}
