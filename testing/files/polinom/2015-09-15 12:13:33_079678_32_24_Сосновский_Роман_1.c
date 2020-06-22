#include <stdio.h>
#include <stdlib.h>

long long pol(int coef_len, long long* coef, long long x) {
    long long ret = 0;

    int cnt_coef = 0;
    for(int i = coef_len - 1; i >= 0; i--) {
        ret += coef[cnt_coef];

        if(i != 0) {
            ret *= x;
        }

        cnt_coef++;
    }
    return ret;
}

long long p_pol(int coef_len, long long* coef, long long x) {
    long long ret = 0;

    int cnt_coef = 0;
    for(int i = coef_len - 1; i > 0; i--) {
        ret += coef[cnt_coef] * i;

        if(i != 1) {
            ret *= x;
        }

        cnt_coef++;
    }
    return ret;
}

int main() {
    int coef_len;
    scanf("%d", &coef_len);
    coef_len += 1;

    int x;
    scanf("%d", &x);

    long long* coef = malloc(coef_len * sizeof(long long));
    for(int i = 0; i < coef_len; i++) {
        scanf("%lld", &coef[i]);
    }


    printf("%lld %lld", pol(coef_len, coef, x), p_pol(coef_len, coef, x));

    free(coef);
}
