all : tp3

tp3 : pile.o affichage.o insertion.o recherche.o main.o
	gcc -Wall -Wextra -ansi -pedantic -o tp3 pile.o main.o insertion.o affichage.o recherche.o

pile.o : pile.c pile.h
	gcc -Wall -Wextra -ansi -pedantic -o pile.o -c pile.c

affichage.o : affichage.c pile.h
	gcc -Wall -Wextra -ansi -pedantic -o affichage.o -c affichage.c

insertion.o : insertion.c
	gcc -Wall -Wextra -ansi -pedantic -o insertion.o -c insertion.c
	
recherche.o : recherche.c insertion.h
	gcc -Wall -Wextra -ansi -pedantic -o recherche.o -c recherche.c

main.o : main.c pile.h affichage.h insertion.h recherche.h pile.h
	gcc -Wall -Wextra -ansi -pedantic -o main.o -c main.c

clean :
	rm -rf *.o

mrproper : clean
	rm -rf tp3
