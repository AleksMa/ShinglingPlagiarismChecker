#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc , char ** argv) {
    if(argc!=4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int i, h=atoi(argv[1]), w=atoi(argv[2]), j;
    if(h>65 || w>30 || w<strlen(argv[3])+2 || h<3){
         printf("Error\n");
         return 0;
    }
    for(j=1;j<=h;j++){
        if(j==1 || j==h){
            for(i=0;i<w;i++){
                printf("*");
            }
            printf("\n");
            continue;
        }

        if((j==h/2+1 && h%2!=0) || h==3 || (j==h/2 && h%2==0)){
            printf("*");
            for(i=1;i<(w-strlen(argv[3]))/2;i++){
                printf(" ");
            }
            printf("%s", argv[3]);
            for(i=(w+strlen(argv[3]))/2;i<w-1;i++){
                printf(" ");
            }
            printf("*");

        }
        else{
            printf("*");
            for(i=2;i<w;i++){
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
