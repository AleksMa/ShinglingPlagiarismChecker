#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void drawFrame(int h, int w, const char *str)
{
        int hmid=h/2, wsp=(w-strlen(str)-2)/2, i, j;
	if ((w<strlen(str)+2)||(h<3)) 
	{
		printf("Error\n");
		return;
	}
	
	for (i=0; i<h; i++) 
	{
		printf("\n*");
		for (j=1; j<w; j++) 
		{
			if ((i==0)||(i==h-1)||(j==w-1)) printf("*");
			else if ((i!=hmid)||((i==hmid)&&
                                ((j<=wsp)||j>=w-wsp-2))) printf(" ");
			     else 
					{
						 printf("%s",str);
						 j+=strlen(str)-1;
					}
		}
	}
	puts("\n");
	return;
}

int main (int argc, const char ** argv) 
{
	char *e;
	if (argc<4) 
	{
		printf("Usage: <heigth> <width> <text>\n");
		return 0;
	}
	drawFrame(strtol(argv[1],&e,10), strtol(argv[2],&e,10), argv[3]);
	return 0;
}

