#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main(void) {

    long long power, x0;
    scanf("%lld", &power);
    scanf("%lld", &x0);

    long long coeffs_count = power + 1;

    int coeffs[coeffs_count];

    for (long long i = 0; i < coeffs_count; i++) {
        scanf("%d", &coeffs[i]);
    }


    long long val = coeffs[0];


    for (long long i = 0; i < power; i++) {
        val = val * x0 + coeffs[i + 1];
    }


    long long derivative = power == 0 ? 0 : coeffs[0] * power;

    for (int i = 0; i < power - 1; i++) {
        derivative = derivative * x0 + coeffs[i + 1] * (power - i - 1);
    }

    printf("%lld %lld", val, derivative);

        return 0;
}