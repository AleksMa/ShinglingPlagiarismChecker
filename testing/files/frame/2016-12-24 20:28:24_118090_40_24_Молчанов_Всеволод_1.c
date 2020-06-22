#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc < 4){
        printf("Usage: frame <height> <width> <text>\n");
        return 1;
    }
    
    int str_length = strlen(argv[3]), height = atoi(argv[1]), width = atoi(argv[2]);
    char *string = argv[3];
    
    if( (str_length > width - 2) || (height < 3) ){
        printf("Error\n");
        return 1;
    }
    
    int is_width_even = 0, is_height_even = 0, padding = 0;
    if(!(height % 2)) is_height_even = 1;
    if(!(width % 2)) is_width_even = 1;
    if(!((width - str_length) % 2)) padding = 1;
    
    for(int i = 0; i <= width - 1; i++) printf("*");
    printf("\n");
    for(int i = 0; i <= height - 3; i++){
        printf("*");
        if(i == (height - 2 - is_height_even) / 2){
            for(int k = 0; k <= (width - str_length) / 2 - 2; k++) printf(" ");
            printf("%s", string);
            for(int k = 0; k <= (width - str_length) / 2 - 1 - padding; k++) printf(" ");
            printf("*");
            printf("\n");
        }else{
            for(int j = 0; j <= width - 3; j++) printf(" ");
            printf("*\n");
        }
    }
    for(int i = 0; i <= width - 1; i++) printf("*");
    printf("\n");
    return 0;
}