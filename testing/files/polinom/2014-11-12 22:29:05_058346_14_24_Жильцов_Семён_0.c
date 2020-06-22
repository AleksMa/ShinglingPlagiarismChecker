#include <stdlib.h>
#include <stdio.h>
 
int main()
{

    long long n,x0,k;
    long long t=0,i,z=0;

    scanf("%lld",&n);
    scanf("%lld",&x0);
 
    for(i=0;i<=n;i++) {
        scanf("%lld",&k);
        t=x0*t+k;
        if(i!=n) {
          z=x0*z+k*(n-i);
        }
        else z=z;
    }
 
    printf("%lld ",t);
    printf("%lld",z);
 
return 0;
}
