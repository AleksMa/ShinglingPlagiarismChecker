#include <stdio.h> <inttypes.h>

int main(int argc, char **argv)
{
        long n, x, i;
        long long p, dp;
	n = x = i = p = dp = 0;
	scanf("%ld\n%ld\n", &n, &x);
	long a[n+1];
	for (i = 0; i < (n + 1); i++) scanf("%ld", &a[i]);
	if (n > 0) {
		for (i = 0; i < n; i++) p = (p + a[i])*x;
		for (i = 0; i < (n - 1); i++) dp = (dp + a[i]*(n-i))*x;
		p += a[n];
		dp += a[n-1];
	} printf ("%lld %lld\n", p, dp);
	return 0;
}