#include <stdio.h>
int main(){
        int n, i, x;
        scanf("%d", &n);
        long a[n], s, p;
	scanf("%d", &x);
	for(i=0; i<=n; i++) 
                scanf("%ld", &a[i]);
 	s=a[0];    	
 	for(i=1; i<=n; i++)
      		s=s*x+a[i];
	printf("%ld\n", s);	
	for(i=0;i<=n;i++)
        	a[i] = a[i] * (n - i);
        p=a[0];
        for(i=1;i<n;i++) 
		p=p*x+a[i];
	printf("%ld\n", p);
	return 0;
}