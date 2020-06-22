#include <stdio.h>

int main(int argc, char **argv)
{
        long n, b, y, i, x;
	scanf("%ld", &n);
	long a[n + 1];
	scanf("%ld", &x);
	for (i = 0; i < (n + 1); i++) scanf("%ld", &a[i]);
	if (n == 0) printf("%ld %d\n", a[0], 0);
	else {
		if (n == 1) printf("%ld %ld\n", a[0] * x + a[1], a[0]);
		else {
			y = a[0] * x + a[1];
			for (i = 2; i < (n + 1); i++) y = y * x + a[i];
			a[0] = a[0] * n;
			a[1] = a[1] * (n - 1);
			b = a[0] * x + a[1];
			if (n != 2) 
				for (i = 2; i < n; i++) {
					a[i] = a[i] * (n - i);
					b = b * x + a[i];
				}
			printf("%ld %ld\n", y, b);
			
		}
	}
	return 0;
}						                                                                        	