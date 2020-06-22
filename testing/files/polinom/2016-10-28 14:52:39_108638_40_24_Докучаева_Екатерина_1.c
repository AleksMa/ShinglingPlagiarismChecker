#include <stdio.h>

int main()
{
    int n;
    long long x;
    scanf("%d", &n);
    scanf("%lld", &x);
    long long a[n];
    int i;
    for (i = n; i > -1; i--)
    {
        scanf("%lld", &a[i]);
    }
    long long p = a[n];
    for (i = n-1; i > -1; i--)
    {
        p = p*x + a[i];
    }
    printf("%lld ", p);
    long long pp = a[n]*n;
    for (i = n-1; i > 0; i--)
    {
        pp = pp*x + a[i]*i;
    }
    printf("%lld ", pp);
    return 0;
}