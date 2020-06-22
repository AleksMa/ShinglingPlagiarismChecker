#include <stdio.h>
#include <string.h>
#include <stdlib.h>        

int main(int argc, char **argv)
{
	if(argc != 4) { 
		printf("Usage: frame <height> <width> <text>\n"); 
		return 1; 
	}
    int a, b, c , m = 0;
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	if(a % 2 == 0)	c = a / 2;
	else	c = a / 2 + 1;
	if((strlen(argv[3])+2) > b || a < 3)	printf("Error");
	else {
		for(int i = 0; i < b; i++) {
			printf("*");
		}
		for(int i = 2; i < a; i++) {
			printf("\n");
			if(i == c) {
				printf("*");
				for(int i = 0; i < ((b - strlen(argv[3]) - 2) / 2); i++) {
					printf(" ");
					m++;
				}
				printf("%s", argv[3]);
				for(int i = 0; i < (b - m - strlen(argv[3]) - 2); i++) {
					printf(" ");
				}
				printf("*");
			}
			else {
				printf("*");
				for(int j = 0; j < (b - 2); j++) {
					printf(" ");
				}
				printf("*");
			}
		}
		printf("\n");
		for(int i = 0; i < b; i++) {
			printf("*");
		}
	}
	return 0;
}


