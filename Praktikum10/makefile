main: main.cpp LinkedList.o ListIterator.o
	g++ main.cpp -o main -std=c++11 LinkedList.o ListIterator.o
	
LinkedList.o: LinkedList.cpp ListIterator.o
	g++ LinkedList.cpp -c -std=c++11 ListIterator.o
	
ListIterator.o: ListIterator.cpp
	g++ ListIterator.cpp -c -std=c++11
	
clean:
	rm main LinkedList.o