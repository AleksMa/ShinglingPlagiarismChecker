#include <stdio.h>

int main()
{
    long n, x, res = 0, res1 = 0, inp0;
    scanf ("%ld %ld %ld", &n, &x, &inp0);
    res = inp0;
    res1 = res * n;
    long i = n;
    while (i > 0){
        scanf("%ld", &inp0);
        if (i > 1){
            res1 = res1 * x + inp0 * (i - 1);
        }
        res = res * x + inp0;
        i--;
    }
    printf("%ld %ld\n", res, res1);
        return 0;
}
