#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
        if (argc < 4) {
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	int height = atoi(argv[1]), width = atoi(argv[2]), l = strlen(argv[3]), m = (height - 1) / 2;
	if ((height > 2) && (width > l + 1)) {
		for (int i = 0; i < width; i++) {
			printf("*");
			if (i == width - 1) printf("\n");
		}
		for (int i = 0; i < height - 2; i++) {
			printf("*");
			if (i+1 != m) {
				for (int j = 0; j < width - 2; j++) {
					printf(" ");
				}
				printf("*\n");
			}
			else {
				for (int j = 0; j < ((width - l) / 2) - 1; j++) {
					printf(" ");
				}
				printf("%s", argv[3]);
				for (int c = 0; c < ((width - l + 1) / 2) - 1; c++) {
					printf(" ");
				}
				printf("*\n");
			}
		}
		for (int i = 0; i < width; i++) {
			printf("*");
		}
	}
	else printf("Error\n");
	return 0;
}