#include <stdio.h>

int main() {
  
  int n;
  scanf("%d", &n);
  long x0;
  scanf("%ld", &x0);
  
  long p, der, ap;
  scanf("%ld", &p);
  der = 0;
  ap = p;
  int i;
  for (i = 0; i < n; i++) {
    long a = 0;
    scanf("%ld", &a);
    p = p * x0 + a;
    der = der * x0 + ap * (n-i);
    ap = a;
  }
  
  printf("%ld %ld", p, der);
  
  return 0;
}