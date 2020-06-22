#include <stdio.h>

int main()
{
    int n = 0;
    long x0 = 0;
    long c = 0;
    long d = 0;
    
    scanf("%d%ld", &n, &x0);
    
    long a[n+1];
    long b[n+1];
    
    for(int i=0; i<n+1; i++){
        scanf("%ld", &a[i]);
        b[i] = a[i]*(n-i);
    }
    
        for(int i=0; i<n+1; i++){
        c = a[i] + c*x0;
    }
	for(int j=0; j<n; j++){
        d = b[j] + d*x0;
    }
    
    printf("%ld %ld\n", c, d);
    
    return 0;
}
