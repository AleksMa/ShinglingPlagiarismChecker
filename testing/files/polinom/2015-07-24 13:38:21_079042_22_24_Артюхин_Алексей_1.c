
#include <stdio.h>

int main()
{
        int n,x0;
        long long pol,pro;
	scanf("%d",&n);
	int koef[80];
	scanf("%d",&x0);
	for(int i=0;i<n+1;i++)
		scanf("%d",&koef[i]);
	pol=koef[0];
	for(int i=1;i<n+1;++i)
		pol=pol*x0+koef[i];	
	pro=n*koef[0];
	for(int i=1;i<n;++i)
		pro=pro*x0+koef[i]*(n-i);	
	printf("%lld %lld\n",pol, pro);
	return 0;
}
