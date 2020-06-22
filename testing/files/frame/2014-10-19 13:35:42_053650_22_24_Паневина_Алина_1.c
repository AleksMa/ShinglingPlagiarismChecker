#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
        
        if (argc != 4)
		printf("Usage: frame <height> <width> <text>\n");
                
	else {
		int height, width, length,i,e,c,j=0;
		char *text;
		height = atoi(argv[1]);
		width = atoi(argv[2]);
		text = argv[3];
		length = strlen(text);
	                if ((width-1<=length) || (height<=2))
		                printf("Error\n");
	                else{
	                	for(i=0;i<width;i++)
		                	printf("*");
	                        printf("\n");
                                
                                if ((height%2)==0)
                                        c=height/2;
                                else 
                                        c=(height+1)/2;
                
                                while (j<c-2) {
	                	        printf("*");
		                        for(i=1;i<=width-2;i++)
			                        printf(" ");
	                        	printf("*\n");
	                	        j++;
	                        }
                                
                	        printf("*");
                                
                                if (((width-2-length)%2)==0)
                                        e=(width-2-length)/2;
                                else 
                                        e=(width-2-length-1)/2;
                        	
                                for(i=0;i<e;i++)
		                         printf(" ");
                        	printf("%s", text);
	                        for (i=(e+length+1);i<width-1;i++)
	                	        printf(" ");
	                        printf("*");
                	        printf("\n");
                                
                                j=0;	 
                                while (j<(height-c-1)) {
		                	printf("*");
			                for(i=1;i<=width-2;i++)
			                	printf(" ");
		                	printf("*\n");
			                j++;
	                        }
                        
                                for(i=0;i<width;i++)
	                        	printf("*");	
	                }
	}
	return 0;
}