#include <stdio.h>

int main (int argc, char **argv)
{
long k, n, i, x;
scanf("%ld", &n);
scanf("%ld", &x);

long a[n+1];
for (i = 0; i <= n; i++) scanf("%ld", &a[i]);

long res = a[0];
for (i = 1; i <= n; i++) res = x * res + a[i];
printf("%ld\n", res);

long resp = a[0] * n;
k = n - 1;
for (i = 1; i < n; i++)
{
resp = x * resp + a[i] * k;
k--;
}
printf("%ld\n", resp);
return 0;
}