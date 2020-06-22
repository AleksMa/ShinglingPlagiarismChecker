#include <stdio.h>

int main ()

{
    long d, x;
    int i;

    scanf("%ld %ld", &d, &x);


    long a[d];
    for (i = 0; i < d + 1; i ++)
        {
        scanf("%ld", &a[i]);
        }

    long poly = a[0];
    long der = 0;

    for (i = 1; i <= d; i++)
    {
        poly = x * poly + a[i];
        der = x * der + a[i - 1] * (d - i + 1);
    }

    printf ("%ld %ld", poly, der);
}
