double min(double a[], int n)
{
  double min = 0.0;
  int isFirst = ~0;
  
  int i;
  for(i=0; i < n; i++)
  {
    if(isFirst || a[i] < min)
    {
      min = a[i];
    }
    isFirst = 0;
  }

  return min;
}
