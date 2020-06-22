#include <stdio.h>

int main(int argc, char **argv) {
        long long n = 0, x0, i = 0, rezal, rezal2;
	long long a[100];
	scanf("%lld", &n);
	scanf("%lld", &x0);
	for (i = 0; i < n + 1; i++)
		scanf("%lld", &a[i]);
	rezal = a[0];
	for (i = 1; i < n + 1; i++){
		rezal *= x0;
		rezal += a[i];
	}
	rezal2 = a[0] * n;
	for (i = 1; i<n; i++){
		rezal2 *= x0;
		rezal2 += a[i] * (n - i);
	}
	printf("%lld %lld\n", rezal, rezal2);
}