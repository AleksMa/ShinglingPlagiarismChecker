        
#include <stdio.h>

int main()
{
        int n;
	int x;
	int i;
	int a;
	scanf ("%d", &n);
	scanf ("%d", &x);
	scanf ("%d", &a);
	long long int zna4 = a; // zna4 - èòîãîâîå çíà÷åíèå ïîëèíîìà
	long long int proizv = a * n; // proizv - èòîãîâîå çíà÷åíèå ïðîèçâîäíîé ïîëèíîìà
	for (i = n; i > 0; i--) {
		scanf ("%d", &a);
		zna4 = zna4 * x + a;
		if (i != 1)
			proizv = proizv * x + a * (i - 1);
	}
	printf ("%lld %lld", zna4, proizv);	
	return 0;
}
