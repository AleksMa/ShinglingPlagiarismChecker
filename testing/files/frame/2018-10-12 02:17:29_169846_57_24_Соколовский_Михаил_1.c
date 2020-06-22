#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
        int width, height;
	//printf("%i\n", argc);
	if (argc != 4) {
		printf("Usage: frame <height> <width> <text>\n");
		return -1;
	}
	height = atoi(argv[1]);
	if (height < 3) {
		printf("Error");
		return -1;
	}
	width = atoi(argv[2]);
	if (width < strlen(argv[3]) + 2) {
		printf("Error");
		return -1;
	}
	for (int i = 0; i < width; ++i)
		printf("*");
	printf("\n");
	for (int i = 2; i < height / 2.f; ++i) {
		printf("*");
		for (int j = 1; j < width - 1; ++j)
			printf(" ");
		printf("*\n");
	}
	printf("*");
	for (int i = 1; i < (width - strlen(argv[3])) / 2; ++i)
		printf(" ");
	printf("%s", argv[3]);
	for (int i = 0; i < (width - strlen(argv[3])) / 2.f - 1; ++i)
		printf(" ");
	printf("*\n");
	for (int i = 1; i < height / 2; ++i) {
		printf("*");
		for (int j = 1; j < width - 1; ++j)
			printf(" ");
		printf("*\n");
	}
	for (int i = 0; i < width; ++i)
		printf("*");
	printf("\n");
	return 0;
}