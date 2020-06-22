#include <stdio.h>

int main(int argc, char **argv) {
  long n=0, x=0, i=0;
  scanf("%ld%ld", &n, &x);
  long a[n];
  for ( i = 0; i < n + 1; i++) 
    scanf("%ld", &a[i]);
long c=a[0];
long p=0;
  for (i = 0; i < n; i++) {
    c *= x;
    c += a[i+1];
    p = p * x + a[i] * (n - i);
  }
  printf("%ld\n%ld", c, p);
  return 0;
}