#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(int argc, char **argv)
{
    int heigth, width, i, j, k, space;
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    heigth = atoi(argv[1]);
    width = atoi(argv[2]);
    if ((width < strlen(argv[3]) + 2) || (heigth < 3)) {
        printf("Error\n");
        return 0;
    }

     for (i = 0; i < heigth; i++) {

               if (i == 0) for (j = 0; j < width; j++)
                    if (j == width-1) printf("*\n");
                    else printf("*");
               else if (i == ceil(heigth/2.0) -1 ) {
                    printf("*");
                    space = (width - strlen(argv[3]))/2;
                    for (k = 1; k < space; k++) printf(" ");
                    printf("%s", argv[3]);
                    for (k = 1; k < width -space - strlen(argv[3]); k++) printf(" ");
                    printf("*\n");
                    }
                else if (i == heigth-1) for (j = 0; j < width; j++) printf("*");
                else for (j = 0; j < width; j++) {
                    if (j == width-1) printf("*\n");
                    else if (j == 0) printf("*");
                    else printf(" ");
                }
    }

    return 0;
}

