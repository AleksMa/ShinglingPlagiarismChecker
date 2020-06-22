#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int width, length, i, j, ls, zn;
    if (argc!=4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    width=atoi(argv[2]);
    length=atoi(argv[1]);
    ls=strlen(argv[3]);
    //printf("%d %d %d", width, length, ls);
    if (ls>=(width-1) || length<=2) {
        printf("Error");
        return 0;
    }
    if (length%2 == 1) zn=(length+1)/2-1;
    else zn=length/2-1;

    for (j=0; j<length; j++){
         if ((j==0) || (j==length-1)){
            for (i=0; i<width; i++) printf("*");
            printf("\n");
         }
         else if (j==zn) {
            printf("*");
            for (i=1; i<=(width-2-ls)/2; i++) printf(" ");
            printf("%s", argv[3]);
            for (i=(width-2+ls)/2; i<(width-2); i++) printf(" ");
            printf("*\n");
        }
         else for (i=0; i<width-1; i++){
            if (i==0) printf("*");
            if (i==width-2) printf("*\n");
            else printf(" ");
         }

    }


    return 0;
}