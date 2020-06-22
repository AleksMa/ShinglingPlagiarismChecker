
#include <stdio.h>

int main()
{
	int n;
        scanf("%d", &n);
	long x;
	scanf("%ld", &x);
	long long P = 0;
	long long Pp = 0;
	for (int i = n; i >= 0; --i)
	{
		long a;
		scanf("%ld", &a);
		P = P * x + a;
		if (i)
			Pp = Pp * x + a * i;
	}
	printf("%lld %lld\n", P, Pp);
	return 0;
}
