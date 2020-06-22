#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
        int i,j,h,w,q1;
        if(argc!=4)
	{
		printf("Usage: frame <height> <width> <text>\n");
		return -1;
	}
	h=atoi(argv[1]);
	w=atoi(argv[2]);
	if(h<3)
	{    
	   if(argc!=4)
	   {
	      printf("Usage: frame <height> <width> <text>\n");
		return -1;
	   }
	   else
		printf("Error\n");
		return -1;
	}
	if(w<strlen(argv[3])+2)
	{
		printf("Error\n");
		return -1;
	}
	for(i=0;i<w;i++)
		printf("*");
	printf("\n");
	q1=(h-2)/2-!(h&1);
	for(i=0;i<q1;i++)
	{
		printf("*");
		for(j=0;j<w-2;j++)
			printf(" ");
		printf("*\n");
	}
	printf("*");
	for(i=0;i<((w-2)-strlen(argv[3]))/2;i++)
		printf(" ");
	printf(argv[3]);
	for(i=0;i<w-2-strlen(argv[3])-((w-2)-strlen(argv[3]))/2;i++)
		printf(" ");
	printf("*\n");


	for(i=0;i<h-2-q1-1;i++)
	{
		printf("*");
		for(j=0;j<w-2;j++)
			printf(" ");
		printf("*\n");
	}


	for(i=0;i<w;i++)
		printf("*");
	printf("\n");

	return 0;
}