#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char** argv) {
    int i,j,k,c;
    i=j=k=c=0;
    if (argv[3] == NULL) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    k = (atoi(argv[2]) - strlen(argv[3]))/2;
    if (k <= 0 || atoi(argv[1]) <= 2) {
        printf("Error");
        return 0;
    }
    int h = atoi(argv[1]);
    int w = atoi(argv[2]);
    for(j = 1; j <=w; j++) printf("*");
    printf("\n");
    if(h%2)
    for(i = 0; i < h-2;i++){
        if(i == (h-2)/2){
            printf("*");
            for(j = 1; j <= (w - strlen(argv[3]) - 2)/2; j++) printf(" ");
            printf("%s",argv[3]);
            if((w - strlen(argv[3])) % 2) for(j = 1; j <= (w - strlen(argv[3]) - 2)/2+1; j++) printf(" ");
            else for(j = 1; j <= (w - strlen(argv[3]) - 2)/2; j++) printf(" ");
            printf("*");
            printf("\n");
        }
        else{
            printf("*");
            for(j = 1; j <=w-2;j++) printf(" ");
            printf("*");
            printf("\n");
        }
    }
    else
        for(i = 0; i < h-2;i++){
            if(i == (h-2)/2-1){
                printf("*");
                for(j = 1; j <= (w - strlen(argv[3]) - 2)/2; j++) printf(" ");
                printf("%s",argv[3]);
                if((w - strlen(argv[3])) % 2) for(j = 1; j <= (w - strlen(argv[3]) - 2)/2+1; j++) printf(" ");
                else for(j = 1; j <= (w - strlen(argv[3]) - 2)/2; j++) printf(" ");
                printf("*");
                printf("\n");
            }
            else{
                printf("*");
                for(j = 1; j <=w-2;j++) printf(" ");
                printf("*");
                printf("\n");
            }
        }
    for(j = 1; j <= w;j++) printf("*");
    return 0;
}