#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    // printf("Hello polynom!\n");

    // printf("%ld\n", LONG_MAX);

    int n;

    long x;
    long pacc = 0;
    long pPrimeAcc = 0;

    scanf("%d", &n);
    scanf("%ld", &x);

    long a;

    while (scanf("%ld", &a) == 1) {
        pacc += a;
        if (n != 0)
            pacc *= x;


        if (n > 0) {
            pPrimeAcc += a * n;
            if (n > 1)
                pPrimeAcc *= x;
        }


        --n;
    }

    printf("%ld\n", pacc);
    printf("%ld\n", pPrimeAcc);



    return 0;
}
