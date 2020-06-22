#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
        char sl[100];
	int i,j,a,b;
	if(argc<4){
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	if (b-1<=strnlen(argv[3],1000) || a<3){printf("Error");return 0;}
	for(i=0;i<b;i++){
		printf("*");
	}
	for (i=0;i<a/2-2+a%2;i++){
		printf("\n*");
		for(j=0;j<b-2;j++){printf(" ");}
		printf("*");
	}
	printf("\n*");
	for (i=0;i<(b-strnlen(argv[3],1000))/2-1;i++){printf(" ");}
	printf("%s",argv[3]);
	for (i=0;i<(b-strnlen(argv[3],1000))/2-1+(b-strnlen(argv[3],1000))%2;i++){printf(" ");}
	printf("*");
	for (i=0;i<a/2-1;i++){
		printf("\n*");
		for(j=0;j<b-2;j++){printf(" ");}
		printf("*");
	}
	printf("\n");
	for(i=0;i<b;i++){
		printf("*");
	}
	return 0;
}