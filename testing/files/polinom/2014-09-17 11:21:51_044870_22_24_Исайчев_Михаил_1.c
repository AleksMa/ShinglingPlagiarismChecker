#include <stdio.h>

int main (void) {
    long n, x0, p, a, b;
    scanf ("%ld %ld %ld", &n, &x0, &a);
    for (p = a*n; n>0; --n) {
        scanf ("%ld", &b);
        if (n>1) p = p*x0+b*(n-1);
        a = a*x0+b;
    }
    printf ("%ld %ld\n", a, p);
    return 0;
}