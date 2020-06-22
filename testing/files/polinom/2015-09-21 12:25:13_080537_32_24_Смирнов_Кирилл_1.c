
#include <stdio.h>

int main(int argc, char **argv)
{
        int n, x0, i;
	scanf ("%d\n%d\n", &n, &x0);
	long long a[n+1];
	for (i = n; i >= 0; i--) scanf("%lld", &a[i]);
	long long p = a[n], pr = a[n] * n;
	for (i = n-1; i >= 0; i--) {
		p = p * x0 + a[i];
		if (i != 0)
			pr = pr * x0 + a[i] * i;
        } 
	printf("%lld " , p); 
	printf("%lld\n", pr);	  		
	return 0;
}
        