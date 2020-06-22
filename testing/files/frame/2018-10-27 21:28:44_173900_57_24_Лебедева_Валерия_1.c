#include <stdio.h>
#include <string.h>

int chartoint(char *s) {
    int sum=0;
    for (int i=0; s[i] != 0; i++)
        sum=sum*10+s[i]-'0';
    return sum;
}

int main(int argc, char **argv) {
    if (argc!=4)
        printf("Usage: frame <height> <width> <text>");
    else {
        int height = chartoint(argv[1]) - 2, width = chartoint(argv[2]);
        char *str = argv[3];
        if ((width < strlen(str) + 2) || (height<=0))
            printf("Error");
        else {
            for (int i = 1; i <= width; i++)
                printf("*");
            printf("\n");
            for (int j = 1; j < (height + 2 - 1) / 2; j++) {
                printf("*");
                for (int k = 1; k <= width - 2; k++)
                    printf(" ");
                printf("*\n");
            }
            printf("*");
            for (int r = 1; r <= (width - 2 - strlen(str)) / 2; r++)
                printf(" ");
            printf("%s", str);
            for (int y = 1; y <= width - 2 - strlen(str) - (width - 2 - strlen(str)) / 2; y++)
                printf(" ");
            printf("*\n"); //строчка с словом закончена
            for (int j = (height + 2 - 1) / 2; j < height; j++) {
                printf("*");
                for (int k = 1; k <= width - 2; k++)
                    printf(" ");
                printf("*\n");
            }
            for (int i = 1; i <= width; i++)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}