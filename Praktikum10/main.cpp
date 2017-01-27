#include <iostream>
#include <string>
#include "Linkedlist.h"
#include "Linkedlist.cpp"

using namespace std;
using namespace pk2;


template<class T>
void print_values(LinkedList<T>* list, int max_size)
{
	int i;
	for(i=0; i < max_size; i++)
	{
		T* content = list->get(i);
		cout << "get at " << i << ", result: ";
		if(content)
			cout << (*content);
		else
			cout << "null";
		cout << endl;
	}
}

template<class T>
void delete_values(LinkedList<T>* list, int max_size)
{
	int i;
	for(i=max_size; i > 0; i--)
	{
		cout << "deleting at " << i-1 << ", result: " << list->remove(i-1) << endl;
	}
}

void test_work(string* content)
{
	if(content)
		cout << (*content);
	else
		cout << "null";
	cout << ", ";
}

int main(void)
{
	cout << "Starting..." << endl << endl;
	
	LinkedList<string>* list = new LinkedList<string>();
	
	//cout << "first: %s\n", list->get_first());
	//cout << "last: %s\n", list->get_last());
	
	string* str1 = new string("abc");
	cout << "appending '" << (*str1) << "', return: " << list->append(str1) << endl;
	cout << "first: " << (*list->get_first()) << endl;
	cout << "last: " << (*list->get_last()) << endl;
	
	string* str2 = new string("xyz");
	cout << "appending '" << (*str2) << "', return: " << list->append(str2) << endl;
	cout << "first: " << (*list->get_first()) << endl;
	cout << "last: " << (*list->get_last()) << endl;
	
	string* str3 = new string("123");
	cout << "appending '" << (*str3) << "', return: " << list->append(str3) << endl;
	cout << "first: " << (*list->get_first()) << endl;
	cout << "last: " << (*list->get_last()) << endl;
	
	cout << "indexof '" << (*str1) << "', return: " << list->index_of(str1) << endl;
	cout << "indexof '" << (*str2) << "', return: " << list->index_of(str2) << endl;
	cout << "indexof '" << (*str3) << "', return: " << list->index_of(str3) << endl;
	
	print_values(list, 5);
	
	string* str4 = new string("mmm");
	int pos4 = 1;
	cout << "inserting '" << (*str4) << "' at " << pos4 << ", return: " << list->insert(str4, pos4) << endl;
	cout << "first: " << (*list->get_first()) << endl;
	cout << "last: " << (*list->get_last()) << endl;
	
	cout << "indexof '" << (*str1) << "', return: " << list->index_of(str1) << endl;
	cout << "indexof '" << (*str2) << "', return: " << list->index_of(str2) << endl;
	cout << "indexof '" << (*str3) << "', return: " << list->index_of(str3) << endl;
	cout << "indexof '" << (*str4) << "', return: " << list->index_of(str4) << endl;
	
	print_values(list, 5);
	
	cout << "executing test_work..\n" << endl;
	cout << "Result: ";
	list->visit_all(&test_work);
	cout << endl;
	
	print_values(list, 5);
	
	cout << "deleting at " << pos4 << ", result: " << list->remove(pos4) << endl;
	
	cout << "executing test_work.." << endl;
	cout << "Result: ";
	list->visit_all(&test_work);
	cout << endl;
	
	delete_values(list, 5);
	
	print_values(list, 5);
	
	cout << "executing test_work.." << endl;
	cout << "Result: ";
	list->visit_all(&test_work);
	cout << endl;
	
	print_values(list, 5);
	
	delete_values(list, 5);
	
	print_values(list, 5);
	
	cout << "Stopping..." << endl;
	return 0;
}