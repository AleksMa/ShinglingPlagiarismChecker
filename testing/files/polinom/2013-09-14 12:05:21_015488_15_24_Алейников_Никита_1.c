
#include <stdio.h>

int main()
{
        int n,i,an,x0;
        long S1, S2;
	scanf("%d", &n);
	scanf("%d", &x0);
	S1=0;
	S2=0;
	for (i=n;i>=0;i--) {
		scanf("%d", &an);
		if (i>1) {
			S1=(S1+an)*x0;
			S2=(S2+an*i)*x0; 
		} else if (i==1) {
			S1=(S1+an)*x0;
			S2=S2+an;
		} else S1=S1+an;	  
	} 
        printf("%lld %lld", S1, S2);
	return 0;
} 

