#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
        
	if (argc < 4) printf("Usage: frame <height> <width> <text>\n");
	else {
		int h = atoi(argv[1]), w = atoi(argv[2]);
		if ((h < 3) || (w < strlen(argv[3]) + 2)) printf("Error\n");
		else {
			for (int i = 0; i < w; i++) printf("*");
			printf("\n");
			for (int i = 1; i < h - 1; i++) {
				if (i != h/2 - (h - 1)%2) {
					printf("*");
					for (int j = 0; j < w - 2; j++) printf(" ");
					printf("*");
				}
				else {
					printf("*");
					for (int j = 0; j < (w - 2 - strlen(argv[3]))/2; j++) printf(" ");
					printf("%s", argv[3]);
					for (int j = 0; j < (w - 2 - strlen(argv[3]))/2 + (w - 2 - strlen(argv[3]))%2; j++) printf(" ");
					printf("*");
				}
				printf("\n");
			}
			for (int i = 0; i < w; i++) printf("*");
			printf("\n");
		}
	}
}