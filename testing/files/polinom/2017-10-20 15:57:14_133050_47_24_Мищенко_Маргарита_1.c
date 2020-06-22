#include <stdio.h>
int main() {
        long n = 0, x = 0;
        scanf ("%ld\n%ld", &n, &x);
        long i = 0, a = 0, b = 0, k = 0, r = 0;
        long u = n;
        for (i = 0; i <= n; i++) {
                scanf ("%ld", &k);
                if (n == 1)
                r = k;
                a = a * x + k;
                if (i != n)
                b = b * x + k * (u--);
        }
        if (n == 0)
                printf("%ld 0", a);
        else printf("%ld %ld", a, b);
        return 0;
}