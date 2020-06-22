#include<stdio.h>
int main() {
        long long int x, n, res_polinom = 0, res_proiz = 0, p;
	scanf("%lld", &n);
	scanf("%lld", &x);
	for (int i = 0; i <= n; i++) {
		scanf("%lld", &p);
		res_polinom += p;
		res_polinom = (i != n) ? res_polinom*x : res_polinom;
		p *= n - i;
		res_proiz += p;
		res_proiz = (i < n - 1) ? res_proiz*x : res_proiz;
	}
	printf("%lld %lld", res_polinom, res_proiz);
	return 0;
}  