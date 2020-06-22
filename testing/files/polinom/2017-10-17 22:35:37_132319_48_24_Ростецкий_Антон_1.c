#include <stdio.h>

int main()
{
    int i;
    long pol, der, x0, n;
        scanf("%ld", &n);
        scanf("%ld" , &x0);
    der = 0;
    pol = 0;
    long a[n + 1];
    for (i = 0; i < n + 1; i++)
    {
        scanf("%lu", &a[i]);
        pol = pol*x0 +a[i];
    }
    for (i = 0; i < n; i++)
    {
        der = der*x0 + a[i]*(n-i);
    }

    printf("%ld %ld", pol, der);
        return 0;
}


