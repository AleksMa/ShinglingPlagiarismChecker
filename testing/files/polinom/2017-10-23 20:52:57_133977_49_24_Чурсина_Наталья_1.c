#include <stdio.h>

int main()
{
    long long k, i,k0,poly=0,pr=0;
    long long l,n,x;
    scanf("%lld%lld",&n,&x );
    l=n;
    scanf("%lld",&poly);
    pr=poly*n;
    for (i=n; i>=1; i--)
    {
        scanf("%lld",&k);
        poly= poly*x +k;
        if (i>1)
        pr= pr*x + k*(i-1);
        
        
    }
    printf("%lld %lld\n",poly,pr);
    
    return 0;
}
