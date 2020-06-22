#include <stdio.h>
#define N 333

main () {
    long Ai[N], x;
    int i, n, j;
    long res = 0, respr = 0;
    scanf("%d", &n);
    scanf("%ld", &x);
    for (i = 0; i <=  n; i++)
        scanf("%ld", &Ai[i]);
    for (i = 0; i <= n; i++)
    res = res*x + Ai[i];
    i = i - 2;
    for (j = 0; j <= i; j++) {
        respr = respr*x + n*Ai[j];
        n--;
    }
    printf ("%ld %ld\n", res, respr);
    return 0;
}
