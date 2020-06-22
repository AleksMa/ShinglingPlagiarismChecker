#include <stdio.h>

int main() {
        long n, x, a;
        scanf("%ld %ld %ld", &n, &x, &a);
        long P = a, P_der = a * n;

 	while (n > 0) {
		scanf("%ld", &a);
		P *= x, P += a;
		if (n != 1) P_der *= x;
		P_der += a * (--n);
	}

	printf("%ld %ld", P, P_der);
	return 0;
}