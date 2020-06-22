# include <stdio.h>

int main (int argc , char **argv )
{
    long n = 0, x = 0;
    scanf("%ld%ld", &n, &x);
    long A[n + 1];
    long i;
    for(i = 0; i <= n; ++i)
    {
        scanf("%ld", &A[i]);
    }
    long poly = A[0];
    for(i = 0; i < n; ++i)
    {
        poly = poly * x + A[i + 1];
    }
    long poly1 = A[0] * n;
    for(i = 0; i < n - 1; ++i)
    {
        poly1 = poly1 * x + A[i + 1] * (n - i - 1);
    }
    printf("%ld %ld", poly, poly1);
    return 0;
}