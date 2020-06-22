
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        int h, w, i, j, len;
        char *t;
        if (argc != 4) printf("Usage: frame <height> <width> <text>\n");
        else {
                h = atoi(argv[1]);
                w = atoi(argv[2]);
                t = argv[3];
                len = strlen(t);
                if ((len > w - 2) || (h < 3)) printf("Error\n");
                else {
                        for (i = 0; i < w; i++) printf("*");
                        printf("\n");
                        for (i = 1; i < (h - 1)/2; i++) {
                                printf("*");
                                for (j = 1; j < w - 1; j++) printf(" ");
                                printf("*\n");
                        }
                        printf("*");
                        for (j = 1; j < (w-len)/2; j++) printf(" ");
        		printf("%s", t);
			for (j = (w+len+2)/2; j < w; j++) printf(" ");
                        printf("*\n");
                        for (i = (h+1)/2; i < h - 1; i++) {
                                printf("*");
                                for (j = 1; j < w - 1; j++) printf(" ");
                                printf("*\n");
                        }
                        for (i = 0; i < w; i++) printf("*");
                        printf("\n");
                }
        }
	return 0;
}
