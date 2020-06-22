
#include <stdio.h>

int main()
{
        long n,x;
        scanf("%ld", &n);
	scanf("%ld", &x);
	long a[n+1];
	long i;
	for (i=n; i>=0; i--) scanf("%ld", &a[i]);

	long P=0,Psh=0;
	P=a[n];
	for (i=n-1; i>=0; i--) P=P*x+a[i];
	Psh=a[n]*n;
	for (i=n-1; i>=1; i--) Psh=Psh*x + a[i]*i;
	printf("%ld %ld", P, Psh);
	return 0;
}
