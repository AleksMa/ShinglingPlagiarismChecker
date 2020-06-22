#include <string.h>
#include <stdio.h>
int main(int argc, char*argv[]){
        int i, j, col, row;
	if(argc!=4){
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	sscanf(argv[1], "%d", &row);
	sscanf(argv[2], "%d", &col);
	if(row<3||2+strlen(argv[3])>col){
		printf("Error");
		return 0;
	}
	for(i=1;i<=col;i++)
	    putchar('*');
	putchar('\n');
	for(i=2;i<(row+1)/2;i++){
		putchar('*');
		for(j=2;j<col;j++)
		    putchar(' ');
	    putchar('*');
	    putchar('\n');	
	}
	putchar('*');
	for(i=1;i<=(col-2-strlen(argv[3]))/2; i++)
	    putchar(' ');
	printf("%s", argv[3]);
	for(i=1;i<=(col-2-strlen(argv[3])+1)/2;i++)
	    putchar(' ');
	putchar('*');
	putchar('\n');
	for(i=(row+1)/2+1;i<row;i++){
		putchar('*');
		for(j=2;j<col;j++)
		    putchar(' ');
	putchar('*');
	putchar('\n');	
	}
	for(i=1;i<=col;i++)
	    putchar('*');
	putchar('\n');
	}    