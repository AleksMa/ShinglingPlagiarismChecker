#include<stdio.h>
int main() {
    long x0, n, a, result1 = 0, result2 = 0;
    int i = 0;
    scanf("%ld", &n);
    scanf("%ld", &x0);
    while (i <= n) {
	scanf("%ld", &a);
	result1 += a;
	if (i != n)
		result1 = result1*x0;
	result2 += a*(n - i);
	if (i < n - 1)
		result2 = result2*x0;
	i++;
        }
    printf("%ld %ld", result1, result2);
    return 0;
}  