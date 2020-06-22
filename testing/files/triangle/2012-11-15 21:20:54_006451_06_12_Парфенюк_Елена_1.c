
#include <stdio.h>

int main()
{
    const long p=3000;
    long n=0,a=1,b=0,i,s;
    while (b<27*p*p*p/8) { /* Стандартная оценка кол-ва делителей, как
    p=(3*p/2)^(n-1) , где n - количество цифр в кол-ве делителей p(3000)=4 */
        b+=a;
        a++;
    }
    while (n<p) {
        b+=a;
        n=0;
        a++;
        i=1;
        s=1;
        while ((i<b/s) && i<s+p) {
            if (b%i==0) {
                n+=2;
                s=i;
            }
            i++;
        }
    }
    printf("%ld",b);
    return 0;
}