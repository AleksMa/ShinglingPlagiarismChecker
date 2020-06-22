#include <stdio.h>
#include <string.h>

int main (int argc,char** argv){
    int w,h,i,j,k,n,x;
    char *s,*e;
    if (argc!=4){
    printf ("usage: frame <height> <width> <text>\n");
    return 0;
    }
    h = strtol ( argv [1] , &e , 10);
    w = strtol ( argv [2] , &e , 10);
    s=argv[3];
    k=strlen(s);
    n=(h-2)/2;
    x=(w-k-2)/2;
    if (x<0||h<3){
        printf ("Error\n");
        return 0;
    }
    for (i=0;i<w;i++)
        printf ("*");
    printf ("\n");
    for (i=0;i<h-n-3;i++){
        printf ("*");
        for (j=0;j<w-2;j++)
            printf (" ");
        printf ("*\n");
    }
    printf ("*");
    for (i=0;i<x;i++)
        printf (" ");
    printf ("%s",s);
    for (i=0;i<w-x-k-2;i++)
        printf (" ");
    printf ("*\n");
    for (i=0;i<n;i++){
        printf ("*");
        for (j=0;j<w-2;j++)
            printf (" ");
        printf ("*\n");
    }
    for (i=0;i<w;i++)
        printf ("*");
    printf ("\n");
    return 0;
}
