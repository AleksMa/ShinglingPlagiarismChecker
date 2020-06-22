#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void line_1(int width)
{
    for (int i = 0; i < width; i++) printf("*");
    printf("\n");
}

void line_2(int width)
{
    printf("*");
    for (int i = 1; i < width - 1; i++) printf(" ");
    printf("*\n");
}

void line_3(int width, char *text)
{
    size_t len = strlen(text);
    size_t spaces = (width - len - 2) / 2;

    printf("*");
    for (size_t i = 0; i < spaces; i++) printf(" ");

    printf("%s", text);

    for (size_t i = 1 + spaces + len; i < width - 1; i++) printf(" ");
    printf("*\n");
}

void enframe(int height, int width, char *text)
{
    line_1(width);
    
    for (int i = 1; i < (height - 1) / 2; i++) line_2(width);

    line_3(width, text);

    for (int i = (height - 1) / 2 + 2; i < height; i++) line_2(width);

    line_1(width);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }

    else
    {
        int height = atoi(argv[1]);
        int width = atoi(argv[2]);
        char *text = argv[3];

        if (height < 3 || width < strlen(text) + 2) printf("Error\n");
                else enframe(height, width, text);
    }

    return 0;
}