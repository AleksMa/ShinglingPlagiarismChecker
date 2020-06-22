#include <stdio.h>
int main()
{
        long n, x, p, p1;
	int i;
	scanf("%ld\n", &n);
	scanf("%ld\n", &x);
	long ndigit[n];
	for (i = 0; i <= n; ++i)
		scanf("%ld", &ndigit[i]);
	p = ndigit[0];
	for(i = 1; i <= n; ++i)
		p = p * x + ndigit[i];
	printf("%ld  ", p);
	for (i = 0; i <= n; ++i)
		ndigit[i] = ndigit[i] * (n - i);
	p1  = ndigit[0];
	for (i = 1; i <= n -1; ++i)
		p1 = p1 * x + ndigit[i];
	printf("%ld\n", p1);
	return 0;
}
