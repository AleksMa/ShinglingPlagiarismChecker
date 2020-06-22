#include <stdio.h>
#include <string.h>

int main ( int argc , char ** argv )
{
    /* Проверка на возможные ошибки */

    if (argc < 4) {
        printf(" Usage: frame <height> <width> <text> \n");
        return 0;
    }

    int l_str = strlen(argv[3]), h = atoi(argv[1]), w = atoi(argv[2]);

    if ((w - 2 < l_str) || (h < 3)) {
        printf("Error");
        return 0;
    }

    /* Вывод рамки */

    /* 1 */

    for (int i  = 1; i <= w; i++) {
        printf("*");
    }
    printf("\n");

    /* 2 */

    for (int i = 2; i < ((h + 1) / 2); i++) {
        printf("*");
        for (int j = 2; j < w; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    /* 3 */

    printf("*");
    int k = (w - l_str) / 2 - 1;
    for (int i = 1; i <= k; i++) {
        printf(" ");
    }
    printf("%s",argv[3]);
    for (int i = 1; i < (w - l_str - k - 1); i++) {
        printf(" ");
    }
    printf("*\n");

    /* 4 */

    for (int i = ((h + 1) / 2 + 1); i < h; i++) {
        printf("*");
        for (int j = 2; j < w; j++) {
            printf(" ");
        }
        printf("*\n");

    }

    /* 5 */

    for (int i = 1; i <= w; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}

