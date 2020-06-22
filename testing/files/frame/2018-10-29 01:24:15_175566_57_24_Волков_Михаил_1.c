#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void frame_printing(int height, int width, char* text) 
{
    int length = strlen(text);
    if (width -2 < length || height < 3 ) 
    {
        printf("Error");
        return;
    }
 
    int mid = (height - 1) / 2;
 
    for (int i = 0; i < height; i++) 
    {
        if (i == 0 || i == (height - 1))
            for (int j = 0; j < width; j++)
                printf("*");
 
            else 
        {
            printf("*");
            int limit1 = (width - length - 2) / 2;
            int limit2 = width - length - limit1 - 2;
 
            for (int skip = 0; skip < limit1; skip++)
                printf(" ");
 
            if (i == mid)
                printf("%s", text);
            else
                for (int skip = 0; skip < length ; skip++)
                    printf(" ");
 
            for (int skip = 0; skip < limit2 ; skip++)
                printf(" ");
 
            printf("*");
 
        }
            printf("\n");
 
    }
 
}
 
 
int main(int argc, char* argv[])
{
 
    if (argc != 4) 
    {
        printf("%s" , "Usage: frame <height> <width> <text>");
        return 0;
    }
    char string[100];
    int height = atoi(argv[1]); 
    int width = atoi(argv[2]); 
    strcpy(string,argv[3]);
    frame_printing(height, width, string);
 
    return 0;
}