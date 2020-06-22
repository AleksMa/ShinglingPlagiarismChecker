#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int k = 0, t = 0 ;
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    if ((strlen(argv[3]) > atoi(argv[2]) - 2) || (atoi(argv[1]) <= 2))
    {
        printf("Error\n");
        return 0;
    }
    /*верхняя часть рамки*/
    for (int i = 0; i < atoi(argv[2]); i++)
        printf("*");
    printf("\n");
    /*определяем положение строки в рамке*/
    if (atoi(argv[1]) % 2 == 0)
        k = atoi(argv[1])/2;
    else
        k = atoi(argv[1])/2 + 1;
    //идем к строке:
    for (int i = 2; i < k ; i++) {
        for(int j = 0; j < atoi(argv[2]); j++) {
            if ((j == 0) || (j == atoi(argv[2]) - 1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    //пишем строку
    for (int i = 1; i <= atoi(argv[2]); i++) {
        if ((i == 1) || (i == atoi(argv[2]))) {
            printf("*");
            t = 1;
        }
        if ((i != (atoi(argv[2]) - strlen(argv[3])) / 2) && (t == 1)) 
            printf(" ");
        else
        {
            printf("%s", argv[3]);
            i +=  strlen(argv[3]);
        }
    }
    printf("\n");
    //идем до последней:
    for (int i = k+1; i < atoi(argv[1]) ; i++) {
        for(int j = 0; j < atoi(argv[2]); j++) {
            if ((j == 0) || (j == atoi(argv[2]) - 1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    //последняя стрка
    for (int i = 0; i < atoi(argv[2]); i++)
        printf("*");
    printf("\n");
    return 0;
}
