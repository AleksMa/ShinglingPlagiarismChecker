#include <stdio.h>

int main()
{
        long n,i,x,a; //reko može
        long c,d;
        
        scanf("%ld", &n);
        scanf("%ld", &x);
        scanf("%ld", &a);
        c=a;
        d=n*a;
        
        for(i=n; i>1; i--){
            
                c *= x;
                scanf("%ld", &a);
                c += a;
                    
                d *= x;
                d += a*(i-1);                            
        }
        
        scanf("%ld", &a);
        c *= x;
        c += a;
        
        printf("%ld %ld\n", c,d);
        
        return 0;
}
