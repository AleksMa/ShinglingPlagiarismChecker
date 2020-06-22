#include <stdio.h>
#include <string.h>


int main(int argc, char * argv[])
{
        int i,j,n,k;
        int height,width;
        int len=strlen(argv[3]);
	if (argc!=4)
	{
		printf("ERROR(wrong number of arguments)");
		return 1;
	}
	sscanf(argv[1],"%d",&height);
	sscanf(argv[2],"%d",&width);
	if (height<3||width>80||(len+2)>width)
	{
		printf("ERROR");
		return 1;
	}
	for ( i = 0; i < width; i++)
	{
		printf("*");
	}
	n=(width==(len+2))?0:(width-len-2)/2;
	k=height/2-1;
	printf("\n");
	for (i = 0; i < height-2; i++)
	{
		printf("*");
		for ( j = 0; j < width-2; j++)
		{
			if ((i==k&&j==n))
			{
				printf("%s",argv[3]);
				j+=len-1;
			}
			else
			{
				printf(" ");
			}			
		}
		printf("*\n");

	}
	for ( i = 0; i < width; i++)
	{
		printf("*");
	}
	return 0;
}