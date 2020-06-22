#include <stdio.h>

int main()
{
        long long n,x,i;
	long long pol = 0, pr = 0;
	scanf ("%lld%lld", &n, &x);
	long long  a[n];
	for (i = n; i >=0; i--) {
		scanf("%lld", &a[i]);
		pol = pol*x+a[i];
		} 
	for (i = n; i>0; i--) pr = pr*x + (a[i]*i);
	printf("%lld\n", pol);
	printf("%lld\n", pr);
	return 0;
}