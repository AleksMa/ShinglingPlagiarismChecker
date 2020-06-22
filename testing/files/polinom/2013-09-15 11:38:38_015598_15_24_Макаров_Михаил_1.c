#include <stdio.h>
main()
{ 
        int n,x0,a,i;
        long  p1,p2;
        scanf("%d%d%d",&n,&x0,&a);
        if (n==1){
                p2=a;
                p1=a*x0;
        }else{
                p1=a*x0;
                p2=a*n*x0;
        }
        for ( i=n-1;i>=0;i--){
                scanf("%d",&a);
	        if (i==1){
	                p1=(p1+a)*x0;
	                p2=p2+a;
	        }
                if (i==0){
                        p1=p1+a;
                }
                if (i!=0 && i!=1){
                        p1=(p1+a)*x0;
                        p2=(p2+i*a)*x0;
	        }
        }
        printf("%ld %ld",p1,p2);
        return 0; 
} 