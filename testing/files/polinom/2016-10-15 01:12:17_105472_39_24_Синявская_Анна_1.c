
#include <stdio.h>

long count(long a[], long x, int n)
{
        int i;
	long b = a[n];
	for (i = n; i >0 ; i--)
	b = b*x + a[i-1]; 
	return b;
}
long derivative(long a[], long x, int n)
{
	int i;
	long b = a[n]*n;
	for (i = n-1; i >0 ; i--)
	b = b*x + a[i]*i;
	return b;
}

int main ()
{
	long x;
	int n, i;
	scanf("%d\n%ld", &n, &x);
	long a[n+1];
	for (i = n; i >=0; i--)
	{
		scanf(" %ld", &a[i]);
	}
	printf("%ld %ld\n", count(a, x, n), derivative (a, x, n));
	return 0;
}
