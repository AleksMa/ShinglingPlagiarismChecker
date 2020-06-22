#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
void stroka (int width) ;
void first_and_final_strok(int width) ;
int main (int argc, char **argv)
{
int height = atoi(argv[1]) , width = atoi(argv[2]) ;
int sum ; 
        int e = argc;
        if ( argc < 4 ) printf("Usage: frame <height> <width> <text>\n");
	else {
		int lenght = strlen(argv[3]), t, r ;
		if (lenght > width - 2 || atoi(argv[2]) < 3 || height < 3) printf("Error\n");
		else {
			int res = (height - 3 )/2 ;
			first_and_final_strok(width);
			for (; res > 0; res--)
		        	stroka(width);
			printf("*"); 
			r = t = ((width - lenght) / 2 ) -1; 
			for( ; r > 0; r--)
				printf(" ") ; 
			printf("%s",argv[3]); 
			if( (width - lenght - 1 ) % 2 == 0) t = t + 1;
			for( ; t > 0; t--)
				printf(" ") ;
                        printf("*") ; 
			printf("\n");
			for(res = (height-2)/2 ; res > 0 ;res-- )
		        	stroka(width);
			first_and_final_strok(width);
		     } 
	     }
}
	 
void first_and_final_strok(int width) //верхняя и нижняя рамка
{
    int i = 0;
    for (i = 0; i < width; i++)
          printf("*");
    printf("\n");
}
 
void stroka (int width)  //пустые строки, вроде такой: *         *
{
        int i;
        printf("*");
        for (i = 0; i < width - 2; i++)
            printf(" ");
        printf("*");
        printf("\n");
    
}