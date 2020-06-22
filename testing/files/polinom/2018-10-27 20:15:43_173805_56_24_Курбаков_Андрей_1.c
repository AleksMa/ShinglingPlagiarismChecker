#include <stdio.h>

int main()
{
        int n, i;
	long long x0, a, polynom = 0, derivative = 0;
	scanf("%i%lli", &n, &x0); 
	for (i = 0; i <= n; i++) {
		scanf("%lli", &a); 
		polynom = polynom * x0 + a; 
		if (i != n)
			derivative = derivative * x0 + (n - i) * a;  
	}
	printf("%lli %lli\n", polynom, derivative);
	return 0;
}

