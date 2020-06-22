#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
        int i=0,j=0,k=0;
	if (argc != 4)
		printf ("Usage: frame <height> <width> <text>");
	else
	{
		if (((int)(strlen(argv[3]))>(atoi(argv[2])-2))||(atoi(argv[1])<3))
			printf ("Error");
		else
		{
			for (i=0;i<( (atoi(argv[1])/2)+(atoi(argv[1])%2-1)) ;i++)
			{
				if (i==0)
				for (j=0;j<atoi(argv[2]);j++)
					printf("*");
				else 
				{
					printf("*");
					for (k=1;k<atoi(argv[2])-1;k++)
					printf(" ");
					printf("*");
				}
				printf("\n");
			}
			printf("*");
			for (i=1;i<((atoi(argv[2])-(strlen(argv[3])))/2);i++)
				printf(" ");
			printf("%s",argv[3]);
			for (i=(((atoi(argv[2])-(strlen(argv[3])))/2)+(strlen(argv[3])));i<atoi(argv[2])-1;i++)
				printf(" ");
			printf("*\n");
			for (i=( (atoi(argv[1])/2)+1+(atoi(argv[1])%2-1));i<atoi(argv[1]);i++)
			{
				if (i==(atoi(argv[1])-1))
				for (j=0;j<atoi(argv[2]);j++)
					printf("*");
				else 
				{
					printf("*");
					for (k=1;k<atoi(argv[2])-1;k++)
					printf(" ");
					printf("*");
				}
				printf("\n");
			}
		}
	}
				
 return 0;
}