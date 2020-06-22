
#include <stdio.h>

int main(int argc, char **argv)
{        int n;
	long x, y, yy, a;
	scanf("%d%ld%ld", &n, &x, &a);
	yy = a;
	y = a;
	while (n > 0) {
		scanf("%ld", &a);
		y = (y * x) + a;
		if (n > 1) yy = (yy * x) + y;
		--n;
	}
	printf("%ld\n%ld\n", y, yy);
	return 0;
}
