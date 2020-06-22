#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    long x, n;
    scanf("%ld%ld", &n, &x);
    long a[n+1];
    for (i = 0; i < n+1; ++i) scanf("%ld",&a[i]);
    long long res = a[0], der = 0;
    for (i = 1; i < n+1; ++i) res =  res * x + a[i];
    for (i = 0; i < n; ++i) der = der * x + a[i] * (n - i);
    printf("%lld %lld\n", res, der);
    return 0;
}
