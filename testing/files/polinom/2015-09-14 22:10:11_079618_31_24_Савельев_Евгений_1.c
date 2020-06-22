#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000

long long polynom(int n, int x, int *a) {
        long long res = a[0];
	
	int i = 1;
	while (i <= n) {
		res = (res * x) + a[i];
		i++;
	}
	
	return res;
}

int* get_der_array(int n, int *a) {
	int i = 0;
	while (i < n - 1) {  /* We don't need to change a[] with the power of 1 :) */
		a[i] *= n - i;
		i++;
	}

    return a;
}

int main(int argc, char *argv[]) {
	int n, x;
	int a[MAXN + 1];
	
	//---------------------input
	
	scanf("%d\n", &n);
	scanf("%d\n", &x);
	
	int i = 0;
	while(i <= n) {
		scanf("%d", &a[i]);
		i++;
	}
	
	//---------------------
	
	printf("%lld ", polynom(n, x, a));
	if (n > 0) printf("%lld", polynom(n - 1, x, get_der_array(n, a)));
	else printf("0");
	
	return 0;
}