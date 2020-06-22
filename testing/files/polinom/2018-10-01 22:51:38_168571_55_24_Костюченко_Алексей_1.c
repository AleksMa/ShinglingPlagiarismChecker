#include <stdio.h>

int main(){
    
    long long n, x0,F,f;
    
    scanf("%lld %lld", &n, &x0);
    long long a[n];
    for (int i = n; i >= 0; i--) {
        scanf("%lld", &a[i]);
    }
    if (n > 1){
        F = a[n]*x0 + a[n-1];
        for (int i = n - 2; i >= 0; i--) {
            F = F*x0 + a[i];
        }
        f = (n)*a[n]*x0 + (n-1)*a[n-1];
        for (int i = n - 2; i >= 1; i--) {
            f = f*x0 + i*a[i];
        }
    }else{
        if (n){
            F = x0*a[1] + a[0];
            f = a[1];
        }else{
            F = a[0];
            f = 0;
        }
    }
    
    printf("%lld %lld\n", F, f);
    return 0;
}
