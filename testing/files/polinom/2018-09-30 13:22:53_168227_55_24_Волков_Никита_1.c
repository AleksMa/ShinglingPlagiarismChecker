#include <stdio.h>

int main(int argc, char **argv){
        long s=0;
	long x=0;
	scanf("%ld %ld", &s, &x);
	long a[s+1];
	for(int i = 0; i < s+1; ++i){
		scanf("%ld", &a[i]);
	}
	long sum =a[0]*x+a[1];
	for(int i = 0; i < s-1;++i){
		sum = sum*x + a[i+2];
	}
	for(int i = 0; i < s+1; ++i){
		a[i]*=(s-i);
	}
	long proizv;
	if (s ==1){
		printf ("%ld %ld", sum, a[0]);
		return 0;
	}
	proizv=a[0]*x+a[1];
	for(int i = 0; i < s-2;++i){
		proizv = proizv*x + a[i+2];
	}
	printf ("%ld %ld", sum, proizv);
	return 0;
}
