
#include <stdio.h>

int main()
{
        long n, l, i=1, k, x, a, g, m;
        scanf ("%ld %ld %ld", &n, &x, &a);
        k=a;
        g=a*n;
        l=n;
        while (i<=n) { 
                scanf ("%ld", &a);
                k=k*x+a;
                if(i<n) {
                        l--;
                        g=g*x+a*l;
                }
                i++;
        } 
        printf ("%ld %ld\n", k, g);
	return 0;
}
 