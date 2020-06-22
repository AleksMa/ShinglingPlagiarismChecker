/*102774672000*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

int main()
{        long long n=0;
	int kol=0,i=0,j;
	while (kol<3000)
	{	kol=0;
		i++;
		n+=i;
		if(n%(2*3*5*7*11)!=0)
		  continue;
		for(j=2;j<sqrt(n)+1;j++)
		  if (n%j==0) 
		    kol+=2;
		if(sqrt(n)*sqrt(n)==n)
		  kol--;
	}
	printf("%lld\n",n);
	return 0;
}