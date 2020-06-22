#include <stdio.h>

int main (){
        long i, p, pp = 0, n, x, a;
        scanf ("%ld\n%ld\n%ld", &n, &x, &a);
        p = a * x;
        for (i = n; i > 1; i--){
                pp = (pp + a * i) * x;
                scanf ("%ld", &a);
                p = (p + a) * x;
        }
        pp = pp + a;
        scanf ("%ld", &a);
        p = p + a;
        printf ("%ld %ld\n", p, pp);
        return 0;
}
