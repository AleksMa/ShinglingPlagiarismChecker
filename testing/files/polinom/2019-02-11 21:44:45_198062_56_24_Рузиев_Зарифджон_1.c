#include <stdio.h>

int main()
{
        long n, x0;
        scanf("%ld%ld", &n, &x0);
        long a[n+1];
        
        for (long i = 0; i <= n; i++)
                scanf("%ld", &a[i]);
                
        long mn = 0, pr = 0;
        for (long i = 0; i <= n; i++)
        {
                pr = pr * x0 + mn;
                mn = mn * x0 + a[i];
        }
        
        printf("%ld %ld", mn, pr);
        return 0;
}