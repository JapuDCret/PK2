#include <stdio.h>
#include "LinkedList.h"
using namespace pk2;

void print_values(LinkedList* list, int max_size);
void delete_values(LinkedList* list, int max_size);
void test_work(const char* str);

int main(void)
{
  printf("Starting...\n\n");
  
  LinkedList* list = new LinkedList();
  
  //printf("first: %s\n", list->get_first());
  //printf("last: %s\n", list->get_last());
  
  const char* str1 = "abc";
  printf("appending '%s', return: %d\n", str1, list->append(str1));
  printf("first: %s\n", list->get_first());
  printf("last: %s\n", list->get_last());
  
  const char* str2 = "xyz";
  printf("appending '%s', return: %d\n", str2, list->append(str2));
  printf("first: %s\n", list->get_first());
  printf("last: %s\n", list->get_last());
  
  const char* str3 = "123";
  printf("appending '%s', return: %d\n", str3, list->append(str3));
  printf("first: %s\n", list->get_first());
  printf("last: %s\n", list->get_last());
  
  printf("indexof '%s', return: %d\n", str1, list->index_of(str1));
  printf("indexof '%s', return: %d\n", str2, list->index_of(str2));
  printf("indexof '%s', return: %d\n", str3, list->index_of(str3));
  
  print_values(list, 5);
  
  const char* str4 = "mmm";
  int pos4 = 1;
  printf("inserting '%s' at %d, return: %d\n", str4, pos4, list->insert(str4, pos4));
  printf("first: %s\n", list->get_first());
  printf("last: %s\n", list->get_last());
  
  printf("indexof '%s', return: %d\n", str1, list->index_of(str1));
  printf("indexof '%s', return: %d\n", str2, list->index_of(str2));
  printf("indexof '%s', return: %d\n", str3, list->index_of(str3));
  printf("indexof '%s', return: %d\n", str4, list->index_of(str4));
  
  print_values(list, 5);
  
  printf("executing test_work..\n");
  printf("Result: ");
  list->visit_all(&test_work);
  printf("\n");
  
  print_values(list, 5);
  
  printf("deleting at %d, result: %d\n", pos4, list->remove(pos4));
  
  printf("executing test_work..\n");
  printf("Result: ");
  list->visit_all(&test_work);
  printf("\n");
  
  delete_values(list, 5);
  
  print_values(list, 5);
  
  printf("executing test_work..\n");
  printf("Result: ");
  list->visit_all(&test_work);
  printf("\n");
  
  print_values(list, 5);
  
  delete_values(list, 5);
  
  print_values(list, 5);
  
  printf("Stopping...\n");
  return 0;
}

void print_values(LinkedList* list, int max_size)
{
    int i;
    for(i=0; i < max_size; i++)
    {
      printf("get at %d, result: %s\n", i, list->get(i));
    }
}

void delete_values(LinkedList* list, int max_size)
{
    int i;
    for(i=max_size; i > 0; i--)
    {
      printf("deleting at %d, result: %d\n", i-1, list->remove(i-1));
    }
}

void test_work(const char* str)
{
  printf("%s, ", str);
}