#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

char *frame(unsigned long a,unsigned long b,char *string)
{
        int i,j,c,l;
	l=strlen(string);
	if ((a<3)||(b<(l+2))){
		printf("Error");
		return 0;
	}
	for (j=0; j<(b-1); j++){
		printf("*");
	}
	printf("*\n");
	c=a/2-(a+1)%2;
	for (i=1; i<(a-1); i++){
		if (i!=c) {
			printf("*");
			for (j=1; j<(b-1); j++)
				printf(" ");
			printf("*");
		}
		else {
			printf("*");
			l=strlen(string);
			for (j=1; j<(b-l)/2; j++)
				printf(" ");
			printf("%s",string);
			for (j=1; j<=(b-(1+(b-l)/2+l)); j++)
				printf(" ");
			printf("*");
		}
		printf("\n");
		}
	for (j=0; j<b; j++)
		printf("*");	
	return 0;
}

int main(int argc, char **argv)
{
	int a,b;
	if (argc!=4)
		printf("Usage: frame <height> <width> <text>");
	else {
		a=atoi(argv[1]);
		b=atoi(argv[2]);
		frame(a,b,argv[3]);
	}
	return 0;
}