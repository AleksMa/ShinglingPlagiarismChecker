
#include <stdio.h>

int main()
{ 
        long n,x,q,q1,proizv,sum,sum1;
         int i;
        scanf("%ld",&n);
        scanf("%ld",&x);
        long a[n+1];
        for(i=0;i<n+1;i++)
            scanf("%ld",&a[i]);
        sum=a[n];
        sum1=0;
        q=x;
        q1=1;
        proizv=1;
        for(i=n-1;i>=0;i--)
            {
                sum+=a[i]*q;
                sum1+=a[i]*q1*proizv;
                q*=x;
                q1*=x;
                proizv++;

            }
            printf("%ld",sum);
            printf(" %ld",sum1);
	return 0;
}
