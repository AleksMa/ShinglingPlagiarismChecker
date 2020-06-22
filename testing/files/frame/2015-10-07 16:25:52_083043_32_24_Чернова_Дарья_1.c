#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//рисование рамки
int main(int argc, char **argv)
{
        if (argc != 4) printf("Usage: frame <height> <width> <text>\n"); else 
	if ((atoi(argv[1]) < 3) || ((atoi(argv[2])- 2) < strlen(argv[3]))) printf("Error\n"); 
	else
	{
		
	int i = 0, j = 0;//i - строки, j - столбцы
	int k = (atoi(argv[1])-1)/2;
	int l = (atoi(argv[2]) - 2 - strlen(argv[3]));
	int m = l/2;
	l = l-m;
	for (i = 0; i < atoi(argv[2]); i++) printf("*");
	printf("\n");
	for (i = 1; i < atoi(argv[1]) - 1; i++){
		
				if (i != k)
						for (j = 0; j < atoi(argv[2]); j++)
						if ((j == 0) || (j == atoi(argv[2])-1)) printf("*");
					    else printf(" "); 
					else if (i == k) {
						printf("*");
						for (j = 0; j < m; j++) printf(" ");
						printf("%s", argv[3]);
						for (j = 0; j < l; j++) printf(" ");
						printf("*");
					}
						
					printf("\n");
				}
			
	for (i = 0; i < atoi(argv[2]); i++) printf("*");
printf("\n");
}
return 0;
}