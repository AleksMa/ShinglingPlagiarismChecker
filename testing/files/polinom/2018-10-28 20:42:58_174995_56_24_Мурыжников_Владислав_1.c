#include <stdio.h>
int main()
{  
        long x,n,s=0,i,p=0;        
        scanf("%ld%ld" , &n, &x);
        long a[n+1];
        for (i=0;i<=n;i++)
                scanf("%ld" ,  &a[i]); 
        for (i=0;i<n;i++) 
                s=(s+a[i])*x; 
        for (i=0;i<n-1;i++)
                p=(p+a[i]*(n-i))*x;
        p=p+a[n-1];
        s=s+a[n];
        printf("%ld %ld\n" ,  s ,p); 
        return 0;
} 
