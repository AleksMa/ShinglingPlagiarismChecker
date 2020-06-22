#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void zv(int n)
{
     for(n;n>0;n--)
     {
                   printf("*");
     }
     printf("\n");
}

int main(int argc,char **argv)
{
    int i,j,k,n;
    int visota,dlina;
    char str[128];
    char *nujnayaperemennaya;
    if(argc<3)
    {
              printf("usage: frame <height> <width> <text>");
              return 0;
    }
    visota=strtol(argv[1],&nujnayaperemennaya,10);
    dlina=strtol(argv[2],&nujnayaperemennaya,10);
    if((strlen(argv[3])>dlina-2)||(visota<3))
    {
                              printf("Error");
                              return 0;
    }
    zv(dlina);
    if(visota%2==0)
    {
                   n=2;
    }
    else
    {
        n=1;
    }
    for(i=0;i<(visota/2-n);i++)
    {
                                printf("*");
                                for(j=0;j<(dlina-2);j++)
                                {
                                                         printf(" ");
                                }
                                printf("*\n");
    }
    printf("*");
    for(i=0;i<(dlina-strlen(argv[3])-2)/2;i++)
    {
                    printf(" ");
    }
    printf("%s",argv[3]);
    for(i=0;i<(dlina-strlen(argv[3])-1)/2;i++)
    {
                          printf(" ");
    }
    printf("*\n");
    for(i=0;i<(visota/2-1);i++)
    {
                               printf("*");
                               for(j=0;j<(dlina-2);j++)
                               {
                                                       printf(" ");
                               }
                               printf("*\n");
    }
    zv(dlina);
    return 0;
}
