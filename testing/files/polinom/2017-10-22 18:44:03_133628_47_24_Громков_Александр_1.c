#include <stdio.h>

int main(int argc, char **argv)
{
    int n,i;
    scanf("%d\n", &n);
    int x;
    scanf("%d\n", &x);

    int a[n];
    for (i = 0; i < n+1; i++) scanf("%d", &a[i]);

    long long promesh = a[0];
    for (i = 1; i <= n; i++) promesh = promesh * x + a[i];

    long long proizvodnaya = a[0] * n;
    for (i = 1; i <= (n-1); i++) proizvodnaya = proizvodnaya * x + a[i] * (n-i);

    printf("%ld %ld", promesh, proizvodnaya);

return 0;
} 