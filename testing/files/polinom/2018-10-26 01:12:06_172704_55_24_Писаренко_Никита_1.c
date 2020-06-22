
#include <stdio.h>

int main()
{
        long long int n, x,x1=1,z=0,p=0,a;
        scanf("%lld%lld",&n,&x);
        for(int i=0;i<n;i++)
        {
                x1*=x;
        }
        //printf("%lld ",x1);
        while(n>=0)
        {
                scanf("%lld",&a);
                if(n!=0)  z=z+a*x1;
                   	   else z=z+a;
        	if(n!=1 && x!=0) p=p+a*n*x1/x;
        	   else if(n==1)p=p+a;
        	n=n-1; 
        	//printf("%lld",n);
        	if(x!=0) x1/=x;
        }
        printf("%lld %lld",z,p);
	return 0;
}
