#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
        if (argc!=4) {printf("Usage: frame <height> <width> <text>");goto end;}
	int heigh=atoi(argv[1]), width=atoi(argv[2]);
	int n=strlen(argv[3]);
	if (n>width-2||width<3||heigh<3)
		if (n>heigh-2||width<3||heigh<3){printf("Error");goto end;}
		else 
			for(int i=0;i<heigh;i++)
				{for(int j=0;j<width;j++)
					{if (i==0||j==0||i==heigh-1||j==width-1) {printf ("*");continue;}
					if(j==(width-1)/2&&i>=(heigh-n)/2&&i<(heigh+n)/2)
						printf("%c",argv[3][i-(heigh-n)/2]);
					else printf(" ");}
				printf("\n");}
	
	else 
	{
		for(int i=0;i<heigh;i++)
				{for(int j=0;j<width;j++)
					{if (i==0||j==0||i==heigh-1||j==width-1) {printf ("*");continue;}
					if(i==(heigh-1)/2&&j>=(width-n)/2&&j<(width+n)/2)
						printf("%c",argv[3][j-(width-n)/2]);
					else printf(" ");}
				printf("\n");}
	}
	end:
	return 0;
}

