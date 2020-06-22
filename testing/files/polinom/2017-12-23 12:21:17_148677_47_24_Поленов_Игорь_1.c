#include <stdio.h>
#include <stdlib.h>

long long polynom(long long x, long long n, long long* a)
{
    if (n == 0)
    {
        return a[0];
    }

    long long p = a[n]*x+a[n-1];
    for (int i = n - 2; i >= 0; --i)
    {
        p = p * x + a[i];
    }

    return p;
}


int main()
{
    long long n=0, x=0;
    scanf ("%lld %lld", &n, &x);
    long long* a =  malloc((n + 1) * sizeof(long long));

    int i = n;
    for (i = n; i >= 0; --i)
    {

        scanf ("%lld", &a[i]);
    }

    printf ("\n%lld", polynom(x, n, a));

    --n;
    for (i = 0; i <= n; ++i)
    {
        a[i] = a[i + 1] * (i + 1);

    }

    printf (" %lld", polynom(x, n, a));
    free(a);
    return 0;
}