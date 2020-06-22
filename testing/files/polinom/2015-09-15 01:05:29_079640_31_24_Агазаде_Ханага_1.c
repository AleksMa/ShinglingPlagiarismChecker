#include <stdio.h>

int main()
{
        int n = 0,i = 0;
    long f = 0, p = 0, x = 0;
        scanf("%i%ld", &n, &x);
	long a[n];
    for (i = 0;i <= n; ++i)
		scanf("%ld", &a[i]);
	f = a[0];
	for (i = 0; i < n; ++i)
		f= f * x + a[i+1];
	for (i = 0; i <= n; ++i)
		a[i]=(n-i)* a[i];
	p = a[0];
	for (i = 0; i < (n-1); ++i)
		p= p * x + a[i+1];
	printf("\n%ld\n%ld\n", f, p);	
	return 0;
}