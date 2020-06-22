#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
        if (argc != 4){
        	printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	int x = atoi(argv[2]);
	int y = atoi(argv[1]);

	if (x - 2 < strlen(argv[3]) || y < 3){
		printf("Error\n");
		return 0;
	}
	int n = (x - strlen(argv[3]) - 2) / 2;
	int m = (y - 1) / 2;
	for (int j = 0; j < y - 1; j++){
		printf("*");
		for (int i = 0; i < x - 2; i++){
			if (j == 0) printf("*");
			else if (i == n && j == m){
				printf("%s", argv[3]);
				i = i + strlen(argv[3]) - 1;
			}
			else printf(" ");
		}
		printf("*\n");
	}
	
	for (int i = 0; i < x; i++) printf("*");
	
	return 0;
}