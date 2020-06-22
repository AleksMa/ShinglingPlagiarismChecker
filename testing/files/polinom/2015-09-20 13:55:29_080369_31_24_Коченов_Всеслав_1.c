#include <stdio.h>

int main()
{
        int n = 0, i;
        long int x0 = 0, h = 0, h2=0;
        scanf("%d%ld", &n, &x0);
        long int a[n];
        for (i=0; i<=n; i++) {
                scanf("%ld", &a[i]);
        }
        h=a[0];
        h2=a[0]*n;
        for (i=1; i<=n; i++) {
                h = h*x0 + a[i];
        }
        for (i=1; i<n; i++) {
                h2=h2*x0 + a[i]*(n-i);
        }
        printf ("%ld %ld", h, h2);
        return 0;
}
