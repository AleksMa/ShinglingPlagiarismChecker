#include <stdio.h>
#include <math.h>

int main(void) {

        long a; int n, i; long x; long p = 0; long pp = 0;

        scanf("%d\n%ld", &n, &x);

                for (i = 0; i <= n; ++i) {
                        scanf ("%ld", &a);
		        p = p * x + a;
		        if (i < n) {
			        pp = pp * x + a * (n - i);	
		        }
	        }
        printf ("%ld ", p);
        printf ("%ld\n", pp);

        return 0;
}