main: main.cpp LinkedList.o LinkedList.h ListIterator.o ListIterator.h
	g++ main.cpp -o main -std=c++11 LinkedList.o ListIterator.o
	
ListIterator.o: ListIterator.cpp Iterator.h LinkedList.h
	g++ ListIterator.cpp -c -std=c++11
	
LinkedList.o: LinkedList.cpp LinkedList.h Iterator.h
	g++ LinkedList.cpp -c -std=c++11
	
clean:
	rm main LinkedList.o ListIterator.o