#include <stdio.h>

int main()
{
  long long n, x0, ai, i, px0, px0_;
  
  scanf("%lld\n", &n);
  scanf("%lld\n", &x0);
  
  px0 = 0; px0_ = 0;
  for (i = 0; i < n+1; i++)
  {
    scanf("%lld", &ai);
    px0 = px0 * x0 + ai;
    if (i != n) 
        	px0_ = px0_ * x0 + ai * (n - i);
  }
  
  printf("%lld %lld\n", px0, px0_);
  return 0;
}
