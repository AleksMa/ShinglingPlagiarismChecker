#include <stdio.h>
#include <stdlib.h>

int main () {
    long i, n, a, x, res = 0, resp = 0;
    long *mas;
    scanf("%ld%ld", &n, &x);
    mas = (long*)malloc(sizeof(long)* (n + 1));
    for (i = 0; i <= n; i++)
    {
        scanf("%ld", &mas[i]);
    }
    for (i = 0; i < n; i++)
    {
        res = res * x + mas[i];
        resp = resp * x +  (n - i)*mas[i];
    }
    res = res * x + mas[n];
    printf("%ld %ld\n", res, resp);
    free(mas);
    return 0;
}
