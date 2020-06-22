#include<stdio.h>
int main()
{
        long n, x0, sum = 0, b = 0, a;
	scanf("%ld%ld", &n, &x0);
	for (int i = 0; i <= n; i++) {
		scanf("%ld", &a);
		b = b*x0 + sum;
		sum = sum*x0 + a;
	}
	printf("%ld %ld", sum, b);
	return 0;
}



