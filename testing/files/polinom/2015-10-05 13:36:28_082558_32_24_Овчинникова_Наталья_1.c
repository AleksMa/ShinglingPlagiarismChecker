#include <stdio.h>
 
int main()
{
        int n;  
        long x, i, a, a1;
        scanf("%d%ld%ld",&n, &x, &a1);
        unsigned long p1 = a1, p2 = a1 * n;
 
        for (i = 1; i < (n + 1); i++) {
                scanf ("%ld", &a);
                p1 = p1 * x + a;
                if (i < n) p2 = p2 * x + a * (n - i);
        }
 
        printf ("%ld %ld\n", p1, p2);
        return 0;
}
