
#include "stdio.h"
#include "math.h"

int main(int argc, char const *argv[]) {
        long  n, x0, polim = 0, proiz = 0;
	scanf("%ld %ld", &n, &x0);
	long a[n + 1];

	for (long i = 0; i <= n; i++){
		scanf("%ld", &a[i]);
	}

	for (long i = 0; i <= n; i++){

		polim = polim*x0 + a[i];
	}
	for (long i = 1; i <= n; i++){
		proiz = x0*proiz + a[i - 1] * (n - i + 1);
	}
	printf("%ld %ld", polim, proiz);
	return 0;
}
