#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf ("Usage: frame <height> <width> <text>");
        return 0;
    }
    int l = 0;
    int h = atoi (argv [1]);
    int w = atoi (argv [2]);

    char * s = argv [3];
    int len = strlen (s);
    if ((len > w - 2) || (h < 3))
    {
        printf("Error");
        return 0;
    }

    int i = 0, k = 0;
    if (len == 1) l = 1;
    for (i = 0; i < w; i++) printf("*");

    for (i = 0; i < (h / 2) - 2 + (h % 2) ; i++)
    {
        printf("\n");
        printf("*");
        for (k = 0; k < w - 2; k++) printf (" ");
        printf("*");
    }
    printf ("\n");
    printf ("*");
    for(i = 0; i < (w - len) / 2 - 1; i++) printf (" ");
    printf ("%s", s);
    for(i = 0; i < (w - len) / 2  + (len % 2) - (1 - (w % 2) ) - 2 * l ; i++) printf (" ");
    printf ("*");

    for (i = 0; i < (h / 2) - 1; i++)
    {
        printf("\n");
        printf("*");
        for (k = 0; k < w - 2; k++) printf (" ");
        printf("*");
    }
    printf ("\n");
    for (i = 0; i < w; i++) printf("*");

return 0;
}