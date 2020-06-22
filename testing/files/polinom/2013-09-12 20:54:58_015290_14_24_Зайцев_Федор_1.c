#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    int n,x;
    scanf("%d%d",&n,&x);
    long long int t[n+1];
    
    int i=0;
    for (i=0;i<n+1;i++) {
        int temp;
        scanf("%d",&temp);
        t[i] = temp;
    }
    
    long long result = t[0];
    for (i=0;i<n;i++) {
        result = result*x + t[i+1];
    }
    printf("%lld ",result);
    
    
    
    result = t[0]*n;
    for (i=0;i<n-1;i++) {
        result = result*x + t[i+1]*(n-i-1);
    }
    
    printf("%lld",result);
    
    return 0;
}
