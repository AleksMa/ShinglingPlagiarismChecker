#include <stdio.h>
#include <string.h>
int main(int argc, char** argv) {
        int h, w, i, k;
	if (argc != 4)
		printf("Usage: frame <height> <width> <text>\n");
	else {
		h = atoi(argv[1]);
		w = atoi(argv[2]);
		if (strlen(argv[3]) > (w - 2) || h < 3)
			printf("Error\n");
		else {
			for (i = 1; i <= w; i++)
				printf("*");
			printf("\n");
			if ((h % 2) == 0) {
				for (i = 1; i < h / 2 - 1; i++) {
					printf("*");
					for (k = 0; k < w - 2; k++)
						printf(" ");
					printf("*\n");
				}
			} else {
				for (i = 1; i < h / 2; i++) {
					printf("*");
					for (k = 0; k < w - 2; k++)
						printf(" ");
					printf("*\n");
				}
			}
			printf("*");
			for (i = 1; i <= ((w - 2) - strlen(argv[3])) / 2; i++)
				printf(" ");
			printf("%s", argv[3]);
			for (i = 1; i <= ((w - 1) - strlen(argv[3])) / 2; i++)
				printf(" ");
			printf("*\n");
			for (i = 0; i < (h / 2) - 1; i++) {
				printf("*");
				for (k = 0; k < w - 2; k++)
					printf(" ");
				printf("*\n");
			}
			for (i = 1; i <= w; i++)
				printf("*");
			printf("\n");
		}
	}
}
