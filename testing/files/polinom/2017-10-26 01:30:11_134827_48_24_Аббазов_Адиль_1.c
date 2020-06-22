#include <stdio.h>

void polynomial(int n, long long int x, long long int a[n]) {
    long long int p = a[0], d = 0;
    for (int i = 1; i <= n; i++) {
        p = p * x + a[i];
        d = d * x + a[i - 1] * (n - i + 1);
    }
    printf("%lli %lli", p, d);
}

int main() {
    int n, i = 0;
    long long int x;
    
    scanf("%i", &n);
    scanf("%lli", &x);
    
    long long int a[n];
    while (i <= n && scanf("%lli", &a[i]) == 1)
        i++;
    
    polynomial(n, x, a);
    return 0;
}