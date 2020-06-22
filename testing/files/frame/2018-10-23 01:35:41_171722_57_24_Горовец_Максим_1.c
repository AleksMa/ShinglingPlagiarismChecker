#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) 
{
    if(argc != 4){
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }

    int height = atoi(argv[1]), width = atoi(argv[2]);
    const char* str = argv[3];
    int length = strlen(str);
    int n = ((width - length) / 2);
    int midHeight;
    if(height % 2 == 0){
        midHeight = height / 2;
    } else{
        midHeight = (height / 2) + 1;
    }

    if(length > width - 2 || height <= 2){
        printf("Error\n");
        return 0;
    }

    for(int i = 1; i <= height; i++){
        printf("*");
        for(int j = 1; j <= width - 2; j++){
            if(i == 1 || i == height){
                printf("*");
            } else if(i == midHeight && j == n){
                printf("%s", str);
                j += length;
                j -= 1;
            } else{
                printf(" ");
            }
        }
        printf("*\n"); 
    } 
    
    return 0;
}
