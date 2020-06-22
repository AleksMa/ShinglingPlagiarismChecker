
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv)
{
    int n,m,k=0,i,j;
    char *e;
    if (argc != 4) {
        printf("usage: frame <height> <width> <text>");
        return -1;
    }
    m=(int)strtol(argv[1],&e,10);
    n=(int)strtol(argv[2],&e,10);
    while (argv[3][k] != '\0')
        k++;
    if (n-2<k || m<3) {
        printf("Error");
        return -2;
    }
    for (i=0;i<n;i++)
        printf("*");
    printf("\n");
    for (j=0;j<(m-1)/2-1;j++) {
        printf("*");
        for (i=2;i<n;i++)
            printf(" ");
        printf("*\n");
    }
    printf("*");
    for (i=1;i<n/2-k/2;i++)
        printf(" ");
    printf("%s",argv[3]);
    for (i=n/2+(k+1)/2+1;i<n;i++)
        printf(" ");
    printf("*\n");
    for (j=(m+1)/2+1;j<m;j++) {
        printf("*");
        for (i=2;i<n;i++)
            printf(" ");
        printf("*\n");
    }
    for (i=0;i<n;i++)
        printf("*");
    return 0;
}
