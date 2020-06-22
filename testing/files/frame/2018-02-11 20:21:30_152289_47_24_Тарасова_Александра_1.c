#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int i,j,width,height, len;
    /*for(i=0;i<argc;i++){
        printf("\n%s",argv[i]);
    }
     */
    if(argc!=4){
        printf("Usage: frame <height> <width> <text>");
        return 1;
    }
    
    width= atoi(argv[2]);
    height= atoi(argv[1]);
    len= strlen(argv[3]);
    
    if((len>width-2)|| (height<=2)){
        printf("Error");
        return 2;
    }
    for(i=0;i<width;i++){
        printf("*");
    }
    printf("\n");
    
    for(i=1;i<(height/2 -1+(height%2));i++){
        printf("*");
        for(j=1;j<width-1;j++){
            printf(" ");
        }
        printf("*\n");
    }
    
    printf("*");
    
    for(i=1;i<(width-len)/2;i++){
        printf(" ");
    }
    
    printf("%s", argv[3]);
    
    for(i=(width-len)/2+len;i<width-1;i++){
        printf(" ");
    }
    printf("*\n");
    
    for(i=height/2+(height%2);i<height -1;i++){
        printf("*");
        for(j=1;j<width-1;j++){
            printf(" ");
        }
        printf("*\n");
    }
    for(i=0;i<width;i++){
        printf("*");
    }
    return 0;
}
