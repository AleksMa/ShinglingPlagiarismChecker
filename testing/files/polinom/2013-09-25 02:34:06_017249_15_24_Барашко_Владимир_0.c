
#include <stdio.h>

int main()
{
        long n, x, i, a, a1, p, pd;
	scanf("%ld", &n);
	scanf("%ld", &x);
	scanf("%ld", &a1);
	p = a1;
	pd = a1 * n;
	for (i = 1; i <= n; i++) {
		scanf("%ld", &a);
		p = p * x + a;
		if (i <= (n - 1)) 
			pd = pd * x + a * (n - i);
	}
	printf("%ld %ld \n", p, pd);
	return 0;
}
	