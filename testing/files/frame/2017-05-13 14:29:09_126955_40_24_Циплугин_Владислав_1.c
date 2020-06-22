#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void helper(int, int, int, char*);
int main(int argc, char **argv){
    if(argc < 4){
        	printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	if(atoi(argv[1]) < 3 || strlen(argv[3]) > (atoi(argv[2]) - 2)){
		printf("Error");
		return 0;
	}
	for(int i = 1; i <= atoi(argv[1]) ; i++)
		helper(i, atoi(argv[1]), atoi(argv[2]), (argv[3]));
	return 0;
}

void helper(int i, int a, int b, char *c){
	int left = (b - strlen(c) - 2)/2;
	int right = left;
	int middle = (a/2);
	if(a % 2 != 0)
		middle = a/2 + 1;
	if ((b - strlen(c) - 2) % 2 != 0)
		right = left + 1;
	if(i == 1 || i == a){
		for(int k = 0; k < b; k++) 
			printf("*");
		printf("\n");
		return;
	}
	if(i != middle){
		printf("*");
		for(int k = 1; k < b - 1; k++) 
			printf(" ");
		printf("*");
		printf("\n");
		return;
	}
	if (i == middle){
		printf("*");
		for(int k = 0; k < left; k++)
			printf(" ");
		printf("%s", c);
		for(int k = 0; k < right; k++)
			printf(" ");
		printf("*\n");
		return;
	}
}