
# include <stdio.h>

int main (int argc, char **argv)
{
    unsigned short n, i;
    long x0,a,p1 = 0,p2 = 0;
    scanf("%hu %ld %ld",&n ,&x0,&a);
    p1 = a;
    p2 = a*n;
    for(i = 1;i <(1+n); ++i) {
        scanf("%ld",&a);
        p1 = (p1*x0)+ a;
        if (i< n) (p2 = p2*x0 + (n - i)*a);
    };
    printf("%ld %ld\n",p1, p2);
    return 0;
}