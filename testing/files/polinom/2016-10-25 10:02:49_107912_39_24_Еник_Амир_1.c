
#include <stdio.h>

int main()
{
        long p1,p2,n,x,a,i;
        
	scanf("%ld%ld", &n, &x);
	
	p1=0; p2=0;
	
	if ( n == 0)
	{
		scanf("%ld", &a);
		p1=a; p2=0;
		printf("%ld %ld\n", p1, p2);
	}
	else
	{
		for (i=n; i > 1; i--)
		{
			scanf("%ld", &a);
			p1=(x * (p1+a));
			p2=(x * (p2 + (a*i)));
		}
		scanf ("%ld", &a);
	    p1=(x * (p1+a)); 
	    p2=(p2+a);

	    scanf ("%ld", &a);
	    p1=(p1+a); 

	    printf ("%ld %ld\n", p1, p2);
	}
	return 0;
}
