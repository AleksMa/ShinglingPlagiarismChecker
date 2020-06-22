#include <stdio.h>

int main()
{
    int n = 0;
    long x0 = 0;
    long p = 0;
    long d = 0;
    int i = 0;
    
    scanf("%d", &n);
    scanf("%ld", &x0);
    long a[n];
    for (i = 0; i < (n + 1); i++) {
        scanf("%ld", &a[n - i]);
    }
 
    p = a[n];
    for (i = 0; i < n; i++) {
        p = p * x0 + a[n - i -1];
    }
    printf("%ld ", p);

    d = n * a[n];
    for (i=0; i < n - 1; i++) {
        d = d * x0 + (n - i -1) *  (a[n - i - 1]);
    }
    printf("%ld", d);
    return 0;
}
