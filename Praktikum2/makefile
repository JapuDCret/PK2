main:libmy.a main.c
	gcc main.c -o main -L. -lmy

libmy.a:ascii.o einmaleins.o dualzahl.o fakultaet.o binomial.o
	ar r libmy.a ascii.o einmaleins.o dualzahl.o fakultaet.o binomial.o

binomial.o:fakultaet.o binomial.c
	gcc binomial.c -c

fakultaet.o:fakultaet.c
	gcc fakultaet.c -c

dualzahl.o:dualzahl.c
	gcc dualzahl.c -c

einmaleins.o:einmaleins.c
	gcc einmaleins.c -c

ascii.o:ascii.c
	gcc ascii.c -c

clean:
	rm ascii.o einmaleins.o dualzahl.o fakultaet.o binomial.o libmy.a main
