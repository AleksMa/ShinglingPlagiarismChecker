#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int h,w,i,j;
    if (argc != 4) {
        printf("Usage: frame <height> <width> <text>");
    } else {
        h=atoi(argv[1]);
        w=atoi(argv[2]);
        if(h<3||w-2<strlen(argv[3])){
            printf("Error");
        } else{
            for(i=0;i<w;i++){
                printf("*");
            }
            printf("\n");
            for(i=0;i<(h-3)/2;i++){
                printf("*");
                for(j=1;j<w-1;j++){
                    printf(" ");
                }
                printf("*\n");
            }
            printf("*");
            for(i=0;i<(w-2-strlen(argv[3]))/2;i++){
                printf(" ");
            }
            printf("%s", argv[3]);
            for(i=0;i<(w-2-strlen(argv[3]))/2+(w-2-strlen(argv[3]))%2;i++){
                printf(" ");
            }
            printf("*\n");
            for(i=0;i<(h-3)/2+(h-3)%2;i++){
                printf("*");
                for(j=1;j<w-1;j++){
                    printf(" ");
                }
                printf("*\n");
            }
            for(i=0;i<w;i++){
                printf("*");
            }
        }
    }
    return(0);
}
