#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{ 
        int height=1, width=2, t=0,k=0, r=0, cer=0, per=0;
        if (argc != 4){
                printf("Usage: frame <height> <width> <text>");
                return 0;
        }
        height = atoi(argv[1]);
        width = atoi(argv[2]);
        if ((width-2) < strlen(argv[3])){
                printf("Error");
                return 0;
        }
        if (width < 3){
                printf("Error");
                return 0;
        }
        if (height < 3){
                printf("Error");
                return 0;
        }
        for (int i=0; i<width; i++) printf("*");
        printf("\n");
        if (height % 2 == 0){
                cer = -1;
        } 
        for (int i=0; i < (height-2) ; i++){
                if (i != ((height-2)/2 + cer)){
                        printf("*");
                        for (int j=0; j<(width-2); j++) printf(" ");
                        printf("*\n");
                }else{
                        printf("*");
                        for (int r=0; r < ((width - 2 - strlen(argv[3]))/2); r++){
                                printf(" ");
                                k=r+1;
                        }
                        printf("%s", argv[3]);
                        for (int e=0; e < (width - 2 - strlen(argv[3]) - k); e++) printf(" ");
                        printf("*\n");
                }
        }
        for (int i=0; i<width; i++) printf("*");
        return 0; 
}