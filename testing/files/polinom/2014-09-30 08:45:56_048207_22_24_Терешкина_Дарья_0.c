#include <stdio.h>

int main()
{
        int n,i;long x,a,a1;
        long polin,dpolin;
        scanf ("%d%ld%ld", &n, &x, &a);
        polin = a;
        dpolin = n*a;
        for (i = 1; i < n; i++)
                {
                        scanf("%ld", &a1);
                        polin=polin * x + a1;
                        dpolin=dpolin * x + (n - i) * a1;
                }
        scanf("%ld",&a1);
        polin = polin * x + a1;
        printf("%ld\n" ,polin);
        printf("%ld\n",dpolin);
        return 0;
}