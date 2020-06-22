#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000

int main(int argc, char **argv){
    
    if(argc!=4) printf("Usage: frame <height> <width> <text>\n");
    else{
        int h = atoi(argv[1]);
	int w = atoi(argv[2]);
	int l = strnlen(argv[3],MAXLEN);

	if((h<3) || ((w-l) < 2)) printf("Error\n");
	else{
	    int j;
	    
	    for(j=0;j<w;j++) printf("*");
	    printf("\n");
	    
	    int print=1+((h-1)/2), blank=((w-l)-2)/2;
	    int i;
	    
	    for(i=2; i<print; i++){
		printf("*");
		for(j=0;j<(w-2);j++) printf(" ");
		printf("*");
		printf("\n");	
	    }
	    
	    printf("*");
	    for(j=0;j<blank;j++) printf(" ");
	    printf("%s", argv[3]);
	    for(j=0;j<(w-2)-(blank+l);j++) printf(" ");
	    printf("*");
	    printf("\n");	
	    
	    for(i=print+1;i<h; i++){
		printf("*");
		for(j=0;j<(w-2);j++) printf(" ");
		printf("*");
		printf("\n");			
	    }
	    
	    for(j=0;j<w;j++) printf("*");
	    printf("\n");    
	}
    }
    return 0;
}