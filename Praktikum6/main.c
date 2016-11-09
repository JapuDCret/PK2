#include <stdio.h>
#include "countspace.h"
#include "min.h"
#include "stringcat.h"

int main()
{
  char str1[] = "Hallo Welt!";
  char str2[] = "Ich bin ein langer Satz.";
  printf("countspace von \"%s\": %d\n", str1, countspace(str1));
  printf("countspace von \"%s\": %d\n", str2, countspace(str2));
  
  double values1[] = { 5.0, 10.2, 42.0, 3.14159 };
  double values2[] = {};
  printf("min von [5,10.2,42,3.14159]: %f\n", min(values1, 4));
  printf("min von []: %f\n", min(values2, 0));  
  
  char * newstr = stringcat(str1, str2);
  printf("stringcat von \"%s\"(%d) und \"%s\"(%d): \"%s\"(%d)\n", str1, strlength(str1), str2, strlength(str2), newstr, strlength(newstr));
  
  return 0;
}
