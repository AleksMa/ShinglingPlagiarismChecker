
#include <stdio.h>

int main()
{
        long n,x0,newnumber,sum,deriv;
	deriv=sum = 0;
	scanf("%ld%ld", &n ,&x0);
	for(int i=0; i<=n; i++){
		scanf("%ld", &newnumber);
		sum= sum*x0 +newnumber;
		if(n!=i){
			deriv = deriv*x0 +newnumber*(n-i);
		}
	}
	printf("%ld %ld", sum, deriv);
        return 0;
}
