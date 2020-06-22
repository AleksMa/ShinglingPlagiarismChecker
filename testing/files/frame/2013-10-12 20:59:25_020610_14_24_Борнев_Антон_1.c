#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }

    int height,width;
    char *text;
    int len = 0;

    sscanf(argv[1],"%i",&height);
    sscanf(argv[2],"%i",&width);
    text = argv[3];
    len = strlen(text);

    if (width < len+2 || height < 3)
    {
        printf("Error");
        return 0;
    }

    int show = (height+1)/ 2 - 1;
    int skip = (width-len)/2;
    int i,j;
    for (i = 0; i < width; i++)
    {
        printf("*");
    }
    printf("\n");
    for (j = 1; j < height-1; j++)
    {
        printf("*");
        for (i = 1; i < width-1; i++)
        {
            if (j == show && skip == i)
            {
                printf("%s",text);
                i+=len-1;
            }
            else
            {
                printf(" ");
            }
        }
        printf("*\n");
    }

    for (i = 0; i < width; i++)
    {
        printf("*");
    }
    printf("\n");
    return 0;
}