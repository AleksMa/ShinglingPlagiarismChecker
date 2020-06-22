#include <stdio.h>

int main(){
        long int n,x0,px,p_x,i,k;
	scanf("%ld %ld",&n,&x0);
	for(i=0,px=p_x=0;i<=n;i++){
		scanf("%ld",&k);		
		px=px*x0+k;
		if(i!=n) p_x=p_x*x0+k*(n-i);
	}
	printf("%ld %ld",px,p_x);
} 
