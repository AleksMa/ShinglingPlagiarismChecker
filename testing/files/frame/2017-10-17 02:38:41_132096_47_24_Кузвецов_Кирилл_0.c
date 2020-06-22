#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
        int x, y, k, right, left, up, down, i, m;
        char* stroka;
          if (argc != 4)
        {
            printf("Usage: frame <height> <width> <text>\n");
            return 0;
        }
        x = atoi(argv[1]);
        y = atoi(argv[2]);
        stroka = argv[3];
        if (((strlen (stroka)) >= (y - 1)) || (x < 3))
        {
            printf("Error");
        }
        else
        {
            k = y - strlen (stroka);
            if (k % 2 == 0)
            {
                right = (k / 2) - 1;
                left = (k / 2) - 1;
            }
            else
            {
                left = ((k - 1) / 2) - 1;
                right = (left + 1);
            }
            if (x % 2 == 0)
            {
                up = (x / 2) - 2;
                down = (x / 2) - 1;
            }
            else
            {
                up = ((x - 1) / 2) - 1;
                down = ((x - 1) / 2) - 1;
            }
            for (i = 0; (i < y); i++)
            {
                printf("*");
            }
            printf("\n");
            for (i = 0; (i < up); i++)
            {
                printf("*");
                for (m = 0; (m < (y - 2)); m++)
                {
                    printf(" ");
                }
                printf("*\n");
            }
            printf("*");
            for (i = 0; (i < left); i++)
            {
                printf(" ");
            }
            printf("%s", stroka);
            for (i = 0; (i < right); i++)
            {
                printf(" ");
            }
            printf("*\n");
             for (i = 0; (i < down); i++)
            {
                printf("*");
                for (m = 0; (m < (y - 2)); m++)
                {
                    printf(" ");
                }
                printf("*\n");
            }
            for (i = 0; (i < y); i++)
            {
                printf("*");
            }
        }
return 0;
}
