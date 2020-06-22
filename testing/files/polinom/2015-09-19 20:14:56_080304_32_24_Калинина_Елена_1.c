
#include <stdio.h>

int main(int argc, char **argv)
{
        int a, x0, n, n0, a1, i;
	long Pn, Prn;
	scanf("%d %d", &n, &x0);
	scanf("%d", &a);
	if (n==0) Pn=a;
	else Pn=a*x0;
	if (n==1) Prn=a*n;
	else Prn=a*n*x0;
	n0=n;
	for (i=0; i<n; i++) {
		n0=n0-1;
		scanf("%d", &a1);
		if (n0==1) {
			Prn=Prn+a1;
			Pn=(Pn+a1)*x0;
		}
		else {
			if (n0==0) Pn=(Pn+a1);
			else {
			        Pn=(Pn+a1)*x0;
			        Prn=(Prn+a1*n0)*x0;
		        }
		}
	}
	printf("%ld %ld",Pn, Prn);				
	return 0;
}
