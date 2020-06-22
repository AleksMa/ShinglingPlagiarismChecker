#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw_frame(int height, int width, char *text) {
    int text_length = strlen(text);
    if ((width < (text_length + 2)) || (height < 3)) {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    
    int mid_height = height - (height / 2);
    int indent = ((width - 2) - text_length) / 2;
    
    for (int i = 1; i <= height; i++) {
        for (int j = width, k = 0; j > 0; j--) {
            if ((i == height) || (i == 1)) {
                if (j == 1)
                    printf("*\n");
                else
                    printf("*");
            }
            else if (i != mid_height) {
                if (j == width)
                    printf("*");
                else if (j == 1)
                    printf("*\n");
                else
                    printf(" ");
            }
            else if (i == mid_height) {
                if (j == width)
                    printf("*");
                else if (j == 1)
                    printf("*\n");
                else if ((j <= width - (indent + 1)) && (j > ((width - (indent + 1))) - text_length)) {
                    printf("%c",text[k++]);
                }
                else
                    printf(" ");
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>\n");
        exit(EXIT_FAILURE);
    }
    
    draw_frame(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10), argv[3]);
    return 0;
}
