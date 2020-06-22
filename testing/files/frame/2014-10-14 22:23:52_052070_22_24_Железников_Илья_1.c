
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    int mid;
    int height = atoi(argv[1]),width = atoi(argv[2]);
    char text[strlen(argv[3])];
    *text = argv[3];
    if (((int)strlen(argv[3]) + 1 >= width) || (height <= 2))
    {
        printf("Error\n");
        return 0;
    }
    if (height % 2 == 0)
        mid = height/2;
    else
        mid = height/2 +1;
    int i,j,m;
    for (i=1; i<=width; i++)
    {
        printf("*");
    }
    if (height != 3)
        printf("\n");
    else
        printf("\n");
    
    for (i = 2; i<height; i++)
    {
        if ((i == mid ) || (height == 3))
            { 
                int temp = 2 +(int)strlen(argv[3]);
                m= (width-2-(int)strlen(argv[3]))/2;
                printf("*");
                for(j=1; j<=m; j++ )
                {
                    printf(" ");
                    temp++;
                }
                printf("%s", argv[3]);
                while (temp < width)
                {
                    printf(" ");
                    temp++;
                }
                //if ((int)strlen(argv[3])+ 2 + m != width)
                //    printf(" ");
                printf("*");
                if (height != 3)
                    printf("\n");
                else
                    printf("\n");
            }
        else
        {
            printf("*");
            for (j=1; j<=width - 2; j++)
            {
                printf(" ");
            }
            printf("*");
            if (height != 3)
                printf("\n");
            else
                printf("\n");
            
        }
    }
    for (i=1; i<=width; i++)
    {
        printf("*");
    }
    return 0; 
}