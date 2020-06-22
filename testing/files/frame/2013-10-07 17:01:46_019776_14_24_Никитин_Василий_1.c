#include <stdio.h>

int main(int argc,char **argv)
{
    if (argc<4) {
        printf("Usage: frame <height> <width> <text>");
    }
    else {
        int h=atoi(argv[1]);
        int w=atoi(argv[2]);
        char *s=argv[3];
        if (((w-2)<strlen(s)) || (h<3)){
            printf("Error");
            return 0;
        }
        int i;
        for (i=1;i<=w;i++) {
            printf("*");
        }
        printf("\n");
        int j;
        for (i=1;i<=h-2;i++) {
            printf("*");
            if ((int)((h-1)/2)==i) {
                for (j=1;j<=(int)((w-2-strlen(s))/2);j++)
                    printf(" ");
                printf("%s",s);
                
                for (j=1;j<=(w-2-strlen(s))-(int)((w-2-strlen(s))/2);j++)
                    printf(" ");
            }
            else
                for (j=1;j<=w-2;j++) {
                    printf(" ");
                }
            printf("*\n");
        }
        for (i=1;i<=w;i++) {
            printf("*");
        }
    }
    return 0;
}

