#include <stdio.h>

int main()
{
    long n, x, p, der, a;
    int i;
    scanf("%ld %ld", &n, &x);
    scanf("%ld", &p);
    der = p * n;
    for (i = 1; i <= n; ++i)
    {
        scanf("%ld", &a);
        p = p * x + a;
        if (i != n)
            der = der * x + a * (n - i);
    }
    printf("%ld\n%ld\n", p, der);
    return 0;
}
