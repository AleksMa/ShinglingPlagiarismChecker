
#include <stdio.h>

int main()
{       long long p,pr;
        long i, n, x;
        scanf ("%ld", &n);
        scanf ("%ld", &x);
        long mass[n];
        for (i = 0; i <= n; i++)
                scanf ("%ld", &mass[i]);
        p= mass[0] * x + mass[1];
        for (i = 2; i <= n ; i++)
                p=p * x + mass[i];
        if (n == 1) pr = mass[0];
                else {
                        pr=mass[0]*x*n + mass[1]*(n-1);
                        for (i = 2; i < n; i++)
                                pr = pr * x + mass[i] * (n - i);
                };
        printf("%lld %lld\n", p , pr);
	return 0;
}
