#include <stdio.h>
int main (int argc , char ** argv )
{
        long x = 0, n = 0, i = 0, p = 0, s = 0;
        scanf ("%ld%ld\n", &n, &x);
        long a[n];
        for (i = 0; i < n+1; i++)
                scanf ("%ld/n", &a[i]);
        for (i = 0; i < n; i++) 
                p = (p+a[i])*x;
        for (i = 0; i < n-1; i++)
                s = (s+a[i]*(n-i))*x;
        p = p+a[n]; s= s+a[n-1];
        printf ("%ld %ld", p, s);
        return 0;
}

