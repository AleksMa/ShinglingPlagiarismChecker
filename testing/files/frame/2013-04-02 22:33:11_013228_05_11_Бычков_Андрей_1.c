#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    int i, j ,k, n, v, d;
    char str[128], *s;
    if(argc < 3)
    {
              printf("usage: frame <height> <width> <text>");
              return 0;
    }
    v = strtol(argv[1],&s,10);
    d = strtol(argv[2],&s,10);
    if((strlen(argv[3]) > d - 2)||(v < 3))
    {
                              printf("Error");
                              return 0;
    }
    for(n = d; n > 0; n--)
                   printf("*");
    printf("\n");
    if(v % 2 == 0)
                   n = 2;
    else
        n = 1;
    for(i = 0; i < (v / 2 - n); i++)
    {
                                printf("*");
                                for(j = 0; j < d - 2;j++)
                                                         printf(" ");
                                printf("*\n");
    }
    printf("*");   
    for(i = 0; i < (d - strlen(argv[3]) - 2);i++){
                      printf(" ");
                      if (i == (d - strlen(argv[3]) - 2) / 2 - 1) 
                            printf("%s",argv[3]);
    }
    printf("*\n");
    for(i = 0; i < (v / 2 - 1);i++)
    {
                               printf("*");
                               for(j = 0; j < (d - 2); j++)
                                                       printf(" ");
                               printf("*\n");
    }
    for(n = d; n > 0; n--)
                   printf("*");
    printf("\n");
    return 0;
}
