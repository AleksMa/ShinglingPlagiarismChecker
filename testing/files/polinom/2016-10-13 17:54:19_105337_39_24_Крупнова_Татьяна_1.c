
#include <stdio.h>

int main() {
         long int s, x0, a1, a, p,b;
	 int n,i;
	 scanf("%d%ld%ld",&n,&x0,&a1);
	 s=a1;
	 p=a1*n;
	 for (i=n-1; i>=0; --i) {
			scanf("%ld", &a);
			s=s*x0+a;
			p=p*x0+a*i;
			if (i==1) b=a;
	 }
	 if (x0==0) printf("%ld %ld",s, b);
	 else printf("%ld %ld",s, p/x0);
	 return 0;
}
         
