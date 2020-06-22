#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    long a[100], i, n, x;
    long s, p;
    scanf("%ld %ld", &n, &x);
    for(i = n; i >= 0; i--)
    scanf("%ld", &a[i]);
    s = a[n];
    p = n * a[n];
    for (i = n - 1; i >= 0; i--)
        s = s * x + a[i];
    for (i = n - 1; i >= 1; i--)
        p = p *x + i *a[i];
    printf("%ld %ld", s, p);
    return 0;
}
