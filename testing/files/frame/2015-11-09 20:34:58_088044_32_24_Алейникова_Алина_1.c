#include <stdio.h>
#include <stdlib.h>

void frame(int height, int width, char* text, int text_len);

int main(int argc, char** args) {
    if(argc != 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }

    int height = atoi(args[1]);
    int width = atoi(args[2]);
    char* text = args[3];
    int text_len = (int)strlen(text);

    if(width - 2 >= text_len && height > 2)
        frame(height, width, text, text_len);
    else {
        printf("Error");
        return 0;
    }
}

void frame(int height, int width, char* text, int text_len) {
    int i,j;
    int text_pos_height = height % 2 == 0 ? height / 2 - 1 : height / 2;
    int text_pos_width = (width - text_len) / 2;

    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            if(i == text_pos_height && j == text_pos_width) {
                printf("%s", text);
                j += text_len;
            }

            if(i == 0 || i == height - 1 || j == 0 || j == width - 1) printf("%c", '*');
            else printf("%c", ' ');
            }

        printf("%c", '\n');
    }
}
