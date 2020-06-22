#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
        int middle,height,width,j=0,i=0,k=0,count=0;
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    char *text;
    text = argv[3];
    height = atoi(argv[1]);
    width = atoi(argv[2]);
    if ((height < 3) || strlen(argv[3])  > width || strlen(argv[3])>=width -1)
    {
        printf("Error\n");
        return 0;
    }
    if (height % 2 == 0)
    {
        middle = (height-1)/2;
    }
    else
    {
        middle = (height-1)/2;
    }
    j=0;
    while(j < width)
    {
        printf("*");
        j++;
    }
    if (height != 3)
        printf("\n");
    else
        printf("\n");
 
    j=1;
    while(j < height - 1)
    {
        if ((height != 3) && (j != middle))
            {
                    printf("*");
                    for (i = 0; i < width - 2; i++)
                    {
                            printf(" ");
                    }
                    printf("*");
                    if (height != 3)
                            	printf("\n");
            		else
                		printf("\n");
            }
        else
        {
                count = strlen(argv[3]) + 2;
                k = (width - count) / 2;
                printf("*");
                for(i = 0; i < k; i++ )
                {
                    printf(" ");
                    count++;
                }
                printf("%s", argv[3]);
                while (count < width)
                {
                    printf(" ");
                    count++;
                }
                    printf("*");
                    if (height != 3)
	                    printf("\n");
                	else
                    	printf("\n");
        }
        j++;
    }
    for (j = 0; j < width; j++)
    {
        printf("*");
    }
    return 0;
}