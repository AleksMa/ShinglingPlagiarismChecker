#pragma GCC optimize ("O3")

#include <stdio.h> 

int main()
{
    long long n = 0, x0 = 0, a = 0; /* n - степень; x0 - значение; a - очередной коэффициент */
    long long p = 0, p1 = 0; /* p - значение полинома; p1 - значение его производной */
    scanf("%ld", &n);
    scanf("%ld", &x0);
    scanf("%ld", &a);
    p = a * x0;
    if (n > 1) {
        p1 = a * n * x0;
    }
    else {
        p1 = a * n;
    }
    for (n = n - 1; n > 0; n--) {
        scanf("%ld", &a);
        p = (p + a)*x0;
        if (n > 1) {
                p1 = (p1 + a * n) * x0;
        }
        else {
            p1 = p1 + a * n;
        }
    }
    scanf("%ld", &a);
    printf("%ld %ld", p + a, p1);
    return 0;
}