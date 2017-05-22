#ifndef STRUCTURE
#define STRUCTURE

typedef struct arbre
{
	char 		         lettre;
	struct arbre   * lv;
	struct arbre   * lh;
} arbre_t;

#endif
