#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
        int height=0, width=0, length=0;
        int str=0, f1=0, f2=0;
        int i=0, k=0;
        if(argc!=4)
        {
             printf("Usage: frame <height> <width> <text>\n");
	     exit(0);
        }
        sscanf(argv[1], "%d", &height);
        sscanf(argv[2], "%d", &width);
        length=strlen(argv[3]);
        if(length>(width-2) || height<=2)
        {
	     printf("Error\n");
	     exit(0);
        }
        if(height%2==1) str=height/2;
        else str=height/2-1;
        f1=(width-2-length)/2;
        f2=width-2-length-f1;
        for(i=0; i<height; i++)
        {
	     printf("*");
	     if(i==0 || i==height-1)
	     {
		  for(k=0; k<width-2; k++) printf("*");
	     }
	     else if(i==str)
	     {
		  for(k=0; k<f1; k++) printf(" ");
		  printf("%s", argv[3]);
		  for(k=0; k<f2; k++) printf(" ");
	     }
	     else for(k=0; k<width-2; k++) printf(" ");
	     printf("*\n");
        }
        return 0;
}