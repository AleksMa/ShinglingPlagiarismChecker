
#include <stdio.h>

int main()
{
    long n, x_0;
    scanf("%ld", &n);
    scanf("%ld", &x_0);

    long i, arr[n];
    for (i = 0; i < (n + 1); i++) scanf("%ld", &arr[i]);


    long polynomial = arr[0], derivative = 0;
    for(i = 1; i < (n + 1); i++)
    {
        polynomial = x_0 * polynomial + arr[i];
        derivative = x_0 * derivative + arr[i - 1] * (n - i + 1);
    }

    printf("%ld %ld", polynomial, derivative);

    return 0;

}
