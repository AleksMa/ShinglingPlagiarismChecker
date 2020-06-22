#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
        if (argc != 4){
                printf("Usage: frame <height> <width> <text>\n");
                return 0;
        }int h=atoi(argv[1]);
        int w=atoi(argv[2]);
        int i,j;
        if ((h<3)||(w<(strlen (argv[3])+2))){
    	        printf("Error");
    	        return 0;
	} for (i=0;i<w;i++) printf("*");
	printf("\n");
	for (i=1;i<h-1;i++){  
                if (((i==h/2)&&(h%2==1))||((i==h/2-1)&&(h%2==0))){
			printf("*");
			for (j=0;j<(w-(strlen (argv[3]))-2)/2;j++) printf(" ");
			printf("%s",(argv[3]));
			for (j;j<(w-(strlen (argv[3]))-2);j++) printf(" ");
			printf("*\n");
		} else { 
                        printf("*");
			for(j=1;j<w-1;j++) printf(" ");
			printf("*\n");
		}      	
	}for (i=0;i<w;i++) printf("*");
	printf("\n");
	return 0;
	}  