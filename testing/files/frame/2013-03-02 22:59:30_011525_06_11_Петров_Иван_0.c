#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int frame (int h, int w, char s[100])
{
        int  i,j,a,b,len;
        len=strlen(s);
        if ((w-2<len)||(h<1))
        {
            printf("Error");
            return 0;
        }
        a=(w-len)/2;
        b=a+len;
        for(i=0;i<h;i++)
        {
            if((i==0)||(i==h-1))
                for(j=0;j<w;j++) printf("*");
            else if(i==h/2-!(h%2))
            {
                for(j=0;j<w;j++)
                {
                    if ((j==0)||(j==w-1)) printf("*");
                    else if((j>=a)&&(j<b)) printf("%c",*(s+j-a));
                    else printf(" ");
                }
            }
            else
            {
                for(j=0;j<w;j++)
                {
                    if((j==0)||(j==w-1)) printf("*");
                    else printf(" ");
                }
            }
                printf("\n");
        }
        return 0;
}
int main (int argc, char **argv)
{
        if(argc!=4)
        {
                printf("usage: frame <height> <width> <text>");
                return 0;
        }
        frame(atoi(argv[1]),atoi(argv[2]),argv[3]);
        return 0;
}