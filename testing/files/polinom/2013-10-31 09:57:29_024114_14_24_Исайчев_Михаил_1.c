#include <stdio.h>

int main(int argc, char **argv) {
        long long n, x0, p, a, b;
	scanf("%lld%lld%lld", &n, &x0, &a);
	p = a*n;
	while (n>0) {
		scanf("%lld", &b);
		if (n>1) p = p*x0+b*(n-1);
		a = a*x0+b;
		--n;
	}
	printf("%lld %lld\n", a, p);
	return 0;
}
