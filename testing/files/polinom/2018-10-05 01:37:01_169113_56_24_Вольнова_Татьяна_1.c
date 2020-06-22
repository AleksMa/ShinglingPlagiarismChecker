
#include <stdio.h>

int main()
{
         long n, x0, ai, pn = 0, i, pnsh = 0;
    scanf ("%ld", &n);
    scanf ("%ld", &x0);
    for (i = 0; i < n; i++) {
        scanf("%ld", &ai);
        pnsh = pnsh * x0 + ai * (n - i);
        pn = pn * x0 + ai;
    }
    scanf("%ld", &ai);
    pn = pn * x0 + ai;
    printf("%ld %ld", pn, pnsh);
    return 0;
}