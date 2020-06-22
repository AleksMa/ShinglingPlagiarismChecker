#include <stdio.h>
 
int main (){        
    long long F = 1, f = 1;
        long long n = 0, x = 0;
	scanf("%lld", &n);
	scanf("%lld", &x);
	long long A[n + 1];
 
 
	for (int i = 0; i < n + 1; i++){
		scanf("%lld", &A[i]);
	}
 
 
	F = A[0] * x + A[1];
	f = n * A[0] * x + (n - 1) * A[1];
 
 
	for (int i = 1; i < n; i++){
		F = F * x + A[i + 1];
	}	 
 
	if (n != 1){
		for (int i  = 1; i < n - 1; i++){
			f = f * x + A[i + 1] * (n - i - 1);
		}
	}
	else{
		f = A[0];
	}
 
	printf("%lld %lld", F, f);
 
	return 0;
}
