#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
        if (argc != 4) {
		printf("Usage: frame <height> <width> <text>");
		return 0; }
	char word[100];
	int wLen = strlen(argv[3]);
	strncpy(word, argv[3], wLen + 1);
	int height = atoi(argv[1]), width = atoi(argv[2]), i, j;
	if (height < 3 || width < wLen + 2) {
		printf("Error");
		return 0; }
	int spL = (width - wLen - 2) / 2, spR = width - wLen - 2 - spL;
	for (i = 0; i < height; i++) {
		if (i == 0 || i == (height - 1))
			for (j = 0; j < width; j++)
				printf("*");
		else if (i == ((height - 1) / 2)) {
			printf("*");
			for (j = 0; j < spL; j++)
				printf(" ");
			printf("%s", word);
			for (j = 0; j < spR; j++)
				printf(" ");
			printf("*"); }
		else
			for (j = 0; j < width; j++)
				if (j == 0 || j == (width - 1))
					printf("*");
				else
					printf(" ");
		printf("\n"); }
	return 0; }