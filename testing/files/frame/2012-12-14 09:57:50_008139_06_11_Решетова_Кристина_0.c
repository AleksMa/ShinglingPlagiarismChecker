#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int frame ( char *s_new, int m, int n )
{
    if ( ( m-2 <= strlen(s_new) ) || ( n < 3 ) )
    {
        return -1;
    }

    {   int i;
        for ( i = 0; i < m; i++ )
        {
            printf("*");
        }
         printf("\n");
    }

    int n1 = (n-2) / 2;

    {   int i,j ;
        for (i = 0; i < (n-2); i++ )
        {
            if ( i != n1 )
            {
                printf("*");
                for ( j = 0; j < m - 2 ; j++ )
                {
                    printf(" ");
                }
                printf("*");
                 printf("\n");
            }
            else {
                printf("*");

                for ( j = 0; j < (m - strlen(s_new)-2) / 2+1; j++ )
                {
                    printf(" ");
                }

                printf("%s",s_new);

                for ( j = 0; j < m - (m - strlen(s_new)-2) / 2 - strlen(s_new) - 3; j++ )
                {
                    printf(" ");
                }

                printf("*");
                 printf("\n");
            }
        }
    }
    {   int i;
        for ( i = 0; i < m; i++ )
        {
            printf("*");
        }
         printf("\n");
    }
    return 0;
}



int main( int argc, char *argv[] )
{
    int i,m,n;
    char s_new[100];
    s_new[0]=0;
    if ( argc < 4 ){
        printf("usage: frame <height> <width> <text>\n");
        return 0;
    } else {
        m=atoi(argv[1]);
        n=atoi(argv[2]);

        for( i = 3; i < argc; i++ )
        {
            strcat(s_new, argv[i]);
            strcat(s_new, " ");
        }
    }

    int Error = frame(s_new, n, m );
    return 0;
}
// Это уже другая программа! //