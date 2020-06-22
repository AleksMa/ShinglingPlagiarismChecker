#include <stdio.h>
int main()
{
    int n, x0, i=1;
    long long P, Pp=0;
    scanf("%d", &n);
    int a[n];
    scanf("%d", &x0);
    scanf("%d", &a[0]);
    if(n==0)
    {
        printf("%d\n", a[0]);
        printf("%d\n", 0);
        exit(0);
    }
    P=a[0]*x0;
    Pp=a[0]*n;
    for(i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        if(i==n)
        {
            P=P+a[i];
            break;
        }
        P=(P+a[i])*x0;
        if(i==n-1)
        {
            Pp=Pp*x0+a[i];
            continue;
        }
        Pp=Pp*x0+a[i]*(n-i);

    }
    printf("%lld\n", P);
    printf("%lld\n", Pp);
    return 0;
}
