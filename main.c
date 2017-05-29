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
	arbre_t * standard = NULL;
	arbre_t * doublons = NULL;
	arbre_t * vide = NULL;
	arbre_t * mots_decroissants = NULL;

	printf("test insertion depuis le fichier standard.txt\n\n");
	insertionFichierTexte(&standard,"standard.txt");
	printf("affichage de standard : \n\n");
	affichage(standard);
	printf("\n");

	printf("test insertion depuis le fichier doublons.txt\n\n");
	insertionFichierTexte(&doublons,"doublons.txt");
	printf("affichage de doublons : \n\n");
	affichage(doublons);
	printf("\n");

	printf("test insertion depuis le fichier vide.txt\n\n");
	insertionFichierTexte(&vide,"vide.txt");
	printf("affichage de vide : \n\n");
	affichage(vide);
	printf("\n");

	printf("test insertion depuis le fichier mots_decroissants.txt\n\n");
	insertionFichierTexte(&mots_decroissants,"mots_decroissants.txt");
	printf("affichage de mots_decroissants : \n\n");
	affichage(mots_decroissants);
	printf("\n");

	printf("test rechercheMotif sur standard avec le motif bo : \n");
	rechercheMotif(standard,"bo",2);

	printf("test rechercheMotif sur standard avec le motif abr : \n");
	rechercheMotif(standard,"abr",3);

	printf("test rechercheMotif sur standard avec le motif vide : \n");
	rechercheMotif(standard,"",0);

	printf("liberation des arbres \n");
	liberer(standard);
	liberer(doublons);
	liberer(vide);
	liberer(mots_decroissants);
	return 0;
}
