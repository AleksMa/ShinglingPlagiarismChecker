#include <stdio.h>

int main()
{
    long i, n, x0, x, temp, polynomial, derivative = 0; 
    
    scanf("%ld %ld\n", &n, &x0);
    scanf("%ld", &polynomial);
    temp = polynomial;
    
    for (i = 1; i < (n + 1); i++) {
            scanf("%ld", &x);
            polynomial = x0 * polynomial + x;
            derivative = x0 * derivative + temp * (n - i + 1);
            temp = x;
    }
        
    printf("%ld %ld\n", polynomial, derivative);
    
    return 0;
}