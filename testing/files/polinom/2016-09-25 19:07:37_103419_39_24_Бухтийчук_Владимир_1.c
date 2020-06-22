#include <stdio.h>
#include <malloc.h>

int main()
{
    int i, n, x;
    long long y=1, y1=1; 
    
    scanf("%d%d", &n, &x);
    
    int a[n + 1];
    
    for (i=0; i < n + 1; i++)
    {
        scanf("%d", &a[i]);
    }
    
    y=a[0];
    for (i=1; i < n + 1; i++)
    {
        y=(long long)((long long)y*(long long)(x) + (long long)a[i]);
    }
    
    y1=a[0]*n;
    for (i=1; i < n; i++)
    {
        y1=(long long)((long long)y1*(long long)(x) + (long long)a[i]*(n - i));
    }
    
    printf("%lld %lld\n", y, y1);
        
    return 0;
}
