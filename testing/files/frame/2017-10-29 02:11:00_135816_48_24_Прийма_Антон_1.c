#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char  **argv)
{
    int n1,j,i,sr,sr1,height=0,width=0;
    height = atoi(*(argv+1));
    width = atoi(*(argv+2));
    char *str = (*(argv+3));
    if (argc!=4){
           printf("Usage: frame <height> <width> <text>");
           return 0;
    }
    
    if (height<=2 || width-2<strlen(str))
        printf("Error");
    else
    {
        if (height%2==0)
                sr = height/2;
    else
        sr = (height/2) + 1;
    sr1 = (((width-2)-strlen(str))) ;

    for (i=0;i<width;i++)
        printf("*");
        printf("\n");
        for(i=1;i<height-1;i++)
        {
            if (i==sr-1)
            {
                printf("*");
                for (j=0;j<(((width-2)-strlen(str))/2);j++)
                        printf(" ");
                printf("%s", str);
                if (sr1>=2)
                        for (j=0;j<sr1/2;j++)
                                printf(" ");
                else
                        for (j=0;j<sr1;j++)
                                printf(" ");
                printf("*\n");
            }
            else
            {
                printf("*");
                for (j=1;j<width-1;j++)
                    printf(" ");
                printf("*\n");
            }
        }
        for (i=0;i<width;i++)
        printf("*");
    }
    return 0;
}
