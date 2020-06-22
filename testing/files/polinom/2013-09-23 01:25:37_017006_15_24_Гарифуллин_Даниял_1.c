#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
        int x0, i, n, a; 
        long p1, p2;
        scanf("%d%d%d", &n,&x0,&a);
        if (n == 0) {
                p1=a;
                p2=0;
        }
        if (n == 1){
                p1 = x0*a;
                p2 = a;
        }
        if (n != 1){
                p1 = x0*a;
                p2 = n*x0*a;
        }
        for (i = n-1; i >= 0; i--){
                scanf("%d", &a);
                if (i == 1){
                        p1 = x0*(p1+a);
                        p2 = p2+a;
                }
                if (i == 0){
                        p1 = p1+a;
                }
                if (i != 0 && i != 1){
                        p1 = x0*(p1+a);
                        p2 = x0*(p2+i*a);
                        }
        }
        printf("%ld %ld\n", p1, p2);
        return 0;
}  