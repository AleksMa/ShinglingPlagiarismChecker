
#include <stdio.h>

int main()
{
        long n, x0, a, p, dp;
	scanf("%ld%ld", &n, &x0);
	for (p = dp = 0; n > 0; n--) {
		scanf("%ld", &a);
		p = p*x0 + a;
		dp = dp*x0 + a*n;
	}

	scanf("%ld", &a);
	p = p*x0 + a;

	printf("%ld %ld\n", p, dp);
}  
 