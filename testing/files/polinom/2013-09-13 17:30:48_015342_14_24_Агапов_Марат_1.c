#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a, i, n, poly = 0, der = 0, b;
    scanf ("%lli", &n);
    scanf ("%lli", &a);
    n++;
    for (i=0;i<n;i++){
        scanf ("%lli", &b);
        der = der*a+poly;
        poly = poly*a+b;
    }
    printf ("%lli %lli", poly, der);
    return 0;
}
