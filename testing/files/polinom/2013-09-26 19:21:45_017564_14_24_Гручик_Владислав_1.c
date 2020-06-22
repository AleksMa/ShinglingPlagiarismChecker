#include <stdio.h>

int main() {
    long long int i, n, x;
    scanf ("%lli", &n);
    scanf ("%lli", &x);
    long long int a[n];
    long long int p;
    for (i=n; i>=0; --i){
        scanf ("%lli", &a[i]);
    }
    p = a[n];
    for (i=n; i>0; --i){
        p = p*x + a[i-1];
    }
    printf ("%lli\n", p);
    long long int p1;
         p1 = a[n]*n;
         for (i=n; i>1; --i){
             p1 = p1*x + a[i-1]*(i-1);
             }
    printf ("%lli\n", p1);
    return 0;
}

