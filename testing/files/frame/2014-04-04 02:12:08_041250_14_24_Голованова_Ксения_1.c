#include <stdio.h>

int main(int argc,char **argv)
{
    if (argc >= 4) {
        int k,l,i,j;
        k = atoi(argv[1]);
        l = atoi(argv[2]);
        char *s = argv[3];
        if (((l-2) < strlen(s)) || (k < 3)) {
            printf("Error");
            return 0;
        }
        for (i = 0; i < l; i++)
            printf("*");
        printf("\n");
        for (i = 1; i <= k-2; i++) {
            printf("*");
            if ((int)((k-1)/2) == i) {
                for (j = 1; j<= (int)((l-2-strlen(s))/2); j++)
                    printf(" ");
                printf("%s",s);

                for (j = 1; j <= (l-2-strlen(s))-(int)((l-2-strlen(s))/2); j++)
                    printf(" ");
            }
            else
                for (j = 1; j <= l-2; j++)
                    printf(" ");
            printf("*\n");
        }
        for (i = 0; i < l; i++)
            printf("*");
    }
    else
        printf("Usage: frame <height> <width> <text>");
    return 0;
}