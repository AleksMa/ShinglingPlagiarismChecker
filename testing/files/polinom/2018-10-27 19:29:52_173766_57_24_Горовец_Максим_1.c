#include <stdio.h>

int main(int argc, const char * argv[]) 
{
    long polynom = 0, proizvodnaya = 0, x, n, a;
    scanf("%li", &n);
    scanf("%li", &x);
    for(long i = 0; i <= n; i++){
        scanf("%li", &a);
        polynom = polynom * x + a;
        if(n != i)  proizvodnaya = proizvodnaya * x + a * (n - i);
    }
    printf("%li %li", polynom, proizvodnaya);
    return  0;
}
