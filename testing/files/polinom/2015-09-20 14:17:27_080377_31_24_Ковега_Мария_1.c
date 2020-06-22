
#include <stdio.h>

int main(int argc, char **argv)
{
        int n, i, j;
        long x, a, sum, diff;
	scanf("%d%ld", &n, &x);
	scanf("%ld", &a);
	sum = a;
	diff = a * n;
	for(i = 0, j = n - 1; i < n; ++i, --j){
		scanf("%ld", &a);
		sum = sum * x + a;
		if (j > 0) {
			diff = diff * x + a * j;
		}
	}
	printf("%ld %ld\n", sum, diff);
	return 0;
}
