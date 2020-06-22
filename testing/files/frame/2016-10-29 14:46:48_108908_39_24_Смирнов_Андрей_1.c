#include <stdio.h>
#include <stdlib.h>

void toast(int height, int width, char*text)
{
    void prt()
    {
        int x, y;
        for (y=0; y<height; y++)
            for (x=0; x<width; x++)
            {
                if (x==0)
                {
                    printf("*");
                    continue;
                }
                if (x==width-1)
                {
                    printf("*\n");
                    continue;
                }

                if (y==(height-1)/2 && (width-strlen(text))/2==x)
                {
                    printf("%s", text);
                    x=x+strlen(text)-1;
                    continue;
                }
                if (y==0 || y==height-1)
                    printf("*");
                else
                    printf(" ");

            }
    }

    if (height>2 && width-2>=strlen(text))
    {
        prt();
    }
    else printf("Error");
}

int main(int n, char* args[])
{
    if (n!=4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    toast(atoi(args[1]), atoi(args[2]), args[3]);
    return 0;
}
