
#include <stdio.h>

int main()
{
        long long  p, k, x;
	long long  n, i;
	p= k = x = 0;
	scanf("%lli", &n);
	scanf("%lli", &x);
	long long a[n+1];
	for (i = 0; i < n + 1; i++) scanf("%lli", &a[i]);
	p = a[0];
	for (i = 1; i < n + 1; i++)  p = p*x + a[i];
	for (i=0; i<n+1; i++) a[i] = a[i] * (n - i);
	k = a[0];
	for (i=1; i<n; i++) k = k*x + a[i];
	printf("%lli %lli", p, k);
	return 0;
}
