#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void body (int height, int width)
{
    for (int r = 0; r <((height - 2)/2); r++)
    {
        printf("*");
        for (int z = 0; z < (width - 2);z++)
            printf(" ");
        printf("*");    
        printf("\n");
    }   
}


void cap(int width)
{
    for (int i = 0; i < width; i++)
        printf("*");
    printf("\n");
}

void str(int width, char *text)
{
    int size,width1,width2;
    size = strlen(text);
    width1 = ((width - 2) - size) / 2;
    width2 = ((width - 2) - size) - width1;
    printf("*");
    for (int j = 0; j < width1; j++)
        printf(" ");
    printf("%s", text);
    for (int p = 0; p < width2; p++)
        printf(" ");
    printf("*");
    printf("\n");    
}
int main(int argc , char *argv[])
{
    int height, width;
    int flag = 0;
    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    height = atoi(argv[1]);
    width = atoi(argv[2]);
    char *text = argv [3];
    int matter;
    matter = strlen(text);
    if (((width - 2) < matter) || (height <= 2))
    {
    	printf("Error");
    	return 0;
    }
    
    cap(width);
    if ((height %  2) == 1) body(height, width);
    else body((height - 1),width);
    str(width,text);
    body(height, width);
    cap(width);
    
    
    
    return 0;
}


