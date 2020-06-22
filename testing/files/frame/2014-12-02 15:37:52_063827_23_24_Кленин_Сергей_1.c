#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int h, w, i=1, j=1, k, x, y, l=0;
    const char *t;
    if(argc!=4) {
        printf("Usage: frame <height> <width> <text>\n");
        return -1;
    }
    h=atoi(argv[1]);
    w=atoi(argv[2]);
    t=argv[3];
//    h*=2;
//    h-=3;
    for(k=0; t[k]; k++);
//    if(h==5) h=4;
    y=h/2;
//    if(h==5) y=3;
    if(h%2==1) y+=1;
    x=(w-k)/2+1;
//    if((w-k)/2==1) x+=1;
//    if((w-k)%2==1) x+=0.5;
    if(k>(w-2) || h<3) {
        printf ("Error\n");
        return -2;
    }
    while(j<=h) {
        if(j==1 || j==h) {
            for(i=0; i<w; i++) {
                printf("*");
            }
            printf("\n");
            j++;
            continue;
        }
        if(j!=1 && j!=h) {
            for(i=1; i<=w; i++) {
                if(j==y && i==x) {
                    printf("%s", t);
                    i+=k;
                }
                if((j<h) && ((i==1) || (i==w)))
                    printf("*");
                else printf(" ");
            }
            printf("\n");
            j++;
        }
    }
    return 0;
}