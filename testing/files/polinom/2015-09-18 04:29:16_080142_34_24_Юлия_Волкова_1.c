#include <stdio.h>
#include <stdlib.h>

long* newcoef(long* arr, int n, int i) {

    arr[ n - i ] *= i;

    if (i == 0) { return arr; }
    else        { return newcoef( arr, n, --i ); }
}

long polynom( long* arr, int n, int i, int value, long sum ) {

    if (n == 0) { return sum; }
    
    sum *= value;
    sum += arr[i];

    if (i == n) { return sum; }
    else        { return polynom( arr, n, ++i, value, sum ); }
}

int main(){
    int n, value, i; 
    long *poly, p, dp;

    scanf( "%i%i", &n, &value );
    poly = malloc( ( n + 1) * sizeof(long) );

    for (i = 0; i <= n; i++) {
        scanf( "%li", &poly[i] );
    }

    p    = polynom( poly, n, 1, value, poly[0] );
    poly = newcoef( poly, n, n );
    dp   = polynom( poly, --n, 1, value, poly[0] );
    
    printf( "%li %li", p, dp );
    free( poly );
    return 0;
}