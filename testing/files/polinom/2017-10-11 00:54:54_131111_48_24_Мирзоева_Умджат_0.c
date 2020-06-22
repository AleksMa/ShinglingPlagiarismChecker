#include <stdio.h>
#include <stdlib.h>

int main()
{
    long n, x;
    scanf ("%ld%ld", &n, &x);
    long i, d;
    long a[n];
    long result = 0;
    for (i = 0; i <= n; i++) {
        scanf ("%ld", &(a[i]));
        result = result * x + a[i];
    }

    printf ("%ld\n", result);
    if (n==0)
    {
        printf ("0");
        return 0;
    }
        if (n==1)
    {
            printf ("%d", a[0]);
            return 0;
    }
    long proiz = 0;
    long h=n;
    for (i = 0; i < h; i++)
    proiz = proiz * x + a[i] * (n--);
    printf ("%ld", proiz);
    return 0;
}