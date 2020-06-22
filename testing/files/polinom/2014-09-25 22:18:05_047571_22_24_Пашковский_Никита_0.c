#include <stdio.h>
#include <math.h>

long n, a, x, p,p1;

int main( int argc, char **argv )
{
    scanf ( "%d", &n);
    scanf ( "%ld", &x);
    p = 0, p1 = 0;
    
    while (n > 0) {
        
        scanf ( "%ld", &a ); 
        p = ( p + a )*x;
        if (n > 1) p1 = (p1 + a*n)*x; else p1 = p1 + a;
        n--;
    }
    scanf( "%ld", &a );
    p = p + a;
    printf("%ld %ld \n", p, p1); 
    return 0;
}