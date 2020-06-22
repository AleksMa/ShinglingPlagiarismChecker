#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
        if (argc != 4) printf("Usage: frame <height> <width> <text>\n"); else
	if (atoi(argv[1]) < 3) printf("Error\n"); else
	if (atoi(argv[2]) - 2 < strlen(argv[3])) printf("Error");else{
        
	int i = 0, j = 0, a, b, c;
	for (i = 0; i < atoi(argv[2]); i++) printf("*");
        printf("\n");
        a = ((atoi(argv[1]) + 1)/2) - 1;
        b = (atoi(argv[2]) - 2 - strlen(argv[3]));
        c = b/2;
        b= b -c;
        //printf ("%d %d %d \n", a, b, c);
	for (i = 1; i < atoi(argv[1]) - 1; i++){
                
		if (i == a){
                     printf("*");
                     for (j = 0; j < c; j++)
                         printf(" ");
                     printf("%s", argv[3]);
                     for (j = 0; j < b; j++)
                         printf(" ");
                     printf("*");
                     printf("\n");}
		else { 
			for (j = 0; j < atoi(argv[2]); j++)
				if ((j == 0) || (j == atoi(argv[2])-1)) printf("*"); 
				else printf(" ");
 			printf("\n");}
        }
	for (i = 0; i < atoi(argv[2]); i++) printf("*");
	printf("\n");}
	
}