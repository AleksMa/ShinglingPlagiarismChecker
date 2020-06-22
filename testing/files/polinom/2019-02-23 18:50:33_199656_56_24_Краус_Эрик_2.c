
#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n , x , b ;
    long long result ;
    scanf("%d %d", &n ,&x);
    int mas[n] ;
    for ( int i = 0 ; i <= n ; i++) {
        scanf("%d", &b);
        mas[i] = b ;}
    result = mas[0] ;
    for ( int i = 1 ; i <= n ; i++ ) {
        result *= x ;
        result += mas[i];}
    printf("%ld\n" , result);
    result = mas[0] * n  ;
    for (int i = 1 ; i <= n-1 ; i++) {
        result *= x ;
        result += mas[i]*(n-i) ;}
    printf("%ld\n" , result);
    return 0;
} 
