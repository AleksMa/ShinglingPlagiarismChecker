#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

        long n = 0, x = 1, *args;

	scanf("%ld", &n);
	args = (long*)malloc(sizeof(long) * (n+1));
	if(!args) {
		printf("Allocation error\n");
		return -1;
	}
	
	scanf("%ld", &x);

	for (int i = 0; i <= n && scanf("%ld", (args+i)); i++);

	long poly = *args * x + *(args+1);
	long der = (*args * n * x) + *(args+1) * (n-1);
	if(n == 1 && x != 0) der /= x;

	for (int i = 1; i < n; i++) {
		if((i+1) < n) der = (der * x) + (*(args+(i+1))) * (n-(i+1));
		poly = (poly * x) + *(args+i+1);
	}

	free(args);
	printf("%ld %ld\n", poly, der);

	return 0;
}