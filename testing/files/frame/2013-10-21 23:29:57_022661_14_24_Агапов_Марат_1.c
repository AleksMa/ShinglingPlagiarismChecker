#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc!=4){
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    char *s, *e;
    s = argv[3];
    int h = strtol(argv[1],&e,10), w = strtol(argv[2],&e,10), ls = strlen(s), spaceh = (h-3)/2, spacew = (w-ls-2)/2, i = 0, j;
    if ((spacew < 0)||(ls+2 > w)||(h<3)){
        printf("Error\n");
        return 0;
    }
    while(i<w){
        printf("*");
        i++;
    }
    printf("\n");
    i = 0;
    while(i<spaceh){
        printf("*");
        j = 0;
        while(j<w-2){
            printf(" ");
            j++;
        }
        printf("*\n");
        i++;
    }
    printf("*");
    i = 0;
    while(i<spacew){
        printf(" ");
        i++;
    }
    printf("%s", s);
    i = 0;
    while(i<(w-ls-spacew-2)){
        printf(" ");
        i++;
    }
    printf("*\n");
    i = 0;
    while(i<(h-spaceh-3)){
        printf("*");
        j = 0;
        while(j<w-2){
            printf(" ");
            j++;
        }
        printf("*\n");
        i++;
    }
    i = 0;
    while(i<w){
        printf("*");
        i++;
    }
    return 0;
}
