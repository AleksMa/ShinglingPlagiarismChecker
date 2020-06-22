
#include <stdio.h>

int main()
{
long a, b;
scanf("%ld", &a);
scanf("%ld", &b);

long i, arr[a];
for (i = 0; i < (a + 1); i++) 
scanf("%ld", &arr[i]);

long poly = arr[0], drv = 0;
for(i = 1; i < (a + 1); i++)
{
poly= b * poly+ arr[i];
drv = b *drv + arr[i - 1] * (a - i + 1);
}

printf("%ld %ld", poly, drv);

	return 0;
}
