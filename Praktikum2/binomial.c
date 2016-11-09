#include "fakultaet.h"

int binomial(int n, int k)
{
  return fakultaet(n) / (fakultaet(k) * fakultaet(n-k) );
}
