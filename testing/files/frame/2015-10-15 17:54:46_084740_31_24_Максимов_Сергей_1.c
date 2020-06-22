#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        if (argc != 4) {
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	if ((atoi(*(argv + 1)) < 3) || ((atoi(*(argv + 2)) - 2) < strlen(*(argv + 3)))) { 
		printf("Error\n");
		return 0;
	}
	int x, y, stry, strx;
	if (atoi(*(argv + 1)) % 2) stry = (atoi(*(argv + 1))) / 2 + 1;
	else stry = atoi(*(argv + 1)) / 2;
	
	if ((atoi(*(argv + 2)) - strlen(*(argv + 3))) % 2) {
		strx = (atoi(*(argv + 2)) - strlen(*(argv + 3)))/ 2 + 1;
	} else strx = (atoi(*(argv + 2)) - strlen(*(argv + 3))) / 2 + 1; 
	
	for (y = 1; y <= atoi(*(argv + 1)); y++) {
		for (x = 1; x <= atoi(*(argv + 2)); x++) {
			if ((y == 1) || (y ==atoi(*(argv + 1))) || (x == 1) || (x == atoi(*(argv + 2)))) {
				printf("*");
				if (x == atoi(*(argv + 2))) printf("\n");
				continue;
			}
			if ((x == strx) && (y == stry)) {
				printf("%s", *(argv + 3));
				x += strlen(*(argv + 3)) - 1;
				continue;
			}
			printf(" ");
		}
	}
	return 0;
}