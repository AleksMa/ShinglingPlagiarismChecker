#include <stdio.h>

int main()
{
        int x, n, nn;
	long long f, d;

		scanf("%d %d", &n, &x);
		long m[n];
		nn=n;
		
		for (int i=0; i<=n; i++)
		scanf("%ld", &m[i]);
		f=m[0];
		d=m[0]*n;

		for (int i=1; i<=n; i++)
		f=f*x+m[i];

		for (int i=1; i<n; i++)
		{	
			d = d*x + m[i]*(nn-1);
			nn--;
		}

		printf("%lld %lld", f, d); 

	return 0;
}