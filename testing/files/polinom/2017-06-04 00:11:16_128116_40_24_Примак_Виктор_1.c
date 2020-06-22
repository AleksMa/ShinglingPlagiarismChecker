#include <stdio.h>
#define HORNER(x,y,z) {x*=y; x+=z;}

int main(int argc, const char * argv[]) {
    unsigned int n;
    long an, x0, p, delta_p;
    
    scanf("%u %ld %ld", &n, &x0, &an);
    p = an;
    delta_p = an*n;
    
    for(int i = (n-1); i>0; i--) {
        scanf("%ld", &an);
        HORNER(p,x0,an)
        HORNER(delta_p,x0,(an*i))
    }
    scanf("%ld", &an);
    HORNER(p,x0,an)
    
    printf("%ld %ld\n", p, delta_p);
    return 0;
}