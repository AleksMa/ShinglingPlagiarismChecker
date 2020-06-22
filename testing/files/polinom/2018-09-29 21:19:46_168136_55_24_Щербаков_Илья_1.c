
#include <stdio.h>

int main()
{
    long n, x0;
    scanf("%ld", &n);
    scanf("%ld", &x0);
    long a[n+1];
    int i;
    for (i=0;i<=n;i++) scanf("%ld", &a[i]);
    long x=a[0],d=0;
    for (i=1;i<=n;i++) {
        x=x*x0+a[i];
        d=d*x0+a[i-1]*(n-i+1);
    }
    printf("%ld %ld", x, d);
    return 0;
}
