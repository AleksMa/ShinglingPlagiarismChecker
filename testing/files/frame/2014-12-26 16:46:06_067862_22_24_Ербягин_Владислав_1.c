#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

void main(int agrc, char *argv[])
{ 
        if(agrc!=4)
	{
		printf("Usage: frame <height> <width> <text>");
		return;
	}
	int h = atoi(argv[1]);
	int l = atoi(argv[2]);
	char *str = argv[3];

	if(h<3)
	{
		printf("Error");
		return;
	}
	if(l < strlen(str)+2)
	{
		printf("Error");
		return;
	}
	int i,j,la,lb;
	int len = strlen(str);
	int c_p = l-len-2;
	la=c_p/2;
	lb = c_p/2;
	if(c_p%2==1)
		lb++;
	for(i=0;i<l;i++)
		printf("*");
	printf("\n");

	for(i=1;i<h-1;i++)
	{
		printf("*");
		if((h%2 == 0 && i==(h/2-1))||(h%2 == 1 && i==h/2))
		{
			for(j=0;j<la;j++)
				printf(" ");
			printf(str);
			for(j=0;j<lb;j++)
				printf(" ");
		}
		else
		{
			for(j=0;j<l-2;j++)
				printf(" ");
		}




		printf("*\n");
	}
	for(i=0;i<l;i++)
		printf("*");
}