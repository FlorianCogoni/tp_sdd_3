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
  arbre_t * nouv;
  arbre_t * temp;
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
      if(parente == 1){
        /*on insere a partir du lien vertical*/
          temp = adr_ins->lv;
          adr_ins->lv = nouv;
      }
      else{
        /* on insere depuis le lien horizontal*/
        temp = adr_ins->lh;
        adr_ins->lh = nouv;
      }
      nouv->lh = temp;      /*on raccorde*/
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
  if(a == NULL)
    /* si l'arbre est vide*/
  {
    free(a);
  }
  else
  {
    if (a->lh == NULL && a->lv == NULL)
      /*si les arbres freres et fils sont vide*/
    {
      free(a);              /*on peut liberer l'arbre*/
    }
    else
      /* si l'arbre frere ou fils n'est pas vide*/
    {
      if (a->lv != NULL)
        /*si l'arbre fils n'est pas vide*/
      {
        /* on le libere */
        liberer(a->lv);
        a->lv = NULL;
      }
      if (a->lh != NULL)
        /*si l'arbre frere n'est pas vide*/
      {
        /* on le libere */
        liberer(a->lh);
        a->lh = NULL;
      }
    }
  }
}


/*char * derniereLettreEnMaj(char mot[],int l)
{
  mot[l-1]=toupper(mot[l-1]);
  return mot;
}*/

void insertionFichierTexte(arbre_t ** a, char nomFichier[])
{
  FILE * fichier = NULL;
  char mot[TAILLE] ="";
  fichier = fopen(nomFichier,"r");
  if (fichier != NULL)
  {
    while(fgets(mot,TAILLE,fichier) != NULL)
    {
      /*printf("%s",mot);*/
      insert(a,mot,strlen(mot));
    }
  }
  else
  {
    printf("problème d'ouverture du fichier");
  }
  fclose(fichier);
}
