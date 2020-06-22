#include <stdio.h>

int main()
{
        long x,a,i,n;
	scanf("%ld", &n);
	long b[n];
	long k;
	long c;
	scanf("%ld", &x);
	for (i=n; i >= 0; i--){
		scanf ("%ld", &b[i]);
	} 
	for (k=n-1, a=b[n]; k>=0; k--){
		a=a*x+b[k];	
	} 
	for (k=n-1, c=b[n]*n; k>0;k--){
		c=c*x+b[k]*k;
	}
	printf("%ld", a);
	printf(" %ld", c);
	return 0;
}
