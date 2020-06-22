
#include <stdio.h>

int main()
{
        int a, n, x, i;
        long p, pp;
        scanf ("%d%d", &n, &x);
        scanf ("%d", &a);
        if (n>0) {p = a*x;
                if (n>1) pp = a*n*x;
                else pp=a*n;
                for (i=1; i <= n; i++){
                        scanf ("%d", &a);
                        if (n-i>0) {
                                p = (p+a)*x;
                                if (n-i>1) pp = (pp+a*(n-i))*x;
                                else pp += a*(n-i);
                        } else p += a;
                }
        } else p=a;
        printf ("%ld %ld", p, pp);
        return 0;
} 

