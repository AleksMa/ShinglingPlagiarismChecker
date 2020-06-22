#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PutCharN(char ch, int n)
{
    for (int i = 0; i < n; i++)
        putchar(ch);
}

void PrintFrame(int height, int width, char *s)
{
    int len = strlen(s);
    int rowWord = (height / 2);
    if (height & 1)//проверяем четное или нет
        rowWord += 1;
    
    int numSpaces1 = (width - len - 2) / 2;
    int numSpaces2 = (width - len - 2 - numSpaces1);
    
    if ((height) < 3 || (width < (len + 2)))
    {
        printf("Error");
        return;
    }

    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            if ((i == 1) || (i == height))
            {
                putchar('*');
                continue;
            }

            if (i == rowWord)
            {
                putchar('*');
                PutCharN(' ', numSpaces1);
                printf("%s", s);
                PutCharN(' ', numSpaces2);
                putchar('*');
                break;
            }

            if ((j == 1) || (j == width))
                putchar('*');
            else
                putchar(' ');
        }

        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    

    /*argv[0] = "6";
    argv[1] = "20";
    argv[2] = "Abracadabra";*/

    PrintFrame(atoi(argv[1]), atoi(argv[2]), argv[3]);
    
    return 0;
}