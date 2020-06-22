#include <stdio.h>
#include <string.h>
 
int main (int argc, char **argv)
{
        int m,n,i=0,j,mm,h,k;
	m=atoi(argv[1]);
	n=atoi(argv[2]);
	mm=(m-2)/2+(m-2)%2;
	if(mm==0)mm=1;
	if(argc-1<3){
		printf("Usage: frame <height> <width> <text>\n");
		return 0;
	}
	if(m<3||n<strlen(argv[3])+2){
		printf("Error\n");
		return 0;
	}
	h=(n-2-strlen(argv[3]))/2;
	if((n-2-strlen(argv[3]))%2==0)k=h;
	else k=h+1;
	for(i=0;i<n;i++)printf("*");
	printf("\n");
	for(i=0;i<m-2;i++){
		if(i==mm-1){
			printf("*");
			for(j=0;j<h;j++)printf(" ");
			printf("%s",argv[3]);
			for(j=0;j<k;j++)printf(" ");
			printf("*\n");
		}
		else{
		printf("*");
		for(j=0;j<n-2;j++)printf(" ");
		printf("*\n");
		}
	}	
	for(i=0;i<n;i++)printf("*");
	printf("\n");
	return 0;
}
				