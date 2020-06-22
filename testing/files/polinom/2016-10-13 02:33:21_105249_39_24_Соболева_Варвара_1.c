#include <stdio.h>

int main() 
{
        long long int S=0,Sp=0,x,n,a,i;
	
        scanf("%lli",&n);
	scanf("%lli",&x);
	
        long long int k=n;
	
        for(i=1;i<n+2;i++) {
	    scanf("%lli",&a);
	
            if (i==n+1) 
                S=S+a;
	    else S=(S+a)*x;
	
            if (n==i) 
                Sp=Sp+a;
	    else {
	        if (i!=n+1) {
		    Sp=(Sp+a*k)*x;
		    k=k-1;
		}
            }
	}
	
        printf("%lli %lli",S,Sp);
	return 0;
}
