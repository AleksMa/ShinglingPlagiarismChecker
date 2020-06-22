
#include <stdio.h>

int main(int argc, const char * argv[])
{
    int n, x0;
    long i, p, pr;
    scanf("%d", &n);
    scanf("%d", &x0);
    int k[n];
    int q;
    q = n;
    for(i = 0; i <= n; ++i)
    {
        scanf("%d", &k[i]);
    }
    
    p = k[0];
    
    for(i = 0; i <= n-1; ++i)
    {
        p = p*x0 + k[i+1];
    }
    
    pr = k[0]*q;
    
    for (i=0; i <= n-2; ++i)
    {
        pr = pr*x0 + k[i+1]*(q-1);
        --q;
    }
    
    printf("%ld\n", p);
    printf("%ld\n", pr);
    
    return 0;
}
