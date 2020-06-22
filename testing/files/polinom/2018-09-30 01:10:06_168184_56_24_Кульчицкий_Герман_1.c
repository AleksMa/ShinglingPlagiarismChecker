#include <stdio.h>

int main() {
        long n;
	scanf("%ld ", &n);
	long x;
	scanf("%ld ", &x);
	long derivative = 0;
	long function = 0;
	for (int i = n; i >= 0; --i){
		long a_i;
		scanf("%ld ", &a_i);
		function = (function * x) + a_i;
		if (i != 0)
			derivative = (derivative * x) + a_i * i;
	}
	printf("%ld %ld", function, derivative);
	return 0;
}
