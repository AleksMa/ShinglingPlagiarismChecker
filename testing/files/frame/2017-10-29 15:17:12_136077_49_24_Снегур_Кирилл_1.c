#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int height, width, textlength;
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    height = atoi(argv[1]);
    width = atoi(argv[2]);
    textlength = strlen(argv[3]);
    if ((textlength > width - 2) || (height < 3)) {
        printf("Error");
        return 0;
    }
    int centerheigth;
    if (height % 2 == 0) centerheigth = height / 2;
    else centerheigth = (height + 1) / 2;
    int centerweigth;
    int temp = (width - textlength - 2);
    if (temp % 2 == 0) centerweigth = temp / 2;
    else centerweigth = (temp - 1) / 2;
    for (int i = 1; i <= height; i++){
        if ((i == 1) || (i == height)) {
            for (int k = 0; k < width; k++) {
                printf("*");
            }
            printf("\n");
            continue;
        }
        if (i == centerheigth) {
            printf("*");
            for (int k = 0; k < centerweigth; k++) {
                printf(" ");
            }
            printf("%s", argv[3]);
            for (int k = 2 + centerweigth + textlength; k < width; k++) {
                printf(" ");
            }
            printf("*\n");
            continue;
        }
        for (int k = 0; k < width; k++) {
            if ((k == 0) || (k == width - 1)) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}