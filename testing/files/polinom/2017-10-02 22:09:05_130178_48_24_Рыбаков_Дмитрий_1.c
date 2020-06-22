
#include <stdio.h>

int main()
{
    long n, x0, i, s, p, g;
    scanf("%ld%ld", &n, &x0);
    long a[n];
    for (i = n; i >= 0; i--)
        scanf("%ld", &a[i]);
    s = 0;
    p = 0;
    g = x0;
    if (n > 1) g = 1;
    for (i = n-2, s = (a[n]*x0 + a[n-1]), p = (a[n]*x0*n/g + a[n-1]*(n-1)); i >= 0; i--)
    {
        s = s*x0 + a[i];
        if (i>0)
            p = p*x0 + a[i]*i;
    }

    printf("%ld %ld", s, p);
    return 0;
}
