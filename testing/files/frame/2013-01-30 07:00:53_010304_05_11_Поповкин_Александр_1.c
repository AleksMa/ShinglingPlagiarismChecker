#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NN 100
void prob(int h,int w)
{        
	int k=h-3, i, j;
	for(i=0;i<k/2;i++){
		printf("*");
		for(j=0;j<w-2;j++)
			printf(" ");
		printf("*");
		printf("\n\n");
	}	
}
int main(int argc, char **argv)
{
	int i,k,n, h, w, mark=0;
	char *e;
	if(argc<3) 
        {
                printf("usage: frame <height> <width> <text>\n");
                return 0;
        }
	h=strtol(argv [1], &e, 10);
        w=strtol(argv [2], &e, 10);
	char *string=malloc(NN*sizeof(char));
	strncpy(string, argv[3] ,NN);
	n=strlen(string);
	if (w<n || h<=2) 
        {
                printf("Erro\n");
                return 0;
        } 
        strncpy(string, argv[3] ,NN);
	for(i=0;i<w;i++)
		printf("*");
	printf("\n\n");
	
	if(h%2==0){
		h--;
		mark++;
	}
	prob(h,w);
	printf("*");
	k=(w-n-2)/2;
	for(i=0;i<k;i++)
		printf(" ");
	printf("%s", string);
	if((w-n-2)%2==1)
		printf(" ");
	for(i=0;i<k;i++)
		printf(" ");
	printf("*");
	printf("\n\n");
	if(mark==1)
		h+=2;
	prob(h,w);
	for(i=0;i<w;i++)
		printf("*");
	printf("\n");
	free(string);
	return 0; 
}