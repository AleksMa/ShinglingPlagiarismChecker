#include <stdio.h>

int main() {
    int n = 0, i = 0;
    scanf("%ld", &n);
    long x, a[n + 1];
    scanf("%ld", &x);
    for (i = 0; i<=n; ++i){
        scanf("%ld", &a[i]);
    }
    /*printf("point\n");
    printf("%d %ld\n", n, x);
    for (i = 0; i<=n; ++i){
        printf("%d - %ld\n", i, a[i]);
    }*/
    long poly(int n, long *a, long x) {
        if (n>0) {
            return a[n] + x*poly(n - 1,a,x);
        } else {
            return a[n];
        }
    }
    printf("%ld ", poly(n, a, x));
    for (i = 0; i<n; i++) {
        a[i] *= n - i;
    }
    printf("%ld\n", poly(n-1, a, x));

    return 0;
}