#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
    int x = atoi(argv[1]), y = atoi(argv[2]), k = 0;
    if (argv[3] != NULL){
        k = strlen(argv[3]);
    }else{
        printf("Usage: frame <height> <width> <text> \n");
        return 0;
    }
    if((k > (y - 2)) || (x < 3)){
        printf("Error \n");
        return 0;
    }
    for (int j = 0; j < y; j++){
        printf("%c", '*');
    }
    printf("\n");
    int z = 0;
    (x % 2 == 0)? (z = x / 2 - 1) : (z = x / 2);
    for (int i = 1; i > 0 && i < x-1; i++){
            if(i == z){
            printf("%c", '*');
            int l = ((y - 2) - k) / 2;
            int n = ((y - 2) - k) - l;
            for (int j = 0; j < l; j++){
                printf(" ");
            }
            printf("%s", argv[3]);
            for (int j = 0; j < n; j++){
                printf(" ");
            }
            printf("%c \n", '*');
        }else{
            printf("%c", '*');
            for(int j = 2; j < y; j++){
                printf(" ");
            }
            printf("%c \n", '*');
        }
    }
    for (int j = 0; j < y; j++){
        printf("%c", '*');
    }
    printf("\n");
    return 0;
}

