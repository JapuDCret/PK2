#include <stdio.h>
#include "ascii.h"
#include "einmaleins.h"
#include "dualzahl.h"
#include "fakultaet.h"
#include "binomial.h"

int main()
{
  printf("ASCII Function:\n");
  print_ascii(10);

  printf("Einmaleins Function:\n");
  int start;
  int ende;
  printf("Von: ");  
  scanf("%d", &start);
  printf("Bis: ");
  scanf("%d", &ende);

  //printf("Start: %d, Ende: %d\n", start, ende);
  print_einmaleins(start,ende);
  
  printf("Dualzahl Function:\n");
  int x;
  printf("Welche Zahl umwandeln: ");
  scanf("%d", &x);
  print_dualzahl(x);
  
  printf("Fakultaet Function:\n");
  printf("fakultaet(4)=%d\n", fakultaet(4));
  printf("fakultaet(0)=%d\n", fakultaet(0));
  
  printf("Binomial Function\n");
  printf("binomial(10 0)=%d\n", binomial(10,0));
  printf("binomial(10,1)=%d\n", binomial(10,1));
  printf("binomial(10,10)=%d\n", binomial(10,10));
  printf("binomial(49,6)=%d\n", binomial(49,6));
  
  return 0;
}
