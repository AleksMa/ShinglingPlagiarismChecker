#include <stdio.h>

int main()
{
    long long pol = 0, der = 0;
    long long a, x, n, i;

    scanf ("%ld", &n);
    scanf ("%ld", &x);

    for (i = 0; i <= n; i++)
    {
       scanf ("%ld", &a);
       pol = pol * x + a;

       if (n != i)
           der = der * x + a * (n - i);
    }


    printf ("%ld %ld", pol, der);
    return 0;
}
