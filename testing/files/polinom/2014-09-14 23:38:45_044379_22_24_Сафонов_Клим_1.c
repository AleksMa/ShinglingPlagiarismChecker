#include <stdio.h>
main()
{
        long int n = 0, x = 0, a = 0, i, res, res2, sum = 0, sum2 = 0;
	scanf("%ld", &n); 
	scanf("%ld", &x); 
	for (n; n>=0; n--) {
		scanf("%ld", &a);
		res = 1;
		res2 = 1;
		for (i=1; i<=n; i++) {
			res = res*x;
			if (i > 1) {
				res2 = res2*x;
			}
		}
		res = res*a;
		res2 = n*a*res2;
		sum = sum + res;
		sum2 = sum2 + res2;
	}
	printf("%ld %ld", sum, sum2);
	return 0;
} 
