
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    int i, j, len, p;
    long height, width;
    char *ch;
    if(argc != 4){printf("usage: frame <height> <width> <text>\n"); return 0;}
    height = strtol(argv[1], &ch, 10);
    width = strtol(argv[2], &ch, 10);
    len = strnlen(argv[3], 100);
    if(len>width-2 || height<3){printf("Error\n"); return 0;}
    
    for(i=0;i<width;i++)
            printf("*");
    printf("\n");
    for(i=2;i<height;i++){
            printf("*");
    	if(i==(height+1)/2){
    		for(j=0;j<(width-2-len)/2;j++)
    			printf(" ");
    		printf("%s", argv[3]);
    		for(j=0;j<((width-2-len)/2)+(width-2-len)%2;j++)
    			printf(" ");
    		
    	}
    	else
    		for(j=1;j<width-1;j++)
    			printf(" ");
    	printf("*\n");
    }
    for(i=0;i<width;i++)
    	printf("*");
    printf("\n");
    return 0;
}
