#include <stdio.h>

int main()
{
    long long i=0, n=0, x=0, p=0, pp=0;
    scanf("%lld", &n);
    scanf("%lld", &x);
    long long a[n+1];
    for (i=n;i>=0;--i)
    {
        scanf("%lld", &a[i]);
        if (i==n) p=a[i];
        if (i<n) p=p*x+a[i];
        if (i==n) pp=i*a[i];
        if ((i<n) && (i>0)) pp=pp*x+i*a[i];
    }
    printf("%lld %lld", p, pp);
    return 0;
}