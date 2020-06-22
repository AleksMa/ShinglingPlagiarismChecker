#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc!=4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    if ((strlen(argv[3])>(unsigned int)(atoi(argv[2]))-2) || (atoi(argv[1])<3)) {
        printf("Error");
        return 0;
    }
    int i,j,k,l;
    k=(atoi(argv[2])-strlen(argv[3]))/2;
    l=(atoi(argv[1])+2-1)/2-1;
    for (i=0;i<atoi(argv[2]);++i) printf("*");
    printf("\n");
    for (i=1;i<atoi(argv[1])-1;++i){
        printf("*");
        if (i==l){
            for (j=1;j<k;++j) printf(" ");
            printf("%s",argv[3]);
            for (j=k+strlen(argv[3]);j<atoi(argv[2])-1;++j) printf(" ");
            printf("*\n");
            continue;
        }
        for (j=1;j<atoi(argv[2])-1;++j) printf(" ");
        printf("*\n");
    }
    for (i=0;i<atoi(argv[2]);++i) printf("*");
    return 0;
}