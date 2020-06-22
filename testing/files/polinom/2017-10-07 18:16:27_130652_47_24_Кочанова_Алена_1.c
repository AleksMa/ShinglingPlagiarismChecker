
#include <stdio.h>

int main()
{
    long x0;
    int i, n;
    scanf("%ld\n%ld\n", &n, &x0);
    long a[n], y, z, p, p1;
    y = 1;
    z = 1;
    p = 0;
    p1 = 0;
    for (i = n; i >= 0; i--)
        scanf("%ld", &a[i]);
    for (i = 0; i <= n; i++) {
        p = p + a[i] * y;
        y = y * x0;
    }
    for (i = 1; i <= n; i++) {
        p1 = p1 + a[i] * i * z;
        z = z * x0;
    }
    printf("%ld %ld", p, p1);
    return 0;
}