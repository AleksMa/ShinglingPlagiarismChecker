#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void panic (int mode) {
    switch (mode) {
        case 0:
            printf("Usage: frame <height> <width> <text>\n");
            break;
        case 1:
            printf("Error\n");
            break;
    }
    exit(1);
}

void print_stars (size_t n) {
    int i;
    for (i = 0; i < n; i++) printf("*");
    printf("\n");
}

int main (int argc, char **argv) {

    if (argc != 4)
        panic(0);

    const size_t width = atoi(argv[2]);
    const size_t height = atoi(argv[1]);
    const char *text = argv[3];
    const size_t length = strlen(text);
    int i, j;

    if (height < 3 || length > width-2)
        panic(1);

    print_stars(width);

    for (i = 2; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (!j || j == width-1)
                printf("*");
            else printf(" ");
            if ((i == (height - 1) / 2 + 1) && (j == ((width - length) / 2 - 1))) {
                printf("%s", text);
                j+=length;
            }
        }
        printf("\n");
    }
    print_stars(width);

    return 0;
}