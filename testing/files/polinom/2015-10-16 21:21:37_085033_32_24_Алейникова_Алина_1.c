#include <stdio.h>
#include <stdio.h>

int main()
{
        long long a, b, c, p;
        int i;
        scanf("%lld%lld%lld", &a, &b, &c);
        long long s = b * c;
	if (a == 1) {
		p = c;
		scanf("%lld", &c);
		s = s + c;
	}
	else {
		p = a * b * c;
		scanf("%lld", &c);
		p = p + c * (a - 1);
		s = s + c;
	}

	if (a >= 2) {
		for ( i = 2; i <= a; i++) {
			scanf("%lld", &c);
			s = s * b + c;
			if (i < a) p = p * b + c * (a - i);
		}
	}

	printf("%lld %lld", s, p);
	return 0;
}