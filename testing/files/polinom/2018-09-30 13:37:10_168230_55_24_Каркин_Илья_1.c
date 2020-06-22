#include <stdio.h>
int main(){
    long long n,x,p=0,pp=0,a;
    scanf("%lld%lld",&n,&x);
    for (int i=n;i>=0;i--){
        scanf("%lld",&a);
        p+=a;
        if(i!=0){
            p*=x;
            pp+=a*i;
            if(i!=1)
                pp*=x;            
        }
    }
    printf("%lld %lld",p,pp);
    return 0;
}