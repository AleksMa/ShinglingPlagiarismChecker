#include <stdio.h>
int main()
{
        long i=1;
        long a,x,n;
        scanf("%ld%ld%ld",&n,&x,&a);
        long k=a;
        long j=a*n;
        while (i<=n) {  
                if (i<n) j=j*x;
		k=k*x;
		scanf("%ld",&a);
		k=k+a;
		if (i<n) j=j+a*(n-i);
		i=i++;
	        }
        printf("%ld\n%ld",k,j);
        return 0;
}