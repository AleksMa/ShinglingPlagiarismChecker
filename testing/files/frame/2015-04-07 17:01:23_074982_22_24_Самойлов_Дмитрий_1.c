#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *word = argv[3];
    int a, b, i, j, len;
    if (argc!= 4)
        printf("Usage: frame <height> <width> <text>");
    else
    {
        b=atoi(argv[1]), a=atoi(argv[2]), len=strlen(word);
        if ((len>a-2)||(b<3))
            printf("Error");
        else
        {
            a=a-2;
            for (i=0;i<a+2;i++)
                putchar('*');
            printf("\n"); 
            for (i=0;i<b-2;i++)
            {
                putchar('*');
                if (i!=(((b-2)-1)/2))
                    for (j=0;j<a;j++)
                        putchar(' ');
                else
                {
                    for (j=0;j<(a-len)/2;j++)
                        putchar(' ');
                    printf("%s", word);
                    for (j=0;j<a-((a-len)/2)-len;j++)
                        putchar(' ');
                }
                putchar('*');
                printf("\n");
            }
            for (i=0;i<a+2;i++)
                putchar('*');
            printf("\n");
            
        }

    }
    return 0;
}