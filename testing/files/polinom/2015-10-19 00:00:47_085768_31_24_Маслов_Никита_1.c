#include <stdio.h>

int main() 
{
  
  int n;
  scanf("%d", &n);
  long x0;
  scanf("%ld", &x0);
  
  long p, pp, pr;
  scanf("%ld", &p);
  pp = p;
  pr = 0;
  int i;
  for (i = 0; i < n; i++) 
  {
    long a = 0;
    scanf("%ld", &a);
    p = p * x0 + a;
    pr = pr * x0 + pp * (n-i);
    pp = a;
  }
  
  printf("%ld %ld", p, pr);
  
  return 0;
}