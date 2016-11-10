#include <stdio.h>
#include "dictionary.h"

void test_work(int value, int flag);

int main(void)
{
  printf("Starting..\n\n");
  
  printf("size: %d\n", get_size());
  
  printf("executing test_work\n");
  visit_all(&test_work);
  printf("\n");
  
  printf("inserting %d, result: %d\n", 1, insert(1));
  printf("inserting %d, result: %d\n", 3, insert(3));
  printf(" deleting %d, result: %d\n", 3, delete(3));
  printf("inserting %d, result: %d\n", 5, insert(5));
  printf("is member %d, result: %d\n", 5, member(5));
  
  printf("executing test_work\n");
  visit_all(&test_work);
  
  printf("Stopping..\n");
  return 0;
}

void test_work(int value, int flag)
{
  printf("%d[%d], ", value, flag);
}