#include <stdio.h>

int main()
{
    long n, x0; 
    scanf("%ld %ld\n", &n, &x0);
    
    long i, arr[n + 1];
    for (i = 0; i < (n + 1); i++) scanf("%ld", &arr[i]);
    
    long polynomial = arr[0], derivative = 0;
    for (i = 1; i < (n + 1); i++) {
            polynomial = x0 * polynomial + arr[i];
            derivative = x0 * derivative + arr[i - 1] * (n - i + 1);
        }
    printf("%ld %ld\n", polynomial, derivative);
    
    return 0;
}