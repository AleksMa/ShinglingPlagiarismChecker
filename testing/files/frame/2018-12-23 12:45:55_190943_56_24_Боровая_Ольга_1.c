#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_frame(int height, int width, char *text) {
    if (height < 3 || width < strlen(text) + 2) {
        printf("Error");
        return;
    }

    for (int i = 0; i < width; i++)
        printf("*");
    printf("\n");
    for (int i = 1; i < (height - 1) / 2; i++)
        printf("*%*s", width, "*\n");

    printf("*%*s%*s", (width - 2 + strlen(text)) / 2, text, (width + 2 + (width + strlen(text)) % 2 - strlen(text)) / 2, "*\n");

    for (int i = 1; i < height / 2; i++)
        printf("*%*s", width, "*\n");
    for (int i = 0; i < width; i++)
        printf("*");
};

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }

    int height = atoi(argv[1]), width = atoi(argv[2]);
    char *text = argv[3];

    make_frame(height, width, text);

    return 0;
};

