
#include <stdio.h>

int main()
{
        int n = 0, x = 0;
        scanf("%d%d", &n, &x);
        int i = 0;
        int a[n + 1];
        for (i = 0; i < (n + 1); i++) scanf("%d", &a[i]);
        long int p = 0, d = 0;        
        for (i = 0; i < (n + 1); i++) {
                p = p * x + a[i];
	        if (i != n) d = d * x + a[i] * (n - i);
	        else d = d + a[i] * (n - i);
        }
        printf("%ld %ld\n", p, d);
        return 0;
}
