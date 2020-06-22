#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[3])
{

    if(argc != 4)
    {
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }

    if((atoi(argv[2]) < strlen(argv[3]) + 2) || (atoi(argv[1]) < 3))
    {
        printf("Error\n");
        return 0;
    }
    int i, j;
    for(i = 0; i < atoi(argv[1]); i++)
    {
        for(j = 0; j < atoi(argv[2]); j++)
        {
            if((i == 0) || (j == 0) || (i == atoi(argv[1])-1) || (j == atoi(argv[2])-1))
            {
                printf("*");
            }
            else if((i == ((ceil(atoi(argv[1])/2))- (atoi(argv[1]) + 1) % 2)) && (j == (atoi(argv[2]) - strlen(argv[3]))/2))
            {
                printf("%s", argv[3]);
                j += strlen(argv[3])-1;
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}