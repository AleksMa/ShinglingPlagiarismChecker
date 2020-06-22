#include <stdio.h>

int main(int argc, char **argv) {
    long n, x, q, a =1 ,w,e=0,r=0;
    scanf("%ld %ld", &n, &x);
    for (q=n;q>-1;q--)
    {

        scanf("%ld" , &a);
for (w=q; w>0; --w){
a*=(x!=0)? x:(q<2)?1 :x;
}
e+=(x!=0)? a :(q==0)? a:0;
r+=(x!=0)? a*q/x: (q==1)? a:0;
    
       
    };
    printf("%ld %ld ",e,r);
    return 0;
}