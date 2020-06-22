#include <stdio.h>

int main (int argc, char **argv)
{
  long long c, x, i;
  scanf("%lli", &c);
  scanf("%lli", &x);

  long long a[c+1];
  for (i = c; i >= 0; --i) scanf("%lli", &a[i]);
  long long sum = a[c];
  long long proiz = 0;
  for (int i = 1; i <= c; ++i){
      proiz = proiz * x + sum;
      sum = sum * x;
      sum = sum + a[c - i];
  }
  printf("%lli %lli\n", sum, proiz);
  return 0;
}
