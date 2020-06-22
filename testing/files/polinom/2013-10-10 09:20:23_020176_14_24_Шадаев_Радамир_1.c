
#include <stdio.h>

int main()
{
        long int i;
        long int n;
        long int x0;
        long int pol=0, pr=0;
        long int ai;
        scanf("%ld", &n);
        scanf("%ld", &x0);
        for (i = 0; i < n; i++)
        {
                scanf("%ld", &ai);
                pol = (pol + ai) * x0;
                if (x0 != 0)        pr = (pr + ai*(n - i)) * x0;
                        else if (i == n - 1) pr = ai;
         }
        scanf("%ld", &ai);
        pol += ai; 
        printf("%ld\n", pol);
        if(x0!=0) printf("%ld", pr / x0);
        else printf("%ld\n", pr);
	return 0;
} 
 