#include<stdio.h>

int main()
{
    long long n,x0;
    long long  curr,next,prev;
    long long rez,deriv;
    scanf("%lld",&n);
    scanf("%lld",&x0);
    scanf("%lld",&curr);
    rez=curr;
    deriv=0;
    long long i;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&next);
        rez=rez*x0+next;
        deriv=deriv*x0+curr*(n-i+1);
        curr=next;
    }
    printf("%lld %lld",rez,deriv);
    return 0;
}
