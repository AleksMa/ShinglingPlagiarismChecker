#include <stdio.h>

int main(int argc, char **argv)
{
    long long n, x, p = 0, p1 = 0;
    scanf("%lld %lld", &n, &x);
    long long a[n+1];

    for (int i = 0; i <= n; i++)
        scanf("%lld", &a[i]);

    for (int i = 0; i <= n; i++)
    {
        p *= x;
        p += a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        p1 *= x;
        p1 += a[i-1]*(n-i+1);
    }

    printf("%lld %lld", p, p1);

    return 0;
}
