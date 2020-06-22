#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n = 0;
	int x0 = 0;
	int* a = NULL;
	int i = 0;
	long long  p0 = 0;
	long long  p1 = 0;

	scanf("%d", &n);
	scanf("%d", &x0);
        
        a = (int*)malloc(sizeof(int) * (n + 1));

	for (i = n; i >= 0; i--)
		scanf("%d", &a[i]);

	for (i = n; i >= 0; i--)
		p0 = p0 * x0 + a[i];

	for (i = n - 1; i >= 0; i--)
		p1 = p1 * x0 + (a[i + 1] * (i + 1));

	printf("%lld\n", p0);
	printf("%lld\n", p1);
	

	free(a);
	return 0;
}