#include <stdio.h>
#include "queue.h"

int main(void)
{
  enqueue(1);
  enqueue(2);
  enqueue(2);
  printf("%d ", dequeue());
  enqueue(3);
  printf("%d ", dequeue());
  printf("%d ", dequeue());
  printf("%d ", dequeue());
  enqueue(4);
  enqueue(5);
  printf("%d ", dequeue());
  printf("%d \n", dequeue());
}
