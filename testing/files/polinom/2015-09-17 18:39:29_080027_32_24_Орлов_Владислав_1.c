#include <stdio.h>
int main()
{
  long long n, x_0, a, a1, i, cvalue, cvalue1;
  scanf("%lld\n", &n);
  scanf("%lld\n", &x_0);
  scanf("%lld\n", &a);
  if (n>0) scanf("%lld\n", &a1);
  cvalue = x_0*a + a1;
  if (n>1) cvalue1 = a*n*x_0 +a1*(n-1);
  else cvalue1 = a;
  for (i = n; i > 1; i--) {
    scanf("%lld\n", &a);
    cvalue = x_0*cvalue + a;
    if (i !=2) cvalue1 = cvalue1*x_0 + a*(i-2);
  }
  printf("%lld %lld\n", cvalue, cvalue1);
  return 0;
}
