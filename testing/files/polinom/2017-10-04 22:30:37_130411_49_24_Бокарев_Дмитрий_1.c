#include <stdio.h>

int main() {
    long int n, a, x, s, s1;

    s=0;
    s1=0;
    scanf ("%ld%ld", &n, &x);
    int m[n+1];

    for (int i=0; i<=n; ++i) scanf("%d", &m[i]);
    for (int i=0; i<n; ++i) s=(s+m[i])*x;

    s=s+m[n];

    a=n;

    for (int i=1; i<n; ++i) {
        s1=(s1+a*m[i-1])*x;
        a=a-1;
    }
    s1=s1+m[n-1];

    printf("%ld %ld", s, s1);
    return 0;
}