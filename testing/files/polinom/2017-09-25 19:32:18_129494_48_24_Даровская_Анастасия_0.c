
#include <stdio.h>

int main(int argc,char**argv)
{long n=0, x=0, a=0, r=0, rp=0;
        scanf("%ld%ld%ld", &n, &x, &a);
	r=a; rp=a*n;
	for(n;n!=0;n--) {
		scanf("%ld", &a); 
		r*=x; r+=a;
		if (n==1) 	rp+=a*(n-1);
		else {rp*=x; rp+=a*(n-1);}
	}
	printf("%ld %ld", r, rp);
	return 0;
}