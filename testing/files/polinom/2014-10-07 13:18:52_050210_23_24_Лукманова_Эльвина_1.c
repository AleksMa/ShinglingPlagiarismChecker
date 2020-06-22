
#include <stdio.h>
 
int main(int argc, char **argv)
{
    long  x, n, d=0, k=0, i;
    scanf ("%ld %ld", &n, &x);
    long a[n+1];
    for (i=n; i>=0; i--) {
        scanf ("%ld", &a[i]);
    }
    for (i=n; i>0; i--) {
        d=(d+a[i])*x;
        if(i>1) k=(k+a[i]*i)*x;
    }
    d=d+a[0];
    k=k+a[1];
    printf("%ld %ld", d, k);
    return 0;
}