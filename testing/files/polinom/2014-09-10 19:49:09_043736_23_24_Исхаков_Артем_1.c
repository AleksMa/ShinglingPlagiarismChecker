#include <stdio.h>

int main(void) {
        int i, n;
	long int poly1 = 0, poly2 = 0, x, a;
	scanf("%d%ld", &n, &x);
	for(i = n; i > 0; i--){
		scanf("%ld", &a);
		poly1 = (poly1 + a) * x;
		poly2 = poly2 * x + a * i;
	}
	scanf("%ld", &a);
	poly1 += a;
	printf("%ld\n%ld", poly1, poly2);
	return 0;
}
