main: main.cpp Matrix.o
	g++ main.cpp -o main -std=c++11 Matrix.o
	
Matrix.o: Matrix.cpp
	g++ Matrix.cpp -c -std=c++11
	
clean:
	rm main Matrix.o