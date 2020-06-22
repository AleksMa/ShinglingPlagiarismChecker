#include<stdio.h>
int main()
{
        long  x0,res,a,res1,n;
        int i;
        scanf("%ld",&n);
        scanf("%ld",&x0);
        scanf("%ld",&a); 
        res=a;
        res1=a*n;
        for (i=1;i<=n;i++)
        {
                scanf("%ld",&a);
                res=res*x0+a;
        	if (i<n)
		        res1=res1*x0+a*(n-i);
        }
        printf("%ld %ld\n",res,res1);
        return 0;
}
