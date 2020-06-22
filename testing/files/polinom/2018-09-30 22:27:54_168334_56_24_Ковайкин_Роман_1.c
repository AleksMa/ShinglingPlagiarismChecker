#include "stdio.h"
#include "math.h"


int main(int argc, char const *argv[]) {
  long long n, x0, pol = 0, pr = 0;
  scanf("%lld %lld", &n, &x0);
  long long koef [n+1];

  for(long long i = 0; i<=n; i++){
    scanf("%lld", &koef[i]);
  }

  for (long long i = 0; i<=n; i++){
    pol*=x0;
    pol+= koef[i];
  }
  for (long long i =1 ; i<=n; i++){
    pr = x0*pr +koef[i-1] * (n-i+1);
  }
  printf("%lld %lld", pol, pr);
  return 0;
}