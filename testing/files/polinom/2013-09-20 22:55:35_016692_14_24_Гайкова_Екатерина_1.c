
#include <stdio.h>

int main()
{
        int n;
        long i, a, x0, sum1, sum2;
        scanf("%u", &n);
        scanf("%lld", &x0);
        scanf("%lld", &sum1);
        sum2 = sum1*n;
        for (i = 0; i < n; i++)
        {
                scanf("%lld", &a);
                sum1 = sum1 * x0 + a;
                if (n-1-i > 0) sum2 = sum2*x0 + a*(n-i-1);
        }	    
        printf("%lld %lld\n", sum1, sum2);
	return 0;
}
