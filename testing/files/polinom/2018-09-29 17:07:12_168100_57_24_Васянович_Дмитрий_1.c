#include <stdio.h>

int main(int argc, char **argv)
{
        long n, x0;
    scanf("%ld", &n);
	scanf("%ld", &x0);
	long arr[n];
	long i, x, xf;

	for (i = 0; i < (n + 1); i++) scanf("%ld", &arr[i]);
	
	if (n == 0) (x = arr[0]);
	else {
		if (n == 1) (x = arr[0] * x0 + arr[1]);
		else {
			x = (arr[0] * x0 + arr[1]);
			for (i = 2; i < (n + 1); i++) (x = x * x0 + arr[i]);
		}
	}
	
	if (n == 0) (xf = 0);
	else {
		if (n == 1) (xf = arr[0]);
		else {
			if (n == 2) (xf = 2 * x0 * arr[0] + arr[1]);
		    else {
				xf = (arr[0] * n * x0 + arr[1] * (n - 1));
				for (i = 2; i < n; i++) (xf = xf * x0 + arr[i] * (n - i));
			}
		}
	}
	
	printf("%ld ", x);
	printf("%ld\n", xf);
}