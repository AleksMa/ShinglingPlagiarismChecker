#include <stdio.h>
#include <stdlib.h>

int main(){
        int n=0;
	int x0=0, k=0;
	int i = 0;
	long long P = 0, P1 = 0;
		scanf("%d %d",&n ,&x0);
	int *arr = malloc(sizeof(int)*(n+1));
	for(i = 0;i < n + 1;i++){
		scanf("%d",&k);
		arr[i] = k;
	}
	P=arr[0];
	for(i = 0;i < n;i++){
		P*=x0;
		P+=arr[i+1];
	}
	printf("%ld ",P);
	P1=0;
	for(i = 0;i < n;i++){
		P1*=x0;
		P1+=arr[i] * (n - i);
	}
	printf("%ld",P1);
	free(arr);
	return 0;
}