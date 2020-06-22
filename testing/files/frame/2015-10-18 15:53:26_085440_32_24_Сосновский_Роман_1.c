#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_SYMBOL(a) printf("%c", a)
#define PRINT_STRING(a) printf("%s", a)

void print_help() {
    printf("Usage: frame <height> <width> <text>");
}

void print_error() {
    printf("Error");
}

void print_frame(int height,
                 int width,
                 char* text, int text_len) {
    int text_pos_height = height % 2 == 0 ? height / 2 - 1 : height / 2;
    int text_pos_width = (width - text_len) / 2;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(i == text_pos_height && j == text_pos_width) {
                PRINT_STRING(text);
                j = j + text_len;
            }

            // Печатем рамочку
            if(i == 0 || i == height - 1 ||
               j == 0 || j == width - 1) {
                PRINT_SYMBOL('*');
            } else {
                PRINT_SYMBOL(' ');
            }
        }
        PRINT_SYMBOL('\n');
    }
}

int main(int argc, char** args) {
    if(argc != 4) {
        // Проблемы количеством аргументов =>
        // => печатаем help
        print_help();
        return 0;
    }

    int height = atoi(args[1]);
    int width = atoi(args[2]);
    char* text = args[3];
    int text_len = (int)strlen(text);

    if(width - 2 >= text_len && height > 2) {
        print_frame(height, width, text, text_len);
    } else {
        // Строчка не влезает по ширине и высоте
        print_error();
        return 0;
    }
}