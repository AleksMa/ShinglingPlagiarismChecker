#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
    int i, f, dlina, visota, l, k;
    char* mas = " ";
    if (argc != 4){
        printf ("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    visota = atoi(argv[1]);
    dlina = atoi(argv[2]);
    mas = argv[3];
    if ((dlina < strlen(mas) + 2) || (visota < 3))
        printf ("Error\n");
    else {
        for (i = 0; i < dlina; i++)
            printf("*");
        printf ("\n");
        if (visota % 2 == 0){
            f = visota / 2 - 2;
            k = visota - f - 3;
        }
        else {
            f = visota / 2 - 1;
            k = f;
        }
        for (i = 0; i < f; i++){
            printf ("*");
            for (l = 0; l < dlina - 2; l++)
                printf (" ");
            printf ("*\n");
        }
        printf ("*");
        for (i = 0; i < (dlina - 2 - strlen(mas))/2; i++)
            printf (" ");
        printf ("%s", mas);
        for (i = 0; i < (dlina - 2 - strlen(mas))/2; i++)
            printf (" ");
        if ((dlina - 2 - strlen(mas)) % 2 != 0)
                printf(" ");
        printf("*\n");
        for (i = 0; i < k; i++){
            printf ("*");
            for (l = 0; l < dlina - 2; l++)
                printf (" ");
            printf ("*\n");
        }

        for (i = 0; i < dlina; i++)
            printf("*");
    }
    return 0;
}

