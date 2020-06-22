#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv){
    if(argc != 4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int height = atoi(*(argv + 1));
    int width = atoi(*(argv + 2));
    if(strlen(*(argv + 3))  + 2> width){
        printf("Error");
        return 0;
    }
    if(height < 3){
        printf("Error");
        return 0;
    }
    int i,j;
    char array[height][width];
    for(i = 0; i < height; i++)
        for( j = 0; j < width; j++){
            if(i == 0 || i == height-1){
                array[i][j] = '*';
                continue;
            }
            if(j == 0 || j == width - 1)
                array[i][j] = '*';
            else
                array[i][j] = ' ';
        }
    i = height/2 - (height+ 1)%2;
    int k  = 0;
    for(j = ((width - strlen(*(argv + 3)))/2); j < ((width - strlen(*(argv + 3)))/2) + strlen(*(argv + 3)); j++)
        array[i][j] = *(*(argv +3) + k++);
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++)
            printf("%c",array[i][j]);
        printf("\n");
    }
    
}