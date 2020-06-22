
#include <stdio.h>

int main()
{
    long x0 ;
    long n = 0  ; /*Cтепень полинома */
    long a = 0 ; /*Коэффициент полинома */
    long long p1 ; /*Полином */
    long long p2 ; /*Производная от полинома */
    scanf("%li" , &n);
    scanf("%li" , &x0);
    scanf("%li" , &a);
    p1 = a;
    p2 = n*a;
    while (n != 0) {
        scanf("%li" , &a);
        p1 = p1*x0 + a;
        if (n-1) p2 = p2*x0 + a*(n-1);
        n = n - 1;
    }
    printf("%lli %lli" , p1 , p2);
    return 0;
}
