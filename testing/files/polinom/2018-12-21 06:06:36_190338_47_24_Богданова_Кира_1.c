#include <stdio.h>
#include <math.h>

int main() {
    long x, n;
    scanf ("%ld\n", &n);
    scanf ("%ld\n", &x);
    long a;
    long result = 0;
    long long derivative = 0;
    for (int i = n; i >= 0; i--) {
        scanf("%ld", &a);
        result *= x;
        result += a;
        if (i != 0) {
            derivative = derivative * x + result;
        }
    }  
    if (n == 0)
        printf ("%ld 0", result);
    else printf("%ld %ld", result, derivative);
    return 0;
}