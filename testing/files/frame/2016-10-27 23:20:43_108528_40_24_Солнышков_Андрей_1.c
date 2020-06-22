#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void draw(int a, int b, const char* swrite, int length);

int main(int argc, const char * argv[])
{
    if(argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }

    int a = atoi(argv[1]), b = atoi(argv[2]), length = 0;
    while(argv[3][length] != '\0') length++;
    draw(a, b, argv[3], length);
}

void draw(int a, int b, const char* swrite, int length)
{
    if ((b < length + 2) || (a < 3)) printf("Error");
    else
    {
        for (int i = 0; i < a; i++)
        {
            printf("*");
            if ((i == 0) || (i == a - 1))
            {
                for (int j = 1; j < b - 1; j++)
                {
                    printf("*");
                }
            } else if (i == (a - 2) / 2 + a % 2)
            {
                for (int j = 0; j < b - 2; j++)
                {
                    if ((j < (b - length) / 2 - 1) || (j >= (b - length) / 2 + length - 1))
                        printf(" ");
                    else printf("%c", swrite[j - (b - length) / 2 + 1]);
                }
            } else
            {
                for (int j = 1; j < b - 1; j++)
                {
                    printf(" ");
                }
            }
            printf("*\n");
        }
    }
}