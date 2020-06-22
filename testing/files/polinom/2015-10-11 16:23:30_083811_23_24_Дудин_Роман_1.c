#include <stdio.h>

int main() {
        int n, i;
	long x, p, polynom = 0, polynom_derivative = 0;
	scanf("%i%li", &n, &x);
	for (i = 0; i <= n; i++) {
		scanf("%li", &p);
		polynom = polynom * x + p;
		if (i != n)
			polynom_derivative = polynom_derivative * x + (n - i) * p;
	}
	printf("%li\n%li\n", polynom, polynom_derivative);
	return 0;
}