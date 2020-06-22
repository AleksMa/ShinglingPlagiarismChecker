#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    if(argc != 4){
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    
    int height = atoi(argv[1]), width = atoi(argv[2]), len;
    for(len = 0; argv[3][len] != '\0'; len++);
    
    if((len > (width - 2)) || height<=2){
        printf("Error\n");
        return -1;
    }
    
    for(int i = 0; i < width; i++)
        putchar('*');
    putchar('\n');
    
    for(int i = 2; i<height; i++){
        putchar('*');
        for (int j = 1; j<=width - 2; j++) {
            if(i == (height+height%2)/2 && (j == (width - len)/2 || width - 2 == len)){
                printf("%s", argv[3]);
                j+=len-1;
            } else
                putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }
    
    for(int i = 0; i < width; i++)
        putchar('*');
    putchar('\n');
    return 0;
}
