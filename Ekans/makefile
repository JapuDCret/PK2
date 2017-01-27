main: main.o
	g++.exe -static -static-libgcc -static-libstdc++ -o "Ekans.exe" main.o -std=c++11
	
main.o: main.cpp
	g++.exe -Wall -c -g main.cpp -o main.o -std=c++11
	
clean:
	rm main