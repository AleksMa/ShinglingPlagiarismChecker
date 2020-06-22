#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    int i, o, l;
    if (argc!=4) printf("Usage: frame <height> <width> <text>");
    else
    {
        for (l=0;argv[3][l]!='\0';++l);
        int height, width;
        height=atoi(argv[1]);
        width=atoi(argv[2]);
        if (l>(width-2) || height<3) printf("Error");
        else
        {
            for(i=1;i<=height;++i)
            {
                if ((i==(height/2) && height%2==0) || (i==(height/2+1) && height%2==1))
                {
                    printf("*");
                    for (o=1;o<=(width-l-2)/2;++o) printf(" ");
                    printf(argv[3]);
                    for (o+=l;o<width-1;++o) printf(" ");
                    printf("*");
                }
                else
                for (o=1;o<=width;++o)
                {
                    if (i==1 || i==height) printf("*");
                    else if (o==1 || o==width) printf("*");
                         else printf(" ");
                }
                printf("\n");
            }
        }
    }
}