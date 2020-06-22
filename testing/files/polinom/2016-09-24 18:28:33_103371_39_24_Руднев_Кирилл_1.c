
#include <stdio.h>

long x0;

long func (long n) {
    long f = 1;
    for (long i=0; i<n; i++) {
        f = f*x0;
    }
    return f;
}

int main() {
    long n;
    scanf("%ld", &n);
    scanf("%ld", &x0);
    long res = 0;
    long res1 = 0;
    for (long i=0; i<=n; i++) {
        long a_1;
        scanf("%ld", &a_1);
        res = res + a_1*(n-i)*func(n-i-1);
        res1 = res1*x0 + a_1;
    }
    printf("%ld %ld\n", res1, res);
    return 0;
} 
