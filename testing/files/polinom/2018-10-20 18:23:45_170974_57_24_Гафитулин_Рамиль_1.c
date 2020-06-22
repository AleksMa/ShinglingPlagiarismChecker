
#include <stdio.h>

int main()
{
    long n, x;
    long long g,r;
    scanf("%ld\n", &n);
    scanf("%ld\n", &x);

    long koff[n];
    for (int i = 0;i<=n;i++)  scanf("%ld", &koff[i]);
    r = koff[0];

    for (int i = 1; i<=n; i++)
    {
        r = r*x + koff[i];
    }
    printf("%lld\n", r);
    g = koff[0]*n;
    for (int i = 1; i<n; i++)
    {
        g = g*x + koff[i]*(n-i);

    }
     printf("%lld\n", g);
}
