#include <stdio.h>

int main (int argc, char **argv)

{
    int n;
    long x, a, pl, prpl;
    scanf ("%d", &n);
    scanf ("%ld", &x);
    scanf ("%ld", &a);
    pl=a;
    prpl=a*n;
    int i;
    for (i=n; i>0; i--) {
        scanf ("%ld", &a);
        pl=pl*x+a;
        if (i>1) prpl=prpl*x+a*(i-1);
    }
    printf ("%ld %ld", pl, prpl);
    return 0;
}