#include <stdio.h>
#include "struct.h"
#include "insertion.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define TAILLE 30

arbre_t ** recherche(arbre_t * a, char mot[], int l,int * i)
{ /*mot en minuscule*/
  arbre_t * cour = a;
  arbre_t ** prec = NULL;
  while((cour =! NULL) && (*i<l))
  /* on sort quand on a la bonne lettre ou qu'on a dépassé le mot */
  {
    if (tolower(cour->lettre) == mot[*i])
    {
      prec = &cour;
      cour = cour->lv;
      *i+=1;
    }
    else
    {
      prec = &cour;
      cour = cour->lh;
    }
  }
  return prec;
}

void insert(arbre_t * a, char mot[], int l )
{ /*faire insertion fils*/
  int i = 0;
  arbre_t * ins = NULL;
  arbre_t * temp = NULL;
  arbre_t ** m = recherche(a,mot,l,&i);
  if (i < l)
  {
    mot[l-1] = toupper(mot[l-1]);
    ins = (arbre_t *) malloc(sizeof(arbre_t));
    ins->lettre = mot[i];
    temp = *m;
    *m = ins;
    ins->lh = temp;
    i++;
    while(i<l)
    {
      temp = ins;
      ins = (arbre_t *) malloc(sizeof(arbre_t));
      ins->lettre = mot[i];
      temp->lv = ins;
      i++;
    }
  }
}


void insertionFichierTexte(arbre_t * a, char nomFichier[])
{
  FILE * fichier = NULL;
  char mot[TAILLE] ="";
  fichier = fopen(nomFichier,"r");
  if (fichier != NULL)
  {
    while(fgets(mot,TAILLE,fichier) != NULL)
    {
      printf("%s",mot);
      insert(a,mot,strlen(mot));
    }
  }
  else
  {
    printf("problème d'ouverture du fichier");
  }
  fclose(fichier);
}
