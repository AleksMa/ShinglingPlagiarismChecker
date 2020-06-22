
#include <stdio.h>

int main()
{
        long p = 0, pd = 0;

        long i, n, x, c;
        scanf("%ld\n%ld", &n, &x);
        for (i = 0; i < n; i++) 
        {
                scanf("%ld", &c);
                p *= x;
                p += c;
                pd *= x;
                pd += (n-i)*c;
        }
        scanf("%ld", &c);
        p *= x;
        p += c;
        printf("%ld %ld\n", p, pd);
        
        return 0;
}