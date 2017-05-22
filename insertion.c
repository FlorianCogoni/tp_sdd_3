#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "struct.h"
#include "insertion.h"

#define TAILLE 30

arbre_t ** recherche(arbre_t * a, char mot[], int l, int * i)
{
  arbre_t * cour = a;
  arbre_t ** prec = &a;
  while(cour != NULL && tolower(cour->lettre) <= tolower(mot[*i]) && *i<l)
  {
    if(cour->lettre == mot[*i])
    {
      prec = &(cour->lv);
      cour = cour->lv;
      *i += 1;
    }
    else 
    {
      prec = &(cour->lh);
      cour = cour->lh;
    }
  }
  return prec;
}

void insert(arbre_t ** a, char mot[], int l )
{
  arbre_t * ins;
  arbre_t * temp;
  int i = 0;
  arbre_t ** m = recherche(*a,mot,l,&i);
  if (i < l) 
  {
    if(*a != NULL) 
    {
      ins = (arbre_t *) malloc(sizeof(arbre_t));
      ins->lettre = mot[i];
      ins->lv = NULL;
      ins->lh = NULL;
      temp = *m;
      *m = ins;
      ins->lh = temp;
      i++;
    }
    else
    {
      *a = (arbre_t *) malloc(sizeof(arbre_t));
      (*a)->lettre = mot[i];
      (*a)->lv = NULL;
      (*a)->lh = NULL;
      ins = *a;
      i++;
    }
    while(i<l)
    {
      temp = ins;
      ins = (arbre_t *) malloc(sizeof(arbre_t));
      ins->lettre = mot[i];
      ins->lh = NULL;
      ins->lv = NULL;
      temp->lv = ins;
      i++;
    }
  }
  else
  {

}

}

void liberer(arbre_t * a)
{
  if(a == NULL)
  {
    free(a);
  }
  else 
  {
    if (a->lh == NULL && a->lv == NULL) 
    {
      free(a);
    } 
    else 
    {
      if (a->lv != NULL) 
      {
        liberer(a->lv);
        a->lv = NULL;
      }
      if (a->lh != NULL) 
      {
        liberer(a->lh);
        a->lh = NULL;
      }
    }
  }
}





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
