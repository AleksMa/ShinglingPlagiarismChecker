
#include <stdio.h>

int n;
long x, sum;
int a[0];

int main()

{
        scanf ("%d", &n);

	scanf ("%ld", &x);

	int i = 0;
	for (i = 0; i <= n; i++) scanf("%d", &a[i]); //Ввод коэффициентов



	sum = a[0];
	for (i = 1; i <= n; i++) sum = sum * x + a[i]; //Вычисление значения полинома

	printf ("%ld\n", sum);



	sum = 0;
	for (i = 0; i < n  ; i++) sum = sum * x + a[i] * (n - i); //Вычисление значения производной

	printf ("%ld\n", sum);

	return 0; 
}