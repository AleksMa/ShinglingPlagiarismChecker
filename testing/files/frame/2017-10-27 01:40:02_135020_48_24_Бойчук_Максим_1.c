#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    char *s = argv[3];

    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>");
        printf("\n");
        return 0;
    }

    if ((strlen(argv[3]) > (m - 2)) || (n < 3)) {
        printf("Error");
        printf("\n");
        return 0;
    }

    int i;
    for (i = 0; i < m; i++)
        printf("*");

    for (i = 1; i < (n - 1); i++) {
        printf("\n*");
        if (i == ((n - 1) / 2)) {
            int g, k = (m - 2 - strlen(s)) / 2;
            for (g = 1; g < k + 1; g++)
                printf(" ");
            printf("%s", s);
            for (g = k + strlen(s); g < (m - 2); g++)
                printf(" ");
            printf("*");
            continue;
        }

        int j;
        for (j = 0; j < (m - 2); j++)
            printf(" ");
        printf("*");
    }

    printf("\n");
    for (i = 0; i < m; i++)
        printf("*");
    printf("\n");

    return 0;
}
