#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
        if (argc == 4) {
		unsigned int height = atoi(argv[1]), width = atoi(argv[2]), l = strlen(argv[3]), i, j;
		if (width - 1 > l && height > 2) {
			for (i = 0; i < width; i++) printf("*");
			for (i = height - 2; i > 0; i--) {
				printf("\n*");
				if (i == height / 2) {
					for (j = (width - 2 - l) / 2; j > 0; j--) printf(" ");
					printf(argv[3]);
					for (j = (width - 2 - l) / 2 + ((width - l) % 2); j > 0; j--) printf(" ");
				} else {
					for (j = width - 2; j > 0; j--) printf(" ");
				}
				printf("*");
			}
			printf("\n");
			for (i = 0; i < width; i++) printf("*");
		} else {
			printf("Error");
		}
	} else {
		printf("Usage: frame <height> <width> <text>");
	}
	return 0;
}