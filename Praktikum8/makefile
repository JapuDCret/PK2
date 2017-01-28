main: main.cpp Audio.o Bild.o
	g++ main.cpp -o main -std=c++11 Audio.o Bild.o
	
Audio.o: Audio.cpp
	g++ Audio.cpp -c -std=c++11
	
Bild.o: Bild.cpp
	g++ Bild.cpp -c -std=c++11
	
clean:
	rm Audio.o Bild.o main