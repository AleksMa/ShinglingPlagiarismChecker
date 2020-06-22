#include <stdio.h>

int main() {
    int n, x0;
    scanf("%d%d", &n, &x0);
    n += 1;
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long Pn = 0;
    for(int i = 0; i < n; i++) {
        Pn = Pn * x0;
        Pn += a[i];
    }
    long long P = 0;
    for(int i = 0; i < n - 1; i++) {
        int k = n - 1 - i;
        P = P * x0;
        P += a[i] * k;
    }

    printf("%lld\n%lld", Pn, P);
    return 0;
}