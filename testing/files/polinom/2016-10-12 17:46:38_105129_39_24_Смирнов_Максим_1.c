#include <stdio.h>

int main(int argc, char** argv)
{
    long long int length, x,
        value = 0,
        deriv = 0;
    scanf("%lld %lld", &length, &x);

    int i;
    for(i = length; i >= 0; i--) {

        long long int a;
        scanf("%lld", &a);

        value = value * x + a;
        if(i) deriv = deriv * x + a * i;

    }

    printf("%lld %lld", value, deriv);

    return 0;
} 