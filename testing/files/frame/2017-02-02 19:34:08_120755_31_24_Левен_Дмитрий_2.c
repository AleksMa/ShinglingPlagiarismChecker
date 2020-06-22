#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
    if(argc!=4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int a=atoi(argv[1]),b=atoi(argv[2]);
    //printf("%d %d\n",a,b)
    if(strlen(argv[3])>(b-2)||a<3)
    {
        printf("Error");
        return 0;
    }
    int i,j;
    for(i = 0;i<b;i++)
        printf("*");
    printf("\n");
    for(i = 1;i<a/2-!(a%2);i++)
    {
        printf("*");
        for(j = 0;j<b-2;j++)
            printf(" ");
        printf("*\n");
    }
    printf("*");
    int len = b-2-strlen(argv[3]);
    for(i = 0;i<len/2;i++)
        printf(" ");
    printf("%s",argv[3]);
    for(;i<len;i++)
        printf(" ");
    printf("*\n");
    for(i = 1;i<a/2;i++)
    {
        printf("*");
        for(j = 0;j<b-2;j++)
            printf(" ");
        printf("*\n");
    }
    for(i = 0;i<b;i++)
        printf("*");
    printf("\n");
    return 0;
}
