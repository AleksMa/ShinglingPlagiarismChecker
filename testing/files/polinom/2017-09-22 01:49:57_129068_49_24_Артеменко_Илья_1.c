#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int n;
    long x0;
    scanf("%d", &n);
    scanf("%ld", &x0);
    long * a = (long *)malloc(sizeof(long) * (n + 1));
    for (int i = 0; i < n + 1; i++) {
        scanf("%ld", &a[i]);
    }
    long t = a[0];
    for (int i = 0; i < n; i++) {
        t = t * x0 + a[i + 1];
    }
    printf("%ld ", t);
    for (int i = 0; i < n + 1; i++) {
        a[i] *= n - i;
    }
    n--;
    t = a[0];
    for (int i = 0; i < n; i++) {
        t = t * x0 + a[i + 1];
    }
    printf("%ld", t);
    free(a);
    return 0;
}