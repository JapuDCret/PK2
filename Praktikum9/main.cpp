#include <iostream>

#include "LinkedList.h"

using namespace pk2;

void ausgabe(const char* text){
  std::cout << text << std::endl;
}

// Test der LinkedList-Klasse
int main(){
  using namespace std;
  
  cout << "Hello world" << endl;
  
  cout << "1" << endl;
  LinkedList liste;
  cout << "2" << endl;
  liste.append("Element 1");
  cout << "3" << endl;
  liste.insert("Element 2", 1);
  cout << "4" << endl;
  
  cout << "Liste:" << endl;
  liste.visit_all(ausgabe);
  
  LinkedList liste2 = liste;
  
  cout << "Liste:" << endl;
  liste.visit_all(ausgabe);
  liste.remove(1);
  
  cout << "Liste:" << endl;
  liste.visit_all(ausgabe);
  
  cout << "Liste2:" << endl;
  liste2.visit_all(ausgabe);
  
  return 0;
}