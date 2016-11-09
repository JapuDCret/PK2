#include <stdio.h>

#define BIT_COUNT 16

void print_dualzahl(int x) {
  if((x < 0) || (x > 65535)) {
    printf("Argument X is too large! Abort.\n");
    return;
  }
  int i;
  for(i=BIT_COUNT - 1; i >= 0; i--)
  {
    printf("%d", ((x & (1 << (i))) >> i));
  }
  printf("\n");
}
