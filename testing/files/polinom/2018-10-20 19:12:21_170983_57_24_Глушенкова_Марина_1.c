
#include <stdio.h>

int main()
{
        long n, x, a, p, pr;
        scanf("%ld %ld %ld", &n, &x, &a);
		p = a;
		pr = a*n;
		for (int i = 1; i <= n; ++i){
			p = p*x;
			if (i <= (n-1)) {
				pr = pr*x;
			}
			scanf("%ld", &a);
			p = p + a;
			if (i <= (n-1)) {
				pr = pr + a * (n-i);
			}
		}
		printf("%ld %ld\n", p, pr);
	return 0;
}