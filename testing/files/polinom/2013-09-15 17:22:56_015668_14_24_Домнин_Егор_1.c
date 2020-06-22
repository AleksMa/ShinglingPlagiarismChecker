#include <stdio.h>

int main()  
{
        long long int n,x,k,d,p;
        scanf("%lli %lli",&n,&x);
        scanf("%lli",&k);
        d=k*x;
        p=k*n;
        --n;
        while (n>0){
                scanf("%lli",&k);
                d=(d+k)*x;
                p=p*x+k*n;
                --n;
        }
        scanf("%lli",&k);
        d=d+k;
        printf("%lli %lli",d,p);
}

