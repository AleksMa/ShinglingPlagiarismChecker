#include <stdio.h>

int main() {
        long n, a, pol = 0, x, der = 0;
	scanf("%ld %ld %ld", &n, &x, &a);
	pol = a * x;
        if (n != 1)  
                der = (a * n * x);
        else
                der =a;
	for (long i = (n - 1); i > 0; --i){
		scanf("%lu ", &a);
		pol = (pol + a) * x; 
                if (i != 1) 
                        der = ((der + a * i) * x);
                else
                        der = (der + a);
	}
	scanf("%ld ", &a);
	pol += a;
	printf("%ld %ld\n", pol, der);
	return 0;
}