#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    int height = atoi(argv[1]);
    int width = atoi(argv[2]);
    char *t = argv[3];
    int h2 = height / 2;

    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 1;
    }

    if ((width < strlen(t) + 2) || ((height) < 3)) {
        printf("Error\n");
        return 1;
    }
    for (int i = 0; i < width; i++) {
        printf("*");
    }

    if (height % 2 == 0) h2--;
    printf("\n");
    for (int i = 1; i < h2; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }

    int flag = 0;
    for (int i = 0; i <= width; i++) {
        int space = width - strlen(t);
        if (i == 0 || i == width) printf("*");
        else {
            if (flag == 0) {
                for (int j = 0; j < space / 2 - 1; j++) {
                    printf(" ");
                }
                printf("%s", t);
                if ((width - strlen(t)) % 2 == 0) space--;
                for (int j = 0; j < space / 2; j++) {
                    printf(" ");
                }
                flag = 1;
            }
        }
    }
    printf("\n");
    if (height % 2 != 0) h2--;
    if (height > 3) {
        for (int i = 0; i < h2; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0 || j == width - 1) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }

    for (int i = 0; i < width; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}