
#include <stdio.h>

int main() {
        long n, x, i, a, p = 0, dp = 0;
	scanf("%ld%ld", &n, &x);
	for (i = n; i > 0; i--) {
		scanf("%ld", &a);
		p = (p + a) * x;
		if (i == 1) {
			dp += a*i;
		} else {
			dp = (dp + a*i) * x;
		}
	}
	scanf("%ld", &a);
	p += a;
	printf("%ld %ld", p, dp);
	return 0;
}
