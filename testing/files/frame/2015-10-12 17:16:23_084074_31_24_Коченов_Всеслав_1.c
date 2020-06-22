#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc!=4) {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
        }
    int height = atoi(argv[1]), width = atoi(argv[2]);
    if ((width-2<strlen(argv[3])) || (height<=2)) {
        printf("Error\n");
        return 0;
        }
    int i,j;
    for (i=0;i<width;i++) printf("*");
    printf("\n");
    int puststr = height-3;
    for (i=0;i<puststr/2;i++){
        printf("*");
        for (j=0;j<width-2;j++) printf(" ");
        printf("*\n");
    }
    printf("*");
    int nprob=width-strlen(argv[3])-2;
    for (i=0;i<nprob/2;i++) printf(" ");
    printf("%s", argv[3]);
    for (i=0;i<nprob-nprob/2;i++) printf(" ");
    printf("*\n");
    for (i=0;i<puststr-puststr/2;i++) {
        printf("*");
        for (j=0;j<width-2;j++) printf(" ");
        printf("*\n");
    }
    for (i=0;i<width;i++) printf("*");
    printf("\n");
}
