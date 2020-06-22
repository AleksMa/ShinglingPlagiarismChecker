#include <stdio.h>

int main(int argc, char **argv)
{
        long n, x0, a;
	long long currentres = 0, pr = 0;
	scanf("%ld", &n);
	scanf("%ld", &x0);
	long coef[n];
	for(long i = 0; i<=n; i++)
		{
		 scanf("%ld", &coef[i]);
		}
	for(long i = 0; i<n; i++)
		{
		 currentres += coef[i];
		 currentres *= x0;
		}
	for(long i = 0; i<n-1; i++)
		{
		 pr += coef[i]*(n-i);
		 pr *= x0;
		}
	currentres += coef[n];
	pr += coef[n-1];
	printf("%lld %lld\n", currentres, pr);
	return 0;
}