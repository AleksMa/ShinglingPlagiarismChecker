#include <stdio.h>

int main () {
    long n, x, a, p, Pn, i;
    p = 0;
    Pn = 0;
    scanf("%li\n", &n);
    scanf("%li\n", &x);
    i = n;
    while (i > 1) {
        scanf("%li", &a);
        p = p + a;
        p = p * x;
        Pn = Pn + (a * i);
        Pn = Pn * x;
        i--;
    }
    scanf("%li\a", &a);
    Pn = Pn + a;
    p = p + a;
    p = p * x;
    scanf("%li\a", &a);
    printf("%li ", p = p + a);
    printf("%li ", Pn);
    return 0;
}