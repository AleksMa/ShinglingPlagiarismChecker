
#include <stdio.h>

int main(int argc, char **argv){
        int n;	
	long x;
	scanf("%d %ld", &n, &x);
	long a[n+1];
	
	for(int i = 0; i <= n; i++){
		scanf("%ld", a + i);
	};
	
	long long p = 0, d = 0;
	for(int i = 0; i <= n; i++){
		p *= x;
		p += a[i];
		//Т.к. производная вычисляется с использванием коэффициентов до n-1, то последяя итерация для него не вычисляется
		if (i !=n){
			d *= x;
			d += (n-i) * a[i];
		};
	};
	printf("%lld %lld\n", p, d);
	return 0;
}
	
		