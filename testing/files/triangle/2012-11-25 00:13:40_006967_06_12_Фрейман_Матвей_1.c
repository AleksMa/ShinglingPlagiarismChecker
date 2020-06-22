# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

int main(){
        long long i=0, n=0, t=0, j;

	while (t<3000){
		t=0;
		i++;
		n+=i;
		if(n%(2*3*5*7*11*13*23)!=0)
			continue;
		for(j=2;j<sqrt(n)+1;j++)
			if (n%j==0) t+=2;
			if(j*j==n) t--;
	}
	printf("%lld",n);
  	return 0;
}