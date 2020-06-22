#include <stdio.h>

int main() { 
        long Pno = 0;
	long Pn = 0;
	int n;
	long x;
	long a;
	scanf("%d %ld", &n, &x);
	while (n != -1) {
		scanf("%ld", &a);
		Pn = Pn * x + a;
		if (n != 0) Pno = Pno * x + a * n;
	        --n;
	}
	printf("%ld %ld", Pn, Pno);
	return 0;
}