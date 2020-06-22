
#include <stdio.h>

int N;
long num, x;
long pol, der = 0;
int main() {
  scanf("%d%ld%ld", &N, &x, &pol);
  der = pol*N;
  for (int i = 1; i < N; i++){
    scanf("%ld", &num);
    pol = pol*x+num;
    der = der * x + num*(N-i);
  }
  scanf("%ld", &num);
  pol = pol*x+num;
  printf("%ld %ld\n", pol, der);
  return 0;
}