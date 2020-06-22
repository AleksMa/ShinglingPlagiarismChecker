#include <stdio.h>

int main () 
{
  int a, n, x, i = 0;
  long polinom = 0, proiz = 0;
  scanf("%d%d", &n, &x); 
  for (i = n; i >= 0; i--)
  {
    scanf("%d", &a); 
    polinom = polinom * x + a;
    if(i>0) {
      proiz = proiz * x + a * i;
    }
  }
  printf("%ld %ld", polinom, proiz);
  return 0;
}               