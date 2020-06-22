#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
        if (argc != 4) {
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	int h = atoi(argv[1]);
	int w = atoi(argv[2]);
	if (((int)strlen(argv[3]) > w - 2) || (h < 3)) {
		printf("Error");
		return 0;
	}
	for (int i = 0; i < w; ++i) {
		printf("*");
	}
	printf("\n");
	for (int i = 1; i < (h - 1) / 2; ++i) {
		printf("*");
		for (int j = 1; j < (w - 1); ++j)
			printf(" ");
		printf("*\n");
	}
	printf("*");
	for (int i = 0; i < (w - 2 - (int)strlen(argv[3])) / 2; ++i)
		printf(" ");
	printf("%s", argv[3]);
	for (int i = 0; i < (w - (int)strlen(argv[3]) - 1) / 2; ++i)
		printf(" ");
	printf("*\n");
	for (int i = (h - 1) / 2; i < h - 2; ++i) {
		printf("*");
		for (int j = 1; j < (w - 1); ++j)
			printf(" ");
		printf("*\n");
	}
	for (int i = 0; i < w; ++i) {
		printf("*");
	}
	printf("\n");
	return 0;
}