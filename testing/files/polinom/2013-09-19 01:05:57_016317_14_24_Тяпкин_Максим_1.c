
#include <stdio.h>

int main()
{
    long long int n;
    scanf("%lld", &n);

    long long int x0;
    scanf("%lld", &x0);

    long long int a;
    scanf("%lld", &a);

    long long int polynom = a;
    long long int dif = a * n;
    long long int i;

    for(i = 0; i < n; i++){
        polynom *= x0;
        if (i != n - 1) dif *= x0;

        scanf("%lld", &a);

        polynom += a;
        dif += a * (n - i - 1);
    }

    printf("%lld %lld", polynom, dif);
    return 0;
}