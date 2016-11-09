#include <stdio.h>

#define START 32
#define END 126


void print_ascii(int s)
{
  int i;
  for(i = 0; i <= END-START; i++)
  {
    printf("(%3d, %c) ", (i+START), (char) (i+START));
    if(i % s == s - 1)
    {
      printf("\n");
    }
  }
  printf("\n");
}
