#include <stdio.h>

int main() 
{
        int n, x0;
	long long result = 0, der = 0;
	long long p = 1;
	scanf("%d", &n);
	scanf("%d", &x0);
	long long k = n + 1;
	long long a[k], A[n];
	for (int i = 0; i < k; i++) scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++) 
	{	A[i] = a[i] * (n - i);
	}

	for (int i = 0; i < k; i++)
	{
		if (i == 1) result = a[0] * x0 + a[1];
		else result = (result * x0) + a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (i == 1) der = A[0] * x0 + A[1];
		else der = (der * x0) + A[i];
	}
	printf("%lld %lld\n", result, der);
}
