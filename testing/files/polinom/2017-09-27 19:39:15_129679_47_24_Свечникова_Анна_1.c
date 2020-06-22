
#include <stdio.h>

int main()
{
        long a, x, p, dp, n;
        p=0;
	dp=0;
	scanf( " %ld %ld", &n, &x);
	for (; n>0; n--) {
		scanf(" %ld", &a);
		p+=a;
		p*=x;
		dp+=(a*n);
		if (n>1) dp*=x;
		}
	scanf(" %ld", &a);
	p+=a;
	printf( " %ld %ld", p, dp);
	return 0;
}
