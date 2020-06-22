#include <stdio.h>
#include <math.h>

int main(int argc , char ** argv)
{   int i, n, x0;
    long long int p = 0, dp = 0;
    scanf("%d%d", &n, &x0);
    n++;
    int a[n];
    for (i=0; i<n; i++)
        scanf("%d", &a[i]);
    for (i=0; i<n; i++)
        p = p*x0 + a[i];
    n--;
    for (i=0; i<n; i++)
        dp = dp*x0 + (n-i)*a[i];
    printf("%lli %lli",p,dp);
        return 0;
}