#include <stdio.h>
#include <string.h>
 
int main(int argc, char **argv) 
{
        int height,width,l,i=0,j=0;
	if(argc!=4)
	{
		printf("Usage: frame <height> <width> <text>\n");
		return 0; 
	}
	height=atoi(argv[1]);width=atoi(argv[2]);
	l=strlen(argv[3]);
	if(height<3 || width<(l+2))
	{
		printf("Error\n");
		return 0; 
	}
	for(;i<width;i++) printf("*"); printf("\n");
	for(i=0;i<height-2;i++)
	{
		printf("*");
		if(i==(height-3)/2)
		{
			for(j=0;j<(width-2-l)/2;j++) printf(" ");
			printf("%s",argv[3]);
			for(j=0;j<width-2-l-(width-2-l)/2;j++) printf(" ");
		}
		else for(j=0;j<width-2;j++) printf(" ");
		printf("*\n");
	}	
	for(i=0;i<width;i++) printf("*"); printf("\n");
	return 0;
}
