#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print (char *t, unsigned long k, unsigned long l, unsigned long r){
    printf("*");
    if ( t == NULL) {
        if (r == 1) for (int i = 0; i < k - 2; i++)  printf("*");
        else for (int i = 0; i < k - 2; i++)  printf(" ");
    } else {
        for (int i = 0; i < l; i++) printf(" ");
        printf ("%s", t);
        for (unsigned long i = 1 + l + strnlen(t, 100); i < k - 1; i++) printf (" ");
    }
    
    printf("*");
    printf("\n");
}
int main(int argc, char **argv)
{
    unsigned long height = atoi(argv[1]), length = atoi(argv[2]);
    char *str = argv[3];
    if (argc != 4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    unsigned long len = strnlen(str, 100);
    if (length - 2 < len || height < 3) {
        printf ("Error");
        return 0;
    }
    unsigned long start_h = (height+1)/2, start_l = (length - len - 2)/2;
    for (int i = 0; i < height; i++) {
        if ((i == 0 || i == height - 1) && i != start_h - 1) print (NULL, length, 0, 1);
        if (i == start_h - 1) print (str, length, start_l, 0);
        if (i!= 0 && i != height -1 && i != start_h - 1) print(NULL, length, 0, 0);
    }
    return 0;
    
}