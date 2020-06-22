
#include <stdio.h>

int main()
{
        long n;
        scanf("%ld", &n);
	long x, a[n], i;
	scanf("%ld", &x);
	for (i=n; i>=0; i--) scanf("%ld", &a[i]);
	long p1, p2;
	p1=a[n];
	for (i=n; i>0; i--) p1=p1*x+a[i-1];
	p2=a[n]*n;
	for (i=n-1; i>0; i--) p2=p2*x+a[i]*i;
	printf("%ld %ld\n", p1, p2);
        return 0;
}
