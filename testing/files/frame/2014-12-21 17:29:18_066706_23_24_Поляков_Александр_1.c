#include <stdio.h>

void bord(int a);

int main(int argc, char **argv)
{
    int height, width, length, i = 0;
    char *text;

    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 1;
    }

    height = atoi(argv[1]);
    width = atoi(argv[2]);
    text = argv[3];
    length = strlen(text);

    if (height < 3 || length > width - 2)
    {
        printf("Error\n");
        return 1;
    }
    bord(width);

    for (i = 0; i < height - 2; i++)
        printf("*%*s%*s*\n", (width - length - 2) / 2 + length, i == (height - height / 2) - 2 ? text : "", width - (width - length - 2) / 2 - length - 2, "");
    bord(width);
    return 0;
}
void bord(int a){while (a-- > 0){printf("*");}printf("\n");}