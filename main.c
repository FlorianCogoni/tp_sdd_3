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
	printf("creation de l'arbre a \n");
	arbre_t * a = (arbre_t *) malloc(sizeof(arbre_t));
	a->lettre = 'a';
	a->lh = NULL;
	a->lv = NULL;
	printf("test d'affichage de a, qui ne contient pas de mot :\n");
	affichage(a);
	printf("insertion de mots dans l'arbre a \n");
	insert(&a,"bonjouR",7);
	insert(&a,"boN",3);
	insert(&a,"bonsoiR",7);
	insert(&a,"arbrE",5);
	insert(&a,"arborescenT",11);
	insert(&a,"arboricolE",10);
	printf("test d'affichage sur a :\n");
	affichage(a);
	printf("test de rechercheMotif sur a avec le motif arb :\n");
	rechercheMotif(a,"arb",3);
	printf("test de recherche de motif inexistant dans a avec le motif co\n");
	rechercheMotif(a,"co",2);
	printf("liberation de a\n");
	liberer(a);
	printf("creation de b vide\n");
	arbre_t * b = NULL;
	printf("test insertion dans b depuis le fichier test.txt :\n");
	insertionFichierTexte(&b,"test.txt");
	printf("affichage de b : \n");
	affichage(b);
	printf("test d'insertion de mot deja existant avec vert \n");
	insert(&b,"verT",4);
	printf("2e affichage de b : \n");
	affichage(b);
	printf("liberation de b\n");
	liberer(b);
	printf("fin des test\n");
	return 0;
}
