
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        if (argc != 4) {
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	int h = atoi(argv[1]);
	int w = atoi(argv[2]);
	if (((w - 2 - (int)strlen(argv[3])) < 0) || (h <= 2)) {
		printf("Error");
		return 0;
	}
	int centerh = (h % 2 == 0) ? (h / 2 - 1) : (h / 2);
	int k = (w - 2 - (int)strlen(argv[3]));
	int cw, cww;
	if (k % 2 == 0) {
		cw = k / 2;
		cww = k / 2;
	}
	else {
		cw = k / 2;
		cww = k / 2 + 1;
	}
	for (int i = 0; i < h; ++i) {
		if ((i == 0) || (i == (h - 1))) {
			for (int j = 0; j < w; ++j)
				printf("*");
			printf("\n");
		}
		else if (i == centerh) {
			printf("*");
			for (int j = 0; j < cw; ++j)
				printf(" ");
			printf("%s", argv[3]);
			for (int j = 0; j < cww; ++j)
				printf(" ");
			printf("*\n");
		}
		else {
			printf("*");
			for (int j = 1; j < (w - 1); ++j)
				printf(" ");
			printf("*\n");
		}
	}
}
