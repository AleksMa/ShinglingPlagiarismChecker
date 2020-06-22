#include <stdio.h>
int main()
{
    long long n, x, n1, p, y;
    scanf ("%lld %lld" , &n , &x );
    long long a[n];
    n1 = n;
    for (long j = 0; j <= n; j ++) scanf ("%lld" , &a[j]);
    y = a[0];
    p = a[0] * n;
    for(long i=1; i<=n; i++) y = y * x + a[i];
    for(long l=1; l< n; l++)
    {
        p = p * x + a[l] * (n1-1);
        n1 = n1 - 1;
    }
    printf ("%lld %lld", y, p);
    return 0;
}