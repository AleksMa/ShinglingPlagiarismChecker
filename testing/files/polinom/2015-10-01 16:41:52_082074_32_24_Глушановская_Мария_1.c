#include <stdio.h>

int main() {
        long n, x0;
	scanf("%ld%ld", &n, &x0);

        long a[n + 1];
        for (long i = n; i >= 0; i--) {
        	scanf("%ld", &a[i]);
        }
	
	long P = 0;
	for (long i = n; i >= 0; i--) {
		P = P + a[i];
		if (i > 0) {
			P *= x0;
		}
        }

	long P1 = 0;
	for (long i = n; i >= 1; i--) {
		P1 = P1 + a[i] * i;
		if (i > 1) {
			P1 *= x0;
		}
	}
	
	
	printf("%ld %ld\n", P, P1);
   return 0;
}