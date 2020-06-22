#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc , char ** argv)
{
        int i,k,m,j,n,b;
        if ( argc < 4 || argc >= 5) {
                printf (" Usage: frame <height> <width> <text>\n" );
                return 0;
        }
        n=atoi(argv[1]);
        k=(n - 1)/2;
        m=(atoi(argv[2]));
        if (n < 3 || strlen(argv[3]) > (m-2)){
                printf("Error");
                return 0;
        }
        for(i=1;i<=m;i++)
                printf("*");
        for(i=1;i<=n-2 ;i++){
                if (i!=k){
                        printf("\n");
                        printf("*");
                        for(j=2;j<m;j++)
                                printf(" ");
                        printf("*");
                }
                else{
                        printf("\n");
			printf("*");
                        for(b=1;b<=(m-strlen(argv[3])-2)/2;b++)
                                printf(" ");
                        printf("%s",argv[3]);
                        for(b=1;b<=(m-strlen(argv[3])-1)/2;b++)
                                printf(" ");
                        printf("*");
                }
	}
        printf("\n");
        for(i=1;i<=m;i++)
                printf("*");
	printf("\n");
        return 0;
}
