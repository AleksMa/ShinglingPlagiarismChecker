#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
void line(int n)
{
        for (int i=0;i<n;i++)
                printf("*");
        printf("\n");
}
void two(int width)
{
        for (int j=0;j<width;j++)
                if (j==0 || j==width-1)
                        printf("*");
                else printf(" ");
        printf("\n");
}
int main (int argc,char **argv)
{
        if (argc!=4){
        	printf("Usage: frame <height> <width> <text>\n");
        	return 0;
        }
        int height=atoi(argv[1]);
        int width=atoi(argv[2]);
        int length=strlen(argv[3]);
        if (width-2<length || height<3){
        	printf("Error\n");
        	return 0;
        }
        int k=width-2-length;
        line(width);
        if (height%2==0)
        	for (int j=0;j<height/2-2;j++)
        	        two(width);
        else 
        	for (int j=0;j<height/2-1;j++)
                	two(width);	
        printf("*");
        for (int j=0;j<width;j++)
        	if (j<k/2)
        	        printf(" ");
        	else {
        		printf("%s" ,argv[3]);
        		k=j;
        		break;
        	}	
        for (int i=k;i<width;i++)
        	if (i+length!=width-2)
        	        printf(" ");
        	else printf("*");
        printf("\n");
        for (int j=0;j<height/2-1;j++)
                two(width);
        line(width);
        return 0;
}
