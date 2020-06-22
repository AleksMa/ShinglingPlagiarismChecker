#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) 
{ 
        char *e;
	int h,w,i,j;
	if(argc!=4) {printf("Usage: frame <height> <width> <text>"); return 0;}
	h=strtol(argv[1],&e,10);
	w=strtol(argv[2],&e,10);
	if(h<3 || w<(strlen(argv[3])+2)) {printf("Error"); return 0;}
	h-=3;
	for(i=0;i<w;i++) printf("*");
	printf("\n");
	for(i=0;i<h/2;i++) 
	{
		printf("*");
		for(j=0;j<w-2;j++) printf(" ");
		printf("*\n");
	}
	printf("*");
	for(i=0;i<(w-2-strlen(argv[3]))/2;i++) printf(" ");
	printf("%s",argv[3]);
	for(i=(w-2-strlen(argv[3]))/2;i<(w-2-strlen(argv[3]));i++) printf(" ");
	printf("*\n");
	for(i=h/2;i<h;i++) 
	{
		printf("*");
		for(j=0;j<w-2;j++) printf(" ");
		printf("*\n");
	}
	for(i=0;i<w;i++) printf("*");
	printf("\n");
	return 0;
}