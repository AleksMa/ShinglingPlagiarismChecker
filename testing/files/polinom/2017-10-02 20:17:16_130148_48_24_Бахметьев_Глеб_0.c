
#include <stdio.h>
#define max 10000

int main()
{
    int n, i;
    long x, sum;
    int a[max];

    scanf ("%d", &n);

    scanf ("%ld", &x);

     for (i = 0; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    sum = a[0]; // Вычисление значение полинома
     for (i = 1; i <= n; i++)
    {
        sum = sum * x + a[i];
    }

    printf ("%ld\n", sum);



    sum = 0; // Вычисление значения производной
    for (i = 0; i < n  ; i++)
    {
        sum = sum * x + a[i] * (n - i) ;
    }

    printf ("%ld\n", sum);

    return 0;
}