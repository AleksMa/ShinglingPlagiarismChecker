#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc , char **argv ) {
    if (argc!=4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int a = atoi(argv[1]), b = atoi(argv[2]), s = strlen(argv[3]);
    //printf("%d %d\n", a, b);
    if (s > b-2 || a < 3){
        printf("Error");
        return 0;
    }
    char x;
    for (int j = 0; j < a; ++j) {
        for (int i = 0; i < b; ++i) {
            //printf("%d %d\n", j, i);
            x = ' ';
            if (j%(a-1)==0 || i%(b-1)==0) {
                x = '*';
            }
            if (j==(a-1)/2 && i < s+(b-s)/2 && i >= (b-s)/2){
                    x = argv[3][i-(b-s)/2];
            }
            printf("%c", x);
        }
        printf("\n");

    }

    return 0;
}