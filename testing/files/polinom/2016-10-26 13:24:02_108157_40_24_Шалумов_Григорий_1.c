
#include <stdio.h>

int main()
{
    int n,i;
    long x,p,dp,a;
    p=0;
    dp=0;
    scanf("%d", &n);
    scanf("%ld", &x);
    for(i=0;i<n;++i)
    {
        scanf("%ld", &a);
        p=p*x+a;
        dp=dp*x+a*(n-i);
    }
    scanf("%ld", &a);
    p=p*x+a;
    printf("%ld ", p);
    printf("%ld\n", dp);
    return 0;
}
