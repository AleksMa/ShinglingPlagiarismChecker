#include <stdio.h>
int main()
{
    int i, n;
    scanf ("%d\n", &n);
    long x0, a0, a1, P0, P1;
    scanf ("%ld\n", &x0);
    scanf ("%ld\n", &a0);
    P0 = a0;
    P1 = n * a0;
    for (i = n; i >= 1; --i)
    {
        scanf ("%ld", &a1);
        P0 = P0 * x0 + a1;
        if (i > 1)
            P1 = P1 * x0 + a1 * (i - 1);
    }
    printf ("%ld %ld\n", P0, P1);
    return 0;
}
