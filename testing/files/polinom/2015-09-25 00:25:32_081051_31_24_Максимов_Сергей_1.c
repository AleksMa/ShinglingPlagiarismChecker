
#include <stdio.h>

int main()
{
        long x, n, p, pp;
        scanf("%ld %ld", &n, &x);
	long k[n+1];
	int i;
	for (i = 0; i < n + 1; i++)
		scanf("%ld", &k[i]);
	p = k[0];
	for (i = 0; i < n; i++) {
		p *= x ;
		p += k[i+1];
	}
	pp = k[0] * (n);
	for (i = 1; i < n; i++) {
	        pp *= x;
	        pp += k[i] * (n - i);
	}
	printf("%ld %ld", p, pp);
        return 0;
}