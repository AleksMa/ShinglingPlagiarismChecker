
#include <stdio.h>

int main()
{
    int n,st;
    int x;
    long i, b, b1;
    scanf("%d", &n);
    scanf("%d", &x);
    int a[n];
    st = n;
    for ( i = 0; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    
    b = a[0];
    b1 = a[0]*st;

    for ( i = 1; i <= n; ++i){
         b = b*x + a[i];
    }
    
    for ( i = 0; i <= n - 2; ++i){
        b1 = b1*x + a[i + 1]*(st - 1);
        --st;
        
    }
    
    printf("%ld %ld\n", b, b1);
    return 0;
}
