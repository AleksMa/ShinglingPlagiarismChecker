#include<stdio.h>
#include<math.h>
int main(){
        int long long n, x0,sum=0,sumprime=0,a;
        scanf("%lld%lld", &n,&x0);
        if(n==0){
                scanf("%lld",&a);
                printf("%lld ",a);
                printf("%lld",(long long int)0);
        }
        else if(n==1){
                scanf("%lld",&a);
                sum=a*x0;
                sumprime=a;
                scanf("%lld",&a);
                printf("%lld ",sum+a);
                printf("%lld",sumprime);
        }
        else{
                for(int i=0;i<n-1;i++){
                        scanf("%lld",&a);
                        sum=(sum+a)*x0;
                        sumprime=(sumprime+(n-i)*a)*x0;
                }
                scanf("%lld",&a);
                sum=(sum+a)*x0;
                sumprime=sumprime+a;
                scanf("%lld",&a);
                printf("%lld ",sum+a);
                printf("%lld",sumprime);
                return 0;
        }
}

