#include <stdio.h>

int main(int argc, char **argv)
{
    int n, x0, i;
    long m, k;
    scanf("%d%d", &n, &x0);
    int a [n + 1];
    for (i = 0; i <= n; i++)
        scanf("%d", &a[i]);
    m = a[0]*x0;
    k = a[0]*x0 * n;
    for (i = 1; i < n; i++)
        m = (m + a[i]) * x0;
    m = m + a[n];
    for (i = 1; i < n - 1; i++)
        k = (k + (a[i] * (n - i)))*x0;
    k = k  + a[n - 1];
    if (x0 == 0) {
        m = a[n];
        k = a[n - 1];
    }
    else if (n == 1) {
        k = a[0];
    }
    printf("%ld %ld ", m, k);
    return 0;
}