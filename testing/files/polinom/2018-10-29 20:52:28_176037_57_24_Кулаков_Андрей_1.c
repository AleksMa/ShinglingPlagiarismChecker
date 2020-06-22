#include <stdio.h>

int main(int argc,char **argv) {
        int n,i,x;
        long int s,p;
        scanf("%d",&n);
        printf("\n");
	scanf("%d",&x);
	printf("\n");
	int a[n];
        scanf("%d",&a[0]);
	s=a[0];
	p=0;
	for(i=1;i<(n+1);i++){
                scanf("%d",&a[i]);
		s=x*s+a[i];
		p=x*p + a[i - 1] * (n - i + 1);
	} printf("%ld %ld",s,p);
        return 0;
}       