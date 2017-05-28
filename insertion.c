#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "struct.h"
#include "insertion.h"
#include "pile.h"

#define TAILLE_MOTS 30 /* taille maximale des mots */
#define NB_BLOCS 200 /* nombre de blocs (de l'arbre) maximal */

arbre_t * recherche(arbre_t * a, char mot[], int l, int * i, int * parente)
{
  arbre_t * prec = a;
  arbre_t * cour = a;
  while(cour != NULL && tolower(cour->lettre) <= tolower(mot[*i]) && *i<l)
    /*on a pas atteint une extremite de l'arbre et l'on a pas depasse la lettre*/
  {
    if(cour->lettre == mot[*i])
      /*s'il s'agit de la bonne lettre*/
    {
      /*on continue de chercher a partir du lien vertical*/
      prec = cour;
      cour = cour->lv;
      *i += 1;          /*on incremente la position dans le mot*/
      *parente = 1;     /* le lien de parente est vertical*/
    }
    else
      /* sinon on continue à chercher la lettre a partir du lien horizontal*/
    {
      prec = cour;
      cour = cour->lh;
      *parente = 2;     /*la parente est horizontal*/
    }
  }
  return prec;
}

void insert(arbre_t ** a, char mot[], int l )
/* la derniere lettre de mot doit être en majuscule*/
{
  arbre_t * nouv = NULL;
  arbre_t * temp = NULL;
  int i = 0;
  int parente = 0;
  arbre_t * adr_ins = recherche(*a,mot,l,&i,&parente);/*on recherche l'adresse a partir de laquelle on insere*/
  if (i < l)
    /*si le mot n'est pas present dans l'arbre*/
  {
    if(*a != NULL)
      /*si l'on insere dans un arbre non vide*/
    {
      nouv = (arbre_t *) malloc(sizeof(arbre_t));
      nouv->lettre = mot[i];
      nouv->lv = NULL;
      nouv->lh = NULL;
      switch (parente)
      {
        case 1 : /*on insere a partir du lien vertical*/
              temp = adr_ins->lv;
              adr_ins->lv = nouv;
              break;
        case 2 : /* on insere depuis le lien horizontal*/
              temp = adr_ins->lh;
              adr_ins->lh = nouv;
              nouv->lh = temp;      /*on raccorde*/
              break;
        default : /*on insere en tete*/
              temp = (arbre_t *) malloc(sizeof(arbre_t));
              *temp = *adr_ins;
              *adr_ins = *nouv;
              adr_ins->lh = temp;
              nouv = adr_ins;
              break;
      }

      i++;                  /*on passe a la lettre suivante*/
    }
    else
      /*si l'arbre est vide*/
    {
      *a = (arbre_t *) malloc(sizeof(arbre_t));
      (*a)->lettre = mot[i];
      (*a)->lv = NULL;
      (*a)->lh = NULL;
      nouv = *a;
      i++;
    }
    while(i<l)
      /*jusqu'a la derniere lettre on insere verticalement les lettres du mots*/
    {
      temp = nouv;
      nouv = (arbre_t *) malloc(sizeof(arbre_t));
      nouv->lettre = mot[i];
      nouv->lh = NULL;
      nouv->lv = NULL;
      temp->lv = nouv;
      i++;
    }
  }
  else
    /*si les lettres du mot sont deja dans l'arbre*/
  {
    adr_ins->lettre = mot[l-1];   /*on met la derniere lettre du mot en majuscule*/
  }
}


void liberer(arbre_t * a)
{
	int fin=0;
	arbre_t * cour = a;
	pile_t * pPileParcours = initPile(NB_BLOCS); /* pile pour parcourir l'arbre */
	pile_t * pPileAliberer = initPile(NB_BLOCS); /* pile pour entasser les adresse à libérer */
	while (!fin)
	{
		while (cour != NULL)
		{
			empile(pPileParcours,cour); /* on empile les adresse pour pouvoir revenir aux pères */
      		empile(pPileAliberer,cour); /* on empile chaque nouvelle adresse */
			cour = cour->lv;
		}
		if (! estVide(pPileParcours))
		{
			depile(pPileParcours,&cour); /* on revient aux pères */
			cour=cour->lh;
		}
		else
		{
			fin = 1;
		}
	}
	while (! estVide(pPileAliberer)) /* tant qu'on a pas libéré toutes les adresse */
	{
		depile(pPileAliberer,&cour); /* on dépile les adresse à libérer */
		free(cour);
	}
	libererPile(pPileParcours); /* on libère les 2 piles */
	libererPile(pPileAliberer);
}


void insertionFichierTexte(arbre_t ** a, char nomFichier[])
{
	/* les mots du fichier doivent avoir leur dernière lettre en majuscule */
  FILE * fichier = NULL;
  char mot[TAILLE_MOTS] ="";
  fichier = fopen(nomFichier,"r");
  if (fichier != NULL)
  {
    while(fgets(mot,TAILLE_MOTS,fichier) != NULL) /* tant qu'on est pas à la fin du fichier */
    {
      insert(a,mot,strlen(mot)); /* on insère le mot qu'on vient de lire dans le fichier */
    }
  }
  else
  {
    printf("problème d'ouverture du fichier");
  }
  fclose(fichier);
}
