
#include <stdio.h>

int main()
{
        long n, x0;
        scanf("%ld", &n);
        scanf("%ld", &x0);
        
        	long i, a[n + 1];
        for(i = 0; i < (n + 1); i++) scanf("%ld", &a[i]);
        
        long p = a[0], d = 0;
        for (i = 1; i < (n + 1); i++) {
                p = x0 * p + a[i];
                d = x0 * d + a[i - 1] * (n - i + 1);
        }
        printf ("%ld %ld\n", p, d);

	return 0;
}

