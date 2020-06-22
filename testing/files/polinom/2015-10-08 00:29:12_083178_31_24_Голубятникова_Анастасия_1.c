#include <stdio.h>
#include <math.h>
int main(void)
{
  long long int x, max, P=0, P1=0, a;
  scanf("%lld", &max);
  scanf("%lld", &x);
  for (;max>-1; max--){
    scanf("%lld", &a);
    P*=x; P+=a;
    if (max!=0) {
      P1*=x;
      P1+=a*max;
    }
  }
  printf("%lld %lld\n", P, P1);
  return 0;
}