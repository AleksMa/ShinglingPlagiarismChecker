#include <stdio.h>
int main() {
        long long n, x0, a, Pn, Pn_;
	scanf("%lld\n%lld\n%lld", &n, &x0, &a);
	for (Pn = a, Pn_ = a * n, n--; n >= 0; n--) {
		scanf(" %lld", &a);
		Pn = Pn * x0 + a;
		if (n != 0) Pn_ = Pn_ * x0 + n * a;
	}
	printf("%lld %lld", Pn, Pn_);
	return 0;
}