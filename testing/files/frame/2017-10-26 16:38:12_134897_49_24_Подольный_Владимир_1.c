#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int a = atoi(argv[1]), b = atoi(argv[2]), k;
    char* chr = argv[3];
    int n = strlen(chr);
    if ((n <= b - 2) && (a > 2))
    {
        for (int i = 0; i < b; i++)
            printf("*");
            printf("\n");
    	if (a % 2 == 1)
    	for (k = 0; k < a/2 - 1; k++)
    	{
        	printf("*");
        	for (int j = 0; j < b - 2; j++)
            	printf(" ");
        	printf("*");
        	printf("\n");
    	}
    	else for (k=0; k < a/2 - 2; k++)
    	{
        	printf("*");
        	for (int j = 0; j < b - 2; j++)
            	printf(" ");
        	printf("*");
        	printf("\n");
    	}
    	printf("*");
    	int m;
    	m = (b - n) / 2;
    	for (int i = 0; i < m - 1; i++)
        	printf(" ");
    	printf("%s", chr);
    	m = b - n - m;
    	for (int i = 0; i < m - 1; i++)
        	printf(" ");
    	printf("*");
    	printf("\n");
    	int c;
    	c = a - k;
    	for (k=0; k < c-3; k++) {
        	printf("*");
    		for (int j = 0; j < b - 2; j++)
        		printf(" ");
    		printf("*");
    		printf("\n");
    	}
    	for (int i = 0; i < b; i++)
        	printf("*");
    }
    else printf("Error");

    return 0;
}