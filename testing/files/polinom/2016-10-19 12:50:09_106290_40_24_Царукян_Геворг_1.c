
#include <stdio.h>

int main()
{
        int n = 0; 
        long int x = 0;
	scanf("%d", &n);
 	scanf("%li", &x);
	long int a[n+1];
	for (int i=n; i>=0; i--)
        {
            scanf("%li", &a[i]);
        }
        long long int  p1 = a[n]; 
        long long int  p2 = a[n] * n;
        for (int i=n - 1; i>=0; i--)
        {
            p1 = p1 * x + a[i];
            p2 = ((i > 0)? p2 * x + a[i] * i: p2);
        }
        printf("%lli\n", p1);
        printf("%lli\n", p2);
	return 0;
}