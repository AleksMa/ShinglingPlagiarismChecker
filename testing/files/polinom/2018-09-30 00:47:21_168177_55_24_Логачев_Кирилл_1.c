#include <stdio.h>

int main(){
    long n, a, polynom = 0, x, derivative = 0;
    scanf("%ld %ld %ld ", &n, &x, &a);
    polynom = a * x;
    derivative = (n != 1) ? (a * n * x) : a;
    //printf("%ld\n", polynom);
    for (long i = (n - 1); i > 0;  --i){
        scanf("%lu ", &a);
        polynom = (polynom + a) * x;
        derivative = (i != 1) ? ((derivative + a * i) * x) : (derivative + a);
        //printf("%ld\n", polynom);
    }
    scanf("%ld ", &a);
    polynom += a;
    printf("%ld %ld\n", polynom, derivative);
    return 0;
}

