#include <stdio.h>
#include <math.h>
int main(int argc, char **argv)

{
        long n,x,sum,proizv_sum,first,coef,i;
	scanf("%lld%lld%lld", &n, &x, &first);
	sum = first;
	proizv_sum = 0;
	if (n) proizv_sum = first*n;
    for (i = n; i; i--)
    {
		scanf("%lld", &coef);
		sum = sum * x + coef;
		if (i>1) proizv_sum = proizv_sum*x + (i-1)*coef;
    }
	printf("%lld %lld\n", sum, proizv_sum);
	return 0;
}