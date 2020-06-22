#include <stdio.h>
#include <stdlib.h>
int main()
{
   long x, k, p=0, p1=0,n;
   scanf("%ld",&n);
   scanf("%ld",&x);
    while (n>=0)
    {
        scanf(" %ld", &k);
        p=p*x+k;
        if (n>0)
        {
            k=k*n;
            n=n-1;
            p1=p1*x+k;
        }
        else{
        n=-1;
        }
    }
    printf("%ld %ld",p, p1);
    return 0;
}