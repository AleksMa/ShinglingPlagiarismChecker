#include <stdio.h>

int main() {
        
	int gr;
	long long x0;
	scanf("%d %lld", &gr, &x0);
	long long mas[gr + 1];
	for (int i = 0; i < gr + 1; i++) {
		scanf("%lld", &mas[i]);
	}
	long long res1 = mas[0], res2 = gr*mas[0];
	for (int i = 0; i < gr; i++) {
		res1 = res1*x0 + mas[i + 1]; 
	}
	for (int i = 0; i < gr - 1; i++) {
		res2 = res2*x0 + mas[i + 1]*(gr - i - 1);
	}
	printf("%lld %lld\n", res1, res2);
}
