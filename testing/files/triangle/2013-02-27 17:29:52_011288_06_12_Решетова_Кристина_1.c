# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

int cheat(long long n){
        int j, t=0;

	if(n%(2*3*5*7*11)!=0)
		return;
	for(j=2;j<(long long)sqrt(n)+1;j++)
		if (n%j==0) t+=2;
	if(j*j==n) t--;

	return t;
}

int main(){
	long long i=0, n=0, s=0;

	while (s<3000){
		i++;
		n+=i;
		s=cheat(n);
	}
	printf("%lld", n);
	return 0;
}