
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    int height=0 , width=0 , i=0 , j=0, probeli=0,m=0,n=0,probel1=0,probel2=0;
        if (argc != 4) {
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	height=(atoi(argv[1]));
	width=(atoi(argv[2]));
	probeli=(width-2-(strlen(argv[3])));
	probel1=probeli/2;
	probel2=probeli-probel1;
	if ((width<(strlen(argv[3])+2)) || (height<3)){
		printf("Error");
		return 0;
	}
	for(i=1;i<=height;i++){
		if (i==1||i==height){
			for(j=1;j<=width;j++) printf("*");
			printf("\n");
		}
		if ((i>1)&&(i<height)&&(i!=(1+height)/2)){
			for(j=1;j<=width;j++){
				if (j==1) printf("*");
				else if (j==width) {
					printf("*");
					printf("\n");
				}else printf(" ");
			}
		}
		if (i==(1+height)/2){
			for(j=1;j<=width;j++){
				if (j==1) printf("*");
				else if (j==width) {
					printf("*");
					printf("\n");
				}else if (probeli==0) {
					printf("%s",*(argv+3));
					j=width-1;
				}else {
					for(m=0;m<probel1;m++) printf(" ");
					printf ("%s", *(argv+3));
					for(m=0;m<probel2;m++) printf(" ");
					j=width-1;     
				}
			}
		}
	}
	return 0;
}