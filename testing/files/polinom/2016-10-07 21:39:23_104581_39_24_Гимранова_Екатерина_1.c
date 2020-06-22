#include <stdio.h>

int main()
{
    long x0, i, n, a_n, a_new, a0, derivative, number;
    scanf("%ld\n", &n);
    scanf("%ld\n", &x0);
    scanf("%ld", &a_n);
    if (n > 1)
    {
        derivative = a_n*x0*(n--);
        number = a_n*x0;
        for (i = n; i > 1; i--, n--)
        {
            scanf ("%ld", &a_new);
            derivative = (derivative + a_new*n)*x0;
            number = (number + a_new)*x0;
        }
        scanf ("%ld", &a_new);
        number = (number + a_new)*x0;
        scanf("%ld", &a0);
        printf("%ld %ld\n", number + a0, derivative + a_new);
    }
    else {
        scanf("%ld", &a0);
        printf("%ld %ld\n", a_n*x0 + a0, a_n);
    }
    return 0;
}
