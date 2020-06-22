
#include <stdio.h>

int main()
{
        long int n, x, i, a;

        scanf("%ld %ld %ld", &n, &x, &a);
        long int polnm = a;
        long int pr = a * n;
        for(i = n-1; i > 0; i--)
        {
                scanf("%ld", &a);
                polnm = (polnm * x) + a;
                pr = (pr * x) + a * i;
        }

        scanf("%ld", &a);
        polnm = (polnm * x) + a;
        printf("%ld %ld", polnm, pr);

        return 0;
}
