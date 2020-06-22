#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{        
	long X0, n;
	long * a = (long *) malloc (100 * sizeof (long));
	long x = 0;
	long y = 0;
	scanf("%ld", &n);
	scanf("%ld", &X0);
	for (long i = n; i>=0; i--) {
		scanf("%ld", &a[i]);
	}
	for (long i = n; i>0; i--) {
		x = (x + a[i]) * X0;
	}
	x = x + a[0];
	for (long i = n; i>1; i--) {
		y = (y + a[i]*i) * X0;
	}
	y = y + a[1];
	printf("%ld %ld", x, y);
	free (a);
	return 0;
} 
