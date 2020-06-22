
#include <stdio.h>
#include <string.h>
int main(int argc,  char * argv[])
{
    int tmp = 0;
    char *str, *e;
    int i = 0, j = 0;
    long width, height, dlina, p, q;
    if (argc < 4)
        printf ("usage: frame <height> <width> <text>\n");
    else
    {
        height = strtol(argv[1], &e,10);
        width = strtol(argv[2], &e,10);
        dlina = strlen (argv[3]);
        if (width < dlina || height < 3 || (dlina + 2) > width)
            printf ("Error");
        else
        {
            if (height % 2 ==  0)
                q=(height - 2) / 2;
            else
                q=((height - 2) / 2) + 1;
            for (i = 0; i < width; i++)
                printf ("*");
            printf ("\n");
            for (j = 1; j < height - 1; j++)
            {
                if (j != q)
                {
                    for (i = 0; i < width; i++)
                        if (i == 0 || i == (width - 1))
                            printf ("*");
                        else
                            printf (" ");
                }
                else
                {
                    printf ("*");
                    p=((width - dlina - 2) / 2) + 1;
                    while (p / 2 != 0)
                    {
                        printf (" ");
                        p--;
                    }
                    printf ("%s", argv[3]);
                    p=((width - dlina - 2) / 2) + 1;
                    if ((width - dlina) % 2 == 0)
                        p=((width - dlina - 2) / 2);
                    else
                        p=((width - dlina - 2) / 2) + 1;
                    while (p != 0)
                    {
                        printf (" ");
                        p--;
                    }
                    printf ("*");
                }
                printf ("\n");
            }
            for (i = 0; i < width; i++)
                printf ("*");
        }
        printf ("\n");
    }
    return 0;
}