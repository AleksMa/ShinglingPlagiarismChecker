
#include <stdio.h>

int main()
{
        int n; 
        int x; 
        scanf("%d", &n);
        scanf("%d", &x);
        int a[n]; 
        int i; 
        for (i=n; i>=0; i=i-1) 
                scanf("%d", &a[i]); 
        long long P=a[n]; 
        long long PP=a[n]*n; 
        for (i=0; i<n; i=i+1) 
                P=P*x+a[n-i-1]; 
        for (i=n; i>1; i=i-1) 
                PP=PP*x+a[i-1]*(i-1); 
        printf("%lld\n %lld", P, PP);
        	return 0;
}
