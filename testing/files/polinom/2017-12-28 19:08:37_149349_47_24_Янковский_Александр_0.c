#include <stdio.h>

int main()
{       long long polynom,proizvodnaya;
        long j, m, x;
        scanf ("%ld", &m);
        scanf ("%ld", &x);
        long mass[m];
        for (j = 0; j <= m; j++)
                scanf ("%ld", &mass[j]);
        polynom = mass[0] * x + mass[1];
        for (j = 2; j <= m ; j++)
                polynom=polynom * x + mass[j];
        if (m == 1) proizvodnaya = mass[0];
                else {
                        proizvodnaya=mass[0]*x*m + mass[1]*(m-1);
                        for (j = 2; j < m; j++)
                                proizvodnaya = proizvodnaya * x + mass[j] * (m - j);
                };
        printf("%lld %lld\n", polynom , proizvodnaya);
        return 0;
}
