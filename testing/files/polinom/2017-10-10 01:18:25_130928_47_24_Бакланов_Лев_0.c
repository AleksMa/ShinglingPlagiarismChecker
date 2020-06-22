#include <stdio.h>

int main (int argc, char **argv)
{
    long n, x, res, res1;
    res= 0;
    res1 = 0;
    scanf("%ld%ld", &n, &x);
    if (n == 0)
    {
        printf("%ld %ld", x, res1);
        return 0;
    }
    n++;
    long a[n];
    for (int i = 0; i < n ; i++)
        scanf("%ld", &a[i]);
    res = a[0];
    for (int i  = 1; i < n; i++)
        res = res * x + a[i];
    n--;
    res1 = a[0]*n;
    for (int i = 1; i < n; i++)
        res1 = res1*x + a[i]*(n - i);


    printf("%ld %ld", res, res1);
    return 0;
}