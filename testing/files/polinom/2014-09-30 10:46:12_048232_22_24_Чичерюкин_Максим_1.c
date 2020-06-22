#include <stdio.h>

int main()
{
        long x, p=0, y=0, z=0, i;
        unsigned long n;
        scanf ("%ld%ld", &n, &x);
        long a[n];
        for (i=0; i<=n; i++)
        {
                scanf("%ld", &a[i]);
        }
        y=a[0];
        z = a[0]*n;
	if (n==1)
	{	
		y= y*x + a[1];
	}	
	else
	{  
		for (i=1;i<=n;i++)
		{
			y= y*x + a[i];
		}
		for (i=1;i<n;i++)
		{
		z= z*x + a[i]*(n-i);
		}
	}
        printf ("%ld\n%ld\n", y, z);
        return 0;
}
