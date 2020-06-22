#include <stdio.h>

int main() {
    long  i, n, poly = 0, x0, gradient = 0;
    scanf("%ld %ld", &n, &x0);
    long a[n+1];
    for (i=0; i <= n; i++) {
        scanf("%ld", &a[i]);
    }
    
    for(i= 0; i <= n; i++){
        poly *= x0; poly += a[i];
        gradient *= x0; gradient += a[i]*(n - i);
    } if (x0 == 0) gradient = a[n-1];
    else gradient /= x0;
    
    printf("%ld %ld\n", poly, gradient );
    return 0;
}