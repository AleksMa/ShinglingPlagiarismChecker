#include <stdio.h>

int main()
{
        long n = 0;
        long x0 = 0;
        long polynom = 0;
        long drv = 0;
        scanf ("%ld", &n);
        scanf ("%ld", &x0);
        long i;
        for (i=0; i<=n; i++)
        {  
                long a = 0;
                scanf ("%ld", &a);
                polynom = polynom * x0 + a;
                if (x0 != 0)
                {
                        drv = drv * x0 + a * (n - i);
                }
                else
                {
                        if (i == n-1)
                        {
                                drv = a;
                        }
                }
        }
        
        if (x0 != 0)
        {
                drv = drv / x0;
        }
        
        printf ("%ld %ld", polynom, drv);
        return 0;
}