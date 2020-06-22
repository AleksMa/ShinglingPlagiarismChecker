#include <stdio.h>


int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int x0;
    scanf("%lld",&x0);
    long long int res=0;
    long long int resp=0;
    for (long long int i=n; i>=0; i--)
    {
        long long int a;
        scanf("%lld",&a);
        res*=x0;
        res+=a;
        if (i>0)
        {
            resp*=x0;
            resp+=(a*i);
        }
    }
    printf("%lld ",res);
    printf("%lld",resp);
    return 0;
}
