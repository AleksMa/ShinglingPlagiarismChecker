#include <stdio.h>
#include <math.h>
#include <string.h>

long helper(long a, long b){
        long step = a;
	while(b>1){
		step = step * a;
		b--;
	}
	if (b == 0) (step = 1);
	//printf("%d\n", step);
	return step;
}
int main(){
	long a1,a2,x;
	int n,i;
	scanf("%d", &n);
	scanf("%ld", &x);
	scanf("%ld", &a1);
	long P = a1;
	int j = n;
	long Pr = j*a1*helper(x,(j-1));
	//printf("%ld\n", Pr);
	j--;
	for(i=0;i<=(n-1);i++){
		scanf("%ld", &a2);
		P = P*x + a2;
		Pr = Pr + j*a2*helper(x,(j-1));
		//printf("Pr= %ld\n", Pr);
		j--;
	}
	printf("%ld\n", P);
	printf("%ld\n", Pr);
	return 0;
}