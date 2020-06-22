
#include <stdio.h>

main()
{
        long a, x, n, s, p, i, k;
	scanf ("%ld%ld%ld", &n, &x, &a);
	s = a;
	k = n;
	p = a*k;
	for (i = 1; i <= n; i++)
		{
			s = s*x;
			scanf ("%ld", &a);
			k = k - 1;
			s = s + a;
			if (k > 0) p = p*x, p = p + a*k;
			else p = p;
		}
	printf ("%ld %ld", s, p);
	return 0;
}