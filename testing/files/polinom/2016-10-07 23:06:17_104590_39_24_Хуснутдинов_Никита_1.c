#include <stdio.h>

int main() {
    long x1,i,n;
    scanf("%ld", &n);
    scanf("%ld", &x1);
    long a[n];
    for (i=0; i<=n; i++) scanf ("%ldx" ,  &a[i]);
    
    long sum=a[0]*x1+a[1];
    for (i=2; i<=n ; i++) sum = x1*sum+a[i];
    
    long pro = a[0]*n;
    for (i=1; i<=n-1; i++) pro = pro*x1+a[i]*(n-i);
    printf("%ld\n", sum);
    printf("%ld\n", pro);
    return 0;
}

