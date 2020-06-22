
#include <stdio.h>

int main()
{
    int n,i;
    long x, y, p, a;
    y=0;
    p=0;
    scanf("%d", &n);
    scanf("%ld", &x);
    for(i=0;i<=n;i++)
    {
        scanf("%ld", &a);
        y=y*x+a;
        if(i<n)
        p=p*x+a*(n-i);
    }
    printf("%ld ", y);
    printf("%ld\n", p);
    return 0;
}
