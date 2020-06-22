#include <stdio.h>

int main(int argc, char **argv)
{
    long n, Xo, sum = 0, sumproz = 0, i;
    scanf("%ld\n%ld", &n, &Xo);
    long a[n+1];
    scanf("%ld", &a[0]);
    sum = a[0];
    sumproz = a[0] * n;
    for (i = 1; i < n+1; i++)
    {
        scanf("%ld", &a[i]);
        sum = sum * Xo + a[i];
    }
    for (i = 1; i < n; i++)  sumproz = sumproz * Xo + (n-i) * a[i] ;
    printf("%ld %ld", sum, sumproz);
        return 0;
}
