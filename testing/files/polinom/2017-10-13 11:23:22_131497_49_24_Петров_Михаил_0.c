#include <stdio.h>
int main(int argc, char **argv)
{
    long a = 0, b = 0, c,x,n,i,k;
    scanf("%ld %ld", &n, &x);
    for (i = n; i > 0; i--) {
        scanf("%ld", &c);
        for (k = i; k > 0; k--) {
             c *= (x != 0)? x: (i == 1)? 1: x; 
        }
        a += (x != 0)? c: 0;  
        b += (x != 0)? (c / x)* i: (i == 1)? c: 0; 
    }
    scanf("%ld", &x);
    a += x;
    printf("%ld %ld", a, b);
    return 0;
}