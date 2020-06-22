#include <stdio.h>

int main(int argc, char **argv)
{
        long res1, res2, i, n, x,a;
	scanf("%ld%ld", &n, &x);
	for (i = 0; i <= n; i++) {
		scanf("%ld", &a);
		if (i) {
			res1 = res1 * x + a;
			if (i != n) res2 = res2 * x + a * (n - i);
		} else {
			res1 = a;
			res2 = a * n;
		}
	}
	printf("%ld %ld\n", res1, res2);
	return 0;
}