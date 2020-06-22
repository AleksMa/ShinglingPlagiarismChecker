#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
        if (argc != 4) {
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	int height, width, len;
	len = strlen(argv[3]);
	height = atoi(argv[1]);
	width = atoi(argv[2]);
	if (((width - len) < 2) || (height < 3)){
		printf("Error");
		return 0;
	}
	int i, j, prob;
	for (i = 0; i < width; i++) {
		printf("*");
	}
        printf("\n");
	int stroka = (height + 1) / 2;
	for (i = 0; i < stroka - 2; i++) {
	printf("*");
		for (j = 0; j < width - 2; j++){
			printf(" ");
		}
	printf("*");
	printf("\n");
	}
	prob = (width - len) / 2 - 1;
        printf("*");
	for (i = 0; i < prob; i++){
		printf(" ");
	}
	printf("%s", argv[3]);
	prob = width - len - prob - 2;
	for (i = 0; i < prob; i++){
		printf(" ");
	}
	printf("*");
	printf("\n");
	for (i = stroka + 1; i < height; i++) {
	printf("*");
		for (j = 0; j < width - 2; j++){
			printf(" ");
		}
	printf("*");
	printf("\n");
	}
	for (i = 0; i < width; i++) {
		printf("*");
	}
        return 0;
}