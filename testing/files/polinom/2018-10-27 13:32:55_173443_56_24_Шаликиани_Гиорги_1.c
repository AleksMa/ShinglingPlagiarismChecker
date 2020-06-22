#include <stdio.h>

int main()
{
        int long long x, n, i = 0, N=0, P = 0, x0, k[100];
	scanf("%lld", &n);
	scanf("%lld", &x0);
	if (n == 0)
		N = 1;
	else
	{
		for (i = 0; i < (n + 1); i++)
		{
			scanf("%lld", &k[i]);
		}

	}


	for (i = 0; i < n; i++)
	{
		N = (N + k[i])*x0;
		
	}
	N += k[i];
	printf("%lld ", N);
	x = n ;
	for (i = 0; i < (n - 1); i++)
	{
		P = (P + x * k[i])*x0;
			x--;
	}
	P += k[i];
	printf("%lld", P);          

	return 0;
}
