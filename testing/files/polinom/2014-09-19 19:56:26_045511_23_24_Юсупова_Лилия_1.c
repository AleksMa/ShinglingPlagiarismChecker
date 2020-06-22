#include <stdio.h>

int main(int argc , char ** argv)
{
        int i, n;
        long pol = 0, pr = 0, x, a;
        scanf("%d %ld", &n, &x);
        for(i = n; i > 0; i--) {
                scanf("%ld", &a);
                pol = (pol + a) * x;
                pr = pr * x + a * i;
        }
        scanf("%ld", &a);
        pol+= a;
        printf("%ld %ld", pol, pr);
        return 0;
} 