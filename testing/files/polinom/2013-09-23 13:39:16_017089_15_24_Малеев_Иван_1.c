#include <stdio.h>

int main(int argc, char *argv)
{
        long rez, x0, fx, n, a, prom;
        scanf("%lld\n", &n);
        scanf("%lld\n", &x0);
        scanf("%lld", &a);
        rez = a;
        fx = n * a;
        while (n > 0) {
                scanf("%lld", &a);
                rez = (rez * x0) + a; 
                fx = (fx * x0) + (a * (n - 1));
                ((x0 == 0) && (n > 1)) ? (prom = a) : (fx = fx);
                --n; 
                }
        (x0 == 0) ? (fx = prom) : (fx = fx / x0);
        printf("%lld %lld\n", rez, fx);
        return 0;
} 
 