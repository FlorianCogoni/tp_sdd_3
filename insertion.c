#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "struct.h"
#include "insertion.h"

#define TAILLE 30

arbre_t * recherche(arbre_t * a, char mot[], int l, int * i, int * parente)
{
  arbre_t * prec = NULL;
  arbre_t * cour = a;
  while(cour != NULL && tolower(cour->lettre) <= tolower(mot[*i]) && *i<l)
  {
    if(cour->lettre == mot[*i])
    {
      prec = cour;
      cour = cour->lv;
      *i += 1;
      *parente = 1;
    }
    else
    {
      prec = cour;
      cour = cour->lh;
      *parente = 2;
    }
  }
  return prec;
}

void insert(arbre_t ** a, char mot[], int l )
{
  arbre_t * nouv;
  arbre_t * temp;
  int i = 0;
  int parente = 0;
  arbre_t * adr_ins = recherche(*a,mot,l,&i,&parente);
  if (i < l)
  {
    if(*a != NULL)
    {
      nouv = (arbre_t *) malloc(sizeof(arbre_t));
      nouv->lettre = mot[i];
      nouv->lv = NULL;
      nouv->lh = NULL;
      if(parente == 1){
          temp = adr_ins->lv;
          adr_ins->lv = nouv;
      }
      else{
        temp = adr_ins->lh;
        adr_ins->lh = nouv;
      }
      nouv->lh = temp;
      i++;
    }
    else
    {
      *a = (arbre_t *) malloc(sizeof(arbre_t));
      (*a)->lettre = mot[i];
      (*a)->lv = NULL;
      (*a)->lh = NULL;
      nouv = *a;
      i++;
    }
    while(i<l)
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
  {
    adr_ins->lettre = mot[l-1];
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


char * derniereLettreEnMaj(char mot[],int l)
{
  mot[l-1]=toupper(mot[l-1]);
  return mot;
}

void insertionFichierTexte(arbre_t ** a, char nomFichier[])
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
