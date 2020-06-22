#include <stdio.h>

int main()
{
        unsigned int n, i;
	
	scanf("%d", &n);

	long x0, a[n + 1], p, dp = 0;
	
	scanf("%ld", &x0);

	if (n == 0) {
		scanf("%ld", &a[0]);
		p = a[0]; }
	else {
		for (i = 0; i <= n; i++)
			scanf("%ld", &a[i]);
		p = a[0];
		dp = n * a[0];
		for (i = 1; i <= n; i++) {
			p = p * x0 + a[i];
			if (i < n)
				dp = dp * x0 + (n - i) * a[i]; }}
	 
	printf("%ld %ld", p, dp);
	
	return 0;
}