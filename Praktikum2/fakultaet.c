#include <stdio.h>

int fakultaet(int n)
{
  if(n < 0)
  {
    printf("Wrong input for n(%d)! Abort.\n", n);
    return -1;
  }

  int result = 1;
  
  int i;
  for(i=2; i <= n; i++) {
    result *= i;
  }

  return result;
}
