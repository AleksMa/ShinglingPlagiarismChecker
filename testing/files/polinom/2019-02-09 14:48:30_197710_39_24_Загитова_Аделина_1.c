
#include <stdio.h>

int main() {

    int n;
    long x0,a,P,Pn;
    scanf("%i\n", &n);
    scanf("%ld\n",&x0);
    P = 0;
    Pn = 0;
    while (n > 0){
        scanf("%ld",&a);
        P = x0 * (P + a);
        Pn = x0 * Pn + a * n;
        n = n - 1;
    }
        scanf("%ld",&a);
        P = P + a;
        printf("%ld %ld",P,Pn);

    return 0;
}