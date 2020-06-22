#include <stdio.h>
#include <malloc.h>
int main(int argc, char **argv)
{
      long long i, a, x, n, p, pr;
        scanf("%ld", &n);
	scanf("%ld", &x);
	scanf("%ld", &a);
	p = a;
	pr = n * a;
	for (i = 0; i < n; i++)
	{
		scanf("%ld", &a);
		p *= x;
		p += a;
	
		if (i != n-1) {
		    pr *= x;
		    pr += (n - i - 1) * a;
		}
	}
	
		printf("%ld ", p);
		printf("%ld", pr);

	return 0;
}