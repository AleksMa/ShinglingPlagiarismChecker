#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i, width, height, mid, j;
    height = atoi(argv[1]);
    width = atoi(argv[2]);
    mid = (height-1)/2;
    char *text;
    text = argv[3];
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    if ((strlen(text) > width-2) || (height < 3))
    {
        printf("Error\n");
        return 0;
    }
    for(i = 0; i < width; ++i)
    {
        printf("*");
    }
    printf("\n");
    for(i = 0; i < mid-1; ++i)
    {
        printf("*");
        for(j = 1; j <= width-2; ++j)
        {
            printf(" ");
        }
        printf("*\n");
    }
    printf("*");
    for(i = 0; i < (width-strlen(text))/2-1; ++i)
    {
        printf(" ");
    }
    printf("%s", text);
    for(i = ((width-strlen(text))/2-1)+strlen(text); i < width-2; ++i)
    {
        printf(" ");
    }
    printf("*\n");
    for(i = mid; i < height-2; ++i)
    {
        printf("*");
        for(j = 1; j <= width-2; ++j)
        {
            printf(" ");
        }
        printf("*\n");
    }
    for(i = 0; i < width; ++i)
    {
        printf("*");
    }
    printf("\n");
    return 0;
}