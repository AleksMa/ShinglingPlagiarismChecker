#include <stdio.h>

int main(int argc, char ** argv) {
    long long x=0, y, t, h, pol, proiz, n;
    scanf("%li %li", &x, &y);
    scanf("%li", &h);
    pol = h;
    proiz = h * x;
    n = x - 1;
    for (int i = 0; i < x; i++) {
        scanf("%li", &t);
        pol = pol * y + t;
        if (i != x-1) proiz = proiz * y + (t * n);
        n = n - 1;
    }

    printf("%li %li", pol, proiz);
    return 0;
}