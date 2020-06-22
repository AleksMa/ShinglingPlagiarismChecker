#include "stdio.h"

int main()
{
         long a[100], sum = 0, proiz = 0;
	 int n, i;
	 long x;
	 scanf("%d", &n);
	 scanf("%lld", &x);
	 for(i = n; i >= 0; i--)
	 {
	  scanf("%lld", &a[i]);
	 }
	 for(i = n; i >= 1; i--)
	 {
	  sum = sum * x + a[i];
	 }
	 sum = sum * x + a[0];
	 printf("%lld\n", sum);
	for(i = n; i >= 2; i--)
	 {
	  proiz = proiz * x + a[i] * i;
	 }
	proiz = proiz * x + a[1];
	printf("%lld\n",proiz);
	return 0;
}
