#include <stdio.h>
#include <math.h>

int main(void)
{
    long n, i, x, sum, sump;
    scanf("%ld%ld", &n, &x);
    sump = 0;
    long a[n];
    scanf("%ld", &a[0]);
    sum = a[0];
    sump = a[0] * n;
    for (i=1; i<=n; i++)
    {
        scanf("%ld", &a[i]);
        sum *= x;
        sum += a[i];
        if (i < n)
        {
            sump *= x;
            sump += a[i] * (n - i);
        }
    }
    printf("%ld\n", sum);
    printf("%ld\n", sump);
    return 0;
}