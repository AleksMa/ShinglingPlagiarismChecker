#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int arg_n, char* arg_c[]) 
{
        if(arg_n!=4)
        {
                printf("Usage: frame <height> <width> <text>");
                return 0;
        }
        int n=atoi(arg_c[1]);
        int m=atoi(arg_c[2]);
        int l=strlen(arg_c[3]);
        if( n<3 || m<l+2 ) 
        {
        	printf("Error");
        	return 0;
        }
        for(int i=0;i<m;i++)
        	printf("*");
        printf("\n");
        int istr=(n-1)/2;
        int jspace1=(m-2-l)/2;
        for(int i=1;i<n-1;i++)
        	if(i==istr)
        	{
        		printf("*");
        		for(int j=0; j<jspace1; j++)
        			printf(" ");
        		printf("%s",arg_c[3]);
	        	for(int j=0; j<m-2-l-jspace1; j++)
			printf(" ");
	        	printf("*\n");
	        }
	else
	{
		printf("*");
		for(int j=0; j<m-2; j++)
			printf(" ");
		printf("*\n");
	}
        for(int i=0;i<m;i++)
        	printf("*");
        printf("\n");
}