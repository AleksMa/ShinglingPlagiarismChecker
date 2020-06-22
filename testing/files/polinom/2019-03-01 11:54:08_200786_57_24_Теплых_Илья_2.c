#include <stdio.h>

int main()
{
        long a, x, n, m, mn;
	scanf("%ld%ld%ld", &n, &x, &a);
	m = a;
	mn = a * n;
	for (n ; n > 0 ; n = n - 1)
	{
		scanf("%ld", &a);
		m = m * x + a;
		if (n == 1)
			x = 1;
		mn = mn * x + a * (n - 1);

	}
	printf("%ld %ld\n", m, mn);
	return 0;
}