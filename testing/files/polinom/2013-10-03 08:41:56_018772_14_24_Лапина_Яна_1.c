#include <stdio.h>
 
int main()
{
    long long int n, i, x, p, p1;
    scanf("%lli\n %lli", &n, &x);
    int a[n+1];
   
    for (i = 0; i <= n; ++i)
        scanf("%lli", &a[i]);
       
    p = 0;
    p1 = 0;
    for (i = 0; i <= n; ++i){
        p1 = p1*x+p;
        p = p*x+a[i];
    }
   
    printf("%lli %lli", p, p1);
   
        return 0;
}