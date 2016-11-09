main: main.c countspace.o min.o stringcat.o
	gcc main.c -o main countspace.o min.o stringcat.o

countspace.o: countspace.c
	gcc -c countspace.c

min.o: min.c
	gcc -c min.c

stringcat.o: stringcat.c
	gcc -c stringcat.c

clean:
	rm main countspace.o min.o stringcat.o
