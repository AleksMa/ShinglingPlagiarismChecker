#include <stdio.h>

int main()
{
  long x, p=0, pp=0;
  int n, i;
  scanf ("%d%ld", &n, &x);
  int a[n];
  for (i=n; i>=0; i--)
    scanf ("%d", &a[i]);
  p = a[n];
  for (i=n; i>=1; i--)
    p = p * x + a[i-1];
  pp = a[n] * n;
  for (i=n; i>=2; i--)
    pp = pp * x + (i-1) * a[i-1];
  printf ("%ld %ld \n", p, pp);
  return 0;
}