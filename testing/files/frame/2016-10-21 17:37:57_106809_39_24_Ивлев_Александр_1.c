#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
        int i, k, hight=atoi(argv[1]), width=atoi(argv[2]),center=(hight-1)/2;
	if(argc!=4){
		printf("Usage: frame <height> <width> <text>\n");
		return -1;
	}
	if(strlen(argv[3])>width-2 || hight<3){
		printf("Error\n");
		return -1;
	}
	for(i=0;i<hight;i++){
		if(i==0 || i==hight-1){
			 for(k=0;k<width;k++) printf("*");
		}else{
			if(i==center){
				for(k=0;k<width;k++){
					if(k==0 || k==width-1) printf("*");
					else{
						if(k==(width-strlen(argv[3]))/2){
							printf("%s",argv[3]);
							k+=strlen(argv[3])-1;
						} else printf(" ");
					}
				}
			}
			else{
				for(k=0;k<width;k++){
					if(k==0 || k==width-1) printf("*");
					else printf(" ");
				}
			}
		}
		printf("\n");
	}
}
