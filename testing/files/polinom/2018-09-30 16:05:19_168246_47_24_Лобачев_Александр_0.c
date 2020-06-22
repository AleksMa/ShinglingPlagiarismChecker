#include <stdio.h>

int main (int argc, char **argv)

{
    long n, x, a, p=0, pr=0, i;
    scanf("%li\n", &n);
    scanf("%li\n", &x);
    for (i = n; i > 1; i--) {
        scanf("%li", &a);
        p += a;
        p *= x;
        pr += a*i;
        pr *= x;
    } 
    scanf("%li\a", &a);
    pr +=a;
    p += a;
    p *= x; 
    scanf("%li\a", &a);
    printf("%li %li ", p += a, pr);
    return 0;
}