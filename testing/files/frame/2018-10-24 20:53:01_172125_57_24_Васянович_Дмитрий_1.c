#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int args, char **argv)
{
        if (args != 4) {
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	int h = atoi(argv[1]);
	int w = atoi(argv[2]);
	if (((strlen(argv[3])) > w - 2) || (h < 3)) {
	    printf("Error\n");
	    return 0;
	}
	int x = (h - 1) / 2;
	int i, j;
	for (i = 0; i < h; i++) {
	    if ((i == 0) || (i == h - 1)) {
            for (j = 0; j < w; j++) {
                if (j != w - 1) printf("*");
                else printf("*\n");
            }
        }
        else {
            if (i == x) {
                int left;
                if (((w % 2 == 0) && ((int)(strlen(argv[3]))) % 2 == 1) || (((w % 2 == 1) && ((int)(strlen(argv[3]))) % 2 == 0))) (left = (w - 1 - (int)(strlen(argv[3]))) / 2);
                if (((w % 2 == 0) && ((int)(strlen(argv[3]))) % 2 == 0) || (((w % 2 == 1) && ((int)(strlen(argv[3]))) % 2 == 1))) (left = (w - (int)(strlen(argv[3]))) / 2);
                if (left == 0) (left = 1);
                int right = left + (int)(strlen(argv[3])) - 1;
                for (j = 0; j < w; j++) {
                    if (j == 0) printf("*");
                    else {
                        if (j == w - 1) printf("*\n");
                        else {
                            if (j >= left && j <= right) printf("%c", argv[3][j - left]);
                            else printf(" ");
                        }
                    }
                }
            }
            else {
                for (j = 0; j < w; j++) {
                    if (j == 0) printf("*");
                    if (j == w - 1) printf("*\n");
                    if (j >= 1 && j <= w - 2) printf(" ");
                }
            }
        }
	}
	return 0;
}
