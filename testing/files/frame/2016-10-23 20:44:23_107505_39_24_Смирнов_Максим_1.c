#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc < 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    char *text = argv[3];
    int width = strlen(text);

    if(a < 3 || b - 2 < width) {
        printf("Error");
        return 0;
    }

    int i, j,
        top = a % 2 ? a / 2 : (a - 1) / 2,
        left = (b - width) / 2;
    for(i = 0; i < a; i++) {
        for(j = 0; j < b; j++) {
            if(i == 0 || j == 0 || i == a-1 || j == b-1) putchar('*');
            else if(i != top || j < left || j >= left + width) putchar(' ');
            else putchar(text[j - left]);
        }
        putchar('\n');
    }

    return 0;
}