#include <stdio.h>
int main(int argc, char **argv)
{
    long b, c,x,k;
    int i,n;
    scanf("%d %ld", &n, &x);
    long a[n];
    scanf("%ld", &a[n]);
    c = a[n];
    k = c*(n);
    for (i = n - 1; i > 0; i--){
        scanf("%ld", &a[i]);
        c = c*x + a[i];
    }
    for (i = (n - 1); i > 0; i--){
        a[i] = a[i]*(i);
        k = k*x + a[i];
    }
    scanf("%ld", &b);
    c =c*x + b;
    printf("%ld %ld", c, k);
}