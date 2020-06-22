#include <stdio.h>
#include <math.h>

int main(int argc , char ** argv)
{
    long long n, x, data, result, res;
    n = 0;
    scanf(" %lld%lld", &n, &x);
    int i = 0;
    for (i = 0; i < n + 1; i++) {
        scanf(" %lld", &data);
        if (i == 0) {
            result = data;
            res = data * n;
        }
        else {
            result *= x;
            result += data;
            if (i < n) {
                res *= x;
                res += data * (n - i);
            }
        }

    }
    printf("%lld %lld", result, res);
        return 0;
}
