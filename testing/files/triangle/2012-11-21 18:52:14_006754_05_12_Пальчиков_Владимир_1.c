#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* sieve(int n){
        int i, j, k;
        char *res;
        res = (char*)malloc(n);
        for(i=2;i<n;i++) res[i] = 1;
        for(i=2; i<n;i++){
                if(res[i] == 1 ){
                    k = i;
                    for(j=i+k;j<n;j+=k){
                            res[j] = 0;
                    }
                }
        }
        return res;
}

unsigned long long d(unsigned long long x, char*a){
        unsigned long long i, k, r=1;
        for(i=0;i*i<=x;i++){
                k=1;
                if(a[i]==1)
                while(x%i==0){
                        x/=i; 
                        k++; 
                }
                r*=k;
        }
        if(x!=1)
                r*=2;
        return r;
}

int main()
{
    unsigned long long x, n, n1, i;
	char *a = sieve(1000000);
	x = 2; n=2; n1=3;
	while(x<3000){
		n++; n1++;
		if(n%2==0)
		x = d(n1,a)*d(n/2,a);
		else
		x = d(n1/2,a)*d(n,a);
	}
	printf("%llu\n",((n+1)*n)/2);
	free(a);
	return 0;
}
