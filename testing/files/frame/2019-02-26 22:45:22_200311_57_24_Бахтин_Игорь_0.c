#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int count, char *argv[]) {
        if (count == 4) {
		long hei = atoi(argv[1]), wid = atoi(argv[2]), len = strlen(argv[3]);
		if (hei <= 2 || len + 1 >= wid) {
			printf("Error");
			return 0;
		}
		for (int j = 0; j < wid; j++) {
			printf("*");
		}
		for (int j = hei - 2; j > 0; j--) {
			printf("\n*");

			if (j == hei / 2) {

				for (int i = (wid - 2 - len) / 2; i > 0; i--) {
					printf(" ");
				}

				printf(argv[3]);

				for (int i = (wid - 2 - len) / 2 + ((wid - len) % 2); i > 0; i--) {
					printf(" ");
				}

			} else {

				for (int i = 1; i <= wid - 2; i++) {
					printf(" ");
				}

			}
			printf("*");

		}
		printf("\n");
		for (int i = 0; i < wid; i++) {
			printf("*");
		}
	} else printf("Usage: frame <height> <width> <text>");
	return 0;
}
