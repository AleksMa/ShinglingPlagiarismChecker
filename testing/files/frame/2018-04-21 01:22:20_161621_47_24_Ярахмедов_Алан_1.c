#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }

    int height = atoi(argv[1]), width = atoi(argv[2]);
    char *string = argv[3];

    if ((strlen(string) > width - 2) || (height < 3)) {
        printf("Error");
        return 0;
    }

    for (int i = 0; i < width; i++) {
        printf("*");
    }
    printf("\n");

    for (int i = 0; i < height - 2; i++) {
        printf("*");
        if (i == ((height / 2) - 2 + (height % 2))) {
            int r = width - 2 - strlen(string);
            for (int j = 0; j < (r / 2); j++) {
                printf(" ");
            }
            printf("%s", string);
            for (int j = 0; j < (r - (r / 2)); j++) {
                printf(" ");
            }
        } else {
            for (int j = 0; j < width - 2; j++) {
                printf(" ");
            }
        }
        printf("*\n");
    }
    for (int i = 0; i < width; i++) {
        printf("*");
    }

}