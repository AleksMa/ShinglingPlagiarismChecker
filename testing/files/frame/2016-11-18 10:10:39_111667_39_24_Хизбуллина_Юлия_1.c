#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) 
{
        if (argc != 4) {
        	printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
        
	int a, b, i, j, l;
	char s[255];
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	strcpy(s, argv[3]);
	l = strlen(s);
        
	if ((l > (b - 2)) || (a < 3)) {
		printf("Error\n");
		return 0;
	}
        
	for (i = 0; i < b; i++)
		printf("*");
	printf("\n");
        
	for (i = 0; i < ((a - 3) / 2); i++) {
		printf("*");
		for (j = 0; j < (b-2); j++);
			printf("%*c", b-2, ' ');
		printf("*\n");
	}
        
	printf("*");
		for (i = 0; i < ((b - l - 2)/2); i++)
		printf(" ");
	printf("%s", s);
	for (i = 0; i < ((b - l - 1)/2); i++)
		printf(" ");
	printf("*\n");
        
	for (i = 0; i < ((a - 2) / 2); i++) {
		printf("*");
		for (j = 0; j < (b-2); j++);
			printf("%*c", b-2, ' ');
		printf("*\n");
	}
        
	for (i = 0; i < b; i++)
		printf("*");
                
	return 0; 
}