#include <stdio.h>

int main() {
        int n, x0, i;
	long sum = 0, sum2 = 0;
	scanf("%d%d", &n, &x0);
	if (n == 0)
		printf("1\n");
	else {

		int a[n + 10], k = n;
		for (i = 0; i <= n; i++)
			scanf("%d", &a[i]);
		sum = a[0] * x0;
		for (i = 1; i < k; i++)
			sum = (sum + a[i]) * x0;
		sum += a[k];
		for (i = 0; i <= k; i++) {
			a[i] = a[i] * n;
			n -= 1;
		}
		sum2 = a[0] * x0;
		for (i = 1; i < (k - 1); i++)
			sum2 = (sum2 + a[i]) * x0;
		if (k > 1)
			sum2 += a[k - 1];
		else
			sum2 = a[0];
		printf("%ld %ld\n", sum, sum2);
	}
}