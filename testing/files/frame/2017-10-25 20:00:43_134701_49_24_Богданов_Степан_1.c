#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc,char **argv)
{
    if (argc!=4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int h,l,i,k,j,m,t,n;
    h=atoi(argv[1]);
    l=atoi(argv[2]);
    char *s=argv[3];
    n=strlen(s);
    if((n>l-2)||((h-2)<1))
    {
        printf("Error");
        return 0;
    }
    for(i=0;i<l;i++)
        printf("*");
    printf("\n");
    k=0;
    while(k<((h+1)/2-2))
    {
        printf("*");
        for(j=0;j<l-2;j++)
            printf(" ");
        printf("*");
        printf("\n");
        k++;
    }
    printf("*");
    m=(l-n)/2;
    for(i=0;i<m-1;i++)
        printf(" ");
    printf("%s",s);
    m=l-n-m;
    for(i=0;i<m-1;i++)
        printf(" ");
    printf("*");
    printf("\n");
    t=h-k;
    k=0;
    while(k<t-3)
    {
        printf("*");
        for(j=0;j<l-2;j++)
            printf(" ");
        printf("*");
        printf("\n");
        k++;
    }
    for(i=0;i<l;i++)
        printf("*");

    return 0;
}
