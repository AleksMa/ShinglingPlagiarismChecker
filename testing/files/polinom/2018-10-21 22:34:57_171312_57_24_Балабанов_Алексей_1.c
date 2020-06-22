#include <stdio.h>

int main() {
  long x, n, p = 0, q = 0;
  scanf("%ld%ld", &n, &x);
  for (long i = n; i > 0; i--){
    long a;
    scanf("%ld ", &a);
    p = (p + a) * x;
    q = i==1 ? (q + a*i) : (q + a*i) * x;
  }
  scanf("%ld", &n); p += n;
  printf("%ld %ld", p, q);
  return 0;
}