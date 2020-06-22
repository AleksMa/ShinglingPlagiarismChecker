
#include <stdio.h>

int main(int argc, const char * argv[]) {
    const int m = 50;
    
    long long f, ff=0, d, dd=0, x;
    int i,n;
    long long fact[m];
    
    scanf("%d",&n);
    scanf("%lld",&x);
    
    for (i=0; i<=n; i++) {
        scanf("%lld", &fact[i]);
    }
    
    f=fact[0];
    d=fact[0]*(n+1);
     
    for (i=1; i<=n; i++) {
        ff=fact[i]+f*x;
        if ((x!=0)) {
            dd=(n+1-i)*fact[i]+d*x;
        }else{
            dd=fact[i-1];
        }
        f=ff;
        d=dd;
    }
    if (x!=0) {
        dd=(dd-ff)/x;
    }
    
    printf("%lld ",ff);
    printf("%lld",dd);
    
    return 0;
}