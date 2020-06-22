
#include <stdio.h>

int main()
{
        int n;
        long  x, i;
	scanf("%d", &n);
	scanf("%ld", &x);
		
	long a[n];
	for (i = 0; i <= n ; i ++) scanf("%ld", &a[i]);
	
	long long z=0;	
	for (i = 0; i < n ; i ++) 
		z=(z+a[i])*x;
	z=z+a[n];

    
    long long p=0;
    int c;
    c=n;
    for (i = 0; i < n-1 ; i ++) 
		{
		p=(p+a[i]*c)*x;
		--c;
		}		
	p=p+a[n-1];
	
	
	printf("%lli ", z);
	printf("%lli", p);
	return 0;
}
