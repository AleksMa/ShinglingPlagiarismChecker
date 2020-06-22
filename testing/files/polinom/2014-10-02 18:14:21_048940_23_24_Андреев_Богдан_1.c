#include <stdio.h>

main()
{
	int n,x,a,i;
        long polynom, proizv;
        scanf("%d %d", &n, &x);
        scanf("%d", &a);
        polynom=a;
        proizv=n*a;
        for(i=n; i>0; i--){
                scanf("%d", &a);
                polynom=polynom*x+a;
                if (i>1) proizv=proizv*x+a*(i-1);
        }
        printf("%ld %ld\n", polynom, proizv);
        return 0;
}
