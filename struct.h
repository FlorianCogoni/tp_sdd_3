/*
 ______________________________________________________________________________________
|                                                                                      |
|                              ___________________                                     |
|                             |                   |                                    |
|                             |      struct.h     |                                    |
|                             |___________________|                                    |
|                                                                                      |
|______________________________________________________________________________________|

	Ce fichier contient la structure de l'arbre.

*/


#ifndef STRUCTURE
#define STRUCTURE

typedef struct arbre
{
	char 		         lettre;	/* la lettre */
	struct arbre   * lv;			/* lien vertical */
	struct arbre   * lh;			/* lien horizontal */
} arbre_t;

#endif
