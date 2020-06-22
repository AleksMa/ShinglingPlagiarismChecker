#include <stdio.h>
#include <string.h>

int main ( int argc, char **argv)
{
        int i,l,h,ls,j,k;
	if (argc ==4)
	{
		h=atoi(argv[1]);
		l=atoi(argv[2]);
		ls=strlen(argv[3]);
		if ((ls<=l-2)&&(h > 2))
		{
			k=l-2-ls;
			for (i=0; i<l; i++)
				printf("*");
			printf("\n");
			if (h%2!=0)
			{
				for (i=1; i<(h)/2 ; i++)
				{
					printf("*");
					for (j=0; j<l-2; j++)
						printf(" ");
					printf("*");
					printf("\n");
				}
			}
			else
			{
				for (i=1; i<(h)/2 -1; i++)
				{
					printf("*");
					for (j=0; j<l-2; j++)
						printf(" ");
					printf("*");
					printf("\n");
				}
			}
				
			printf("*");
			for (i=0; i<(k-k%2)/2; i++)
				printf(" ");
			printf("%s", argv[3]);
			for (i=0; i<(k-k%2)/2 + k%2 ; i++)
				printf(" ");
			printf("*");
			printf("\n");
			for (i=1; i<h-((h+h%2)/2); i++)
			{
				printf("*");
				for (j=0; j<l-2; j++)
					printf(" ");
				printf("*");
				printf("\n");
			}
			
			for (i=0; i<l; i++)
				printf("*");
			
		}
		else 
			printf("Error\n");
	}	
	else 
		printf("Usage: frame <height> <width> <text>\n");
	
	return 0;
}

	
	