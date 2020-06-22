
#include <stdio.h>

int main (int argc, char **argv)
{
    long i, n, x, a, p, d;
    scanf("%ld %ld", &n, &x);
    
    long arr[n+1];
    for(i = n; i >= 0; i--){
        scanf("%ld", &a);
        arr[i] = a;
        }
        
    p = arr[n];
    for(i = n; i > 0; i--)
        p = p * x + arr[i - 1];
        
    d = arr[n] * n;
    for(i = n; i > 1; i--)
        d = d * x + (arr[i - 1] * (i - 1));
        
    printf("%ld %ld", p, d);
    return 0;
}