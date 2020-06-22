#include <stdio.h>

int main()
{
    int n,i;
    long long x,a,p,d;
    scanf("%d ", &n);
    scanf("%lld ", &x);
    scanf("%lld", &a);
    p=a;
    d=a*n;
    for ( i = n - 1; i > 0; i-- )
    {
        scanf("%lld", &a);
        p=p*x + a;
        d=d*x + a*i;
    }
    scanf("%lld", &a);
    p=p*x + a;
    printf("%lld ", p);
    printf("%lld", d);
    return 0;
}
