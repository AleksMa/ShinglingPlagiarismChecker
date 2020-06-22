#include <stdio.h>
#include <stdlib.h>
long long int gorner (int n, int x, int *mas){//long long - для контроля над переполнением
        long long int b = mas[n];
	int i;
	for (i = n - 1; i >= 0; --i){
			b = x * b + mas[i];
		}

		return b;
}

long long int derivative(int n, int x, int *mas){
	long long int b = n * mas[n];
	n -= 1;
	int i;
	for (i = n - 1; i >= 0; --i){
			b = x * b + (i + 1) * mas[i+1];
		}
		return b;
}



int main(int argc, char **argv){
	int n = 0;
	int x = 0;
	scanf("%d", &n);
	scanf("%d", &x);
	int *mas = (int*) malloc ((n+1)* sizeof(int));//int mas[n + 1];
	int i;
	for (i = n; i >= 0; --i){
		scanf("%d", &mas[i]);
	}

	printf("%lld\n", gorner(n, x, mas));



	printf("%lld\n", derivative(n, x, mas));

	free(mas);

	
	return 0;	
}
