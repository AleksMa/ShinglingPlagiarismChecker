#include <stdio.h>

/* P'=(...((a(n)*n*x+a(n-1)*(n-1))*x+a(n-2)*(n-2))*x+...a2*2)*x+a1   производная полинома по
модифицированной схеме горнера */
int main(int argc, char **argv)
{
    long n,x0,a,P,Pp;    
    scanf("%ld%ld%ld",&n,&x0,&a);
    if (n==0){                      //если у полинома нулевая степень, P=a0 P'=0
        printf("%ld %d",a,0);
        return 0;
    }
    P=a*x0;
    Pp=a*n;
    while (--n){                    //из цикла выйдем со значением P=p-a0 и Pp=P'
        scanf("%ld",&a);
        P=(P+a)*x0;
        Pp=Pp*x0+a*n;
    }
    scanf("%ld",&a);                
    P+=a;                           //добавляем это самое a0
    printf("%ld %ld",P,Pp);
    return 0;
}
