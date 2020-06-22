#include <stdio.h>

int main() {
    int n, x0, i;
    long long int func, func1;
    func = 0;
    func1 = 0;
    printf("\n");
    scanf("%d" , &n);
    scanf("%d" , &x0);
    long a[n];
    
    for (i = 0; i < n + 1; i++) { 
        scanf("%li" , &a[i]);
    }
    for (i = 0; i < n + 1; i++) { 
        func = ( func * x0 ) + a[i];
    }
    
    printf("%lli\n" , func);
    
    for (i = 0; i < n; i++) { 
        func1 = ( func1 * x0) + a[i] * ( n - i);
    
    }
    printf("%lli" , func1);
    return 0;
}