#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long val = 0, pr = 0, n, x;
int main()
{
        scanf("%lld%lld", &n, &x);
	for (int i = n; i >= 0; i--)
	{
		long long tmp;
		scanf("%lld", &tmp);
//		cout << i << " " << val << " " << tmp << endl;
		if (i != 0)
		{
			pr = pr * x + tmp * i;
		}
		val = val * x + tmp;

		
		//printf("%lld ", val);
	}
	//cout << val;
	//std::cout << pr << std::endl;
	printf("%lld %lld", val, pr);
	return 0;
}

