#include <stdio.h>

void print_einmaleins(int start, int ende)
{
  int i;
  for(i = 0; i < 10; i++)
  {
    int k;
    for(k = start; k <= ende; k++)
    {
      printf("%3d ", (i+1)*k);
    }
    printf("\n");
  }
}
