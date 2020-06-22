#include <stdio.h>
#include <stdlib.h>
//#include "mylibrary.h"
#define type int

type *resheto_eratosphena(type n)
{
        type *a,i,j,k=n-1;
        char *s=(char*)malloc(n*sizeof(char));
	for(i=0; i<n; i++) 
		*(s+i)=1;
	for(i=1; (i+1)*(i+1)<=n; i++)
		if(s[i])
			for(j=(i+1)*(i+1); j<=n; j+=i+1)
				if(s[j-1]) {s[j-1]=0; k--;}
	k=k;
	a=(type*)malloc((k+1)*sizeof(type));
	a[0]=k;
	for(i=n-1; i>0; i--)
		if(s[i]) {a[k]=i+1; k--;}
	free(s);
	return a;
}

long long koll(long long x, int *o)
{
        int s=1,i,j=1;
        if(x%2==0) x/=2;
	while (x!=1 && j!=14)
	{
		i=0;
		while(x%*(o+j)==0) 
		{
			x/=*(o+j);
			i++;
		}
		s*=++i;
		j++;
	}
	return s;
}

int main()
{
	long long a=1,b=2,s1=1,s2=1,s=0;
	int *o;
	o=resheto_eratosphena(42);
	s=*o;
	while(s<3000)
	{
		a++;
		b++;
		s1=s2;
		s2=koll(b,o); 	
		s=s1*s2;
	}
	printf("%lld",a*b/2);
	return 0;
}