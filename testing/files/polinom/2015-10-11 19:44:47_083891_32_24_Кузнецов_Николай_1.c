#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char **argv)

{
    long n, x0;
    scanf("%ld\n %ld", &n, &x0);
    n++;
    long* a = (long*)malloc(n * sizeof(long));
    int i;
    for (i = 0; i < n; i++)
        scanf("%ld", a + i);
    long pol = a[0], pol1 = a[0] * (n - 1);
    for (i = 1; i < n; i++)
        pol = pol * x0 + a[i];
    n--;
    for (i = 1; i < n; i++)
        pol1 = pol1 * x0 + a[i] * (n - i);
    printf("%ld %ld\n", pol, pol1);
    free(a);
    return 0;
}