#include<stdio.h>
int main ()
{
    int n, i, x ;
    long long int p, pr;
    scanf("%d%d",&n,&x);
    int a[n+1];
    for(i=0;i<n+1;i++)
        scanf("%d",&a[i]);
    p=a[0];
    pr=a[0]*n;

    for(i=n;i>0;i--)
    {
        p=p*x+a[n-i+1];
        if(i>1)
            pr=pr*x+a[n-i+1]*(i-1);
    }
    printf("%lld ",p);
    printf("%lld",pr);
    return 0;
}
