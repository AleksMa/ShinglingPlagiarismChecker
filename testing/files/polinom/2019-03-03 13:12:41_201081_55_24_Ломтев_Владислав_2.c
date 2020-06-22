#include <stdio.h>

int main(int argc, char *argv[]) {
        long long n = 0;
	long long x_0 = 0;
	scanf("%lld", &n);
	scanf("%lld", &x_0);
	long long *p = (long long*) calloc(n + 1, sizeof(long long));
	for (int i = 0; i < n + 1; i++){
		scanf("%lld", &p[i]);
	}
	long long func_res = p[0]; long long der_res = p[0] * n;
	for (int i = 0; i < n; i++) {
		func_res *= x_0; func_res += p[i+1];
	}
	for (int i = 0; i < n - 1; i++) {
		der_res *= x_0; der_res += p[i+1] * (n-i-1);
	}
	printf("%lld ", func_res); printf("%lld", der_res);
        free(p);
        return 0;
}