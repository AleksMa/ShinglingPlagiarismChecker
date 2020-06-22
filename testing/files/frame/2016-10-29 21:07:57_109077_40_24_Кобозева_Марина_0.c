#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }

    int height = strtol(argv[1], NULL, 10);
    int width = strtol(argv[2], NULL, 10);
    if (strlen(argv[3])+2 > width || height < 3) {
        printf("Error\n");
        return 0;
    }

    int i, j;
    for (i = 0; i < width; i++)
        printf("*");
    printf("\n");

    int vert = ((height - 2)/2);
    if (height%2 == 0)
        vert--;

    for (i = 0; i <  vert; i++) {
        printf("*");
        for (j=0; j < width-2; j++)
            printf(" ");
        printf("*\n");
    }


    int horiz = (width-2-strlen(argv[3])) / 2;

    printf("*");
    for (i = 0; i < horiz; i++)
        printf(" ");
    printf("%s", argv[3]);
    for (i = 0; i < width-horiz-2-strlen(argv[3]); i++)
        printf(" ");
    printf("*\n");


    for (i = 0; i <  height-vert-3; i++) {
        printf("*");
        for (j=0; j < width-2; j++)
            printf(" ");
        printf("*\n");
    }

    for (i = 0; i < width; i++)
        printf("*");
    printf("\n");

    return 0;
}
