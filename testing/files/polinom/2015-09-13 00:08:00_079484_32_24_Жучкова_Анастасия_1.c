#include <stdio.h>

long countPolynom(const int n, long arr[], const long x0);
void createDerivative(int* n, long arr[]);

int main()
{
        int n = 0, i = 0;
	scanf("%d\n", &n);

	long x0 = 0, arr[n + 1];
	scanf("%ld\n", &x0);

	for (i = 0; i < n + 1; i++)
		scanf("%ld", &arr[i]);

	printf("%ld ", countPolynom(n, arr, x0));
	createDerivative(&n, arr);
	printf("%ld\n", countPolynom(n, arr, x0));

	return 0;
}

long countPolynom(const int n, long arr[], const long x0)
{
	long polynom = arr[0];
	int i = 0;

	for (i = 1; i < n + 1; i++) {
		polynom = polynom*x0 + arr[i];
	}

    return polynom;
}

void createDerivative(int* n, long arr[])
{
	int i = 0;
	for (i = 0; i < *n + 1; i++)
		arr[i] = arr[i]*(*n - i);
	arr[*n] = 0;
    *n = *n - 1;
}