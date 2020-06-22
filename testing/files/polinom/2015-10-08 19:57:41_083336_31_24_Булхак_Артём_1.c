#include <stdio.h>

int main(){
    
    
    long long n;
    
    scanf("%lld", &n);
    long long x;
    
    scanf("%lld", &x);
    long long array[n+1];
    
    int i;
    for (i=0; i<n+1; i++){
        scanf ("%lld", &array[i]);
    }
    long long sum1 = 0;
    for (i=0; i<n+1; i++) {
        sum1 = sum1 * x + array[i];
    }
    long long sum2 = 0;
    
    for (i=0; i<n; i++) {
        sum2 = sum2 * x + array[i] * (n-i);
    }
    printf("%lld %lld", sum1, sum2);
    
    return 0;
    
}