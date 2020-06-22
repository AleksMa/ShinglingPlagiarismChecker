#include <stdio.h>

int main(void)
{   
    int d, n;
    long int polynom = 0, derivative = 0, x, a;
    scanf("%d%ld", &n, &x);
    for(d = n; d > 0; d--)
    {
        scanf("%ld", &a);
        polynom = (polynom + a) * x;
        derivative = (derivative * x) + (a * d);
    }
    scanf("%ld", &a);
    polynom += a;
    printf("%ld\n%ld", polynom, derivative);
    return 0;
}