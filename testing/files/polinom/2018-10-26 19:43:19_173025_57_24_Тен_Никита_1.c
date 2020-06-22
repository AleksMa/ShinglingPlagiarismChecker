#include <stdio.h>

int main(){
    long long x, f, pr, n, a;
     scanf("%lli", &n);
    scanf("%lli", &x);
    long long kef [(n+1)];
    for(a = 0 ; a <= n ; a++){
        scanf("%lli", &kef[a]);
    }
    f = kef[0];
    pr = f*n;
    for(a = 1; a <= n; a++){
        f = f *x + kef[a];
    }
    printf("%lli", f);
    for(a = 1; a < n; a++){
        pr= pr*x + kef[a]*(n-a);
    }
    printf(" %lli", pr);
}