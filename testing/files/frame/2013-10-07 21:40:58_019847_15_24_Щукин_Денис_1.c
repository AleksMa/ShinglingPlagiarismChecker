#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc ,char **argv)
{
        char s[100];
        int i,n,length, ld2,height, width,hstr,hstrr;
	//scanf("%d %d %s", &height, &width, s);
	height=atoi(argv[1]);
	width=atoi(argv[2]);
	if(argc <= 3){
        	printf("Usage: frame <height> <width> <text>\n");
        	return 0;
	}else{
	        length=strlen(argv[3]);
	        //printf("height = %d\n", height);
	        //printf("length = %d\n", length);
	        //printf("width = %d\n", width);
	        if((height<3) || (length>width-2)) printf("Error\n");
	        else{
	                ld2=(width-length)/2;
	                hstr=height/2;
	                for(i=0;i<width-1;i++) printf("*");
	                printf("*\n");
	                if(height%2==0)hstrr=hstr;
	                else hstrr=hstr+1;
	                while(hstrr>2){
	                        printf("*");
	                        for(i=0;i<width-2;i++) printf(" ");
		                printf("*\n");
		                hstrr--;
	                }
	                printf("*");
	                if((width-length)%2!=0){
	                        for(i=0;i<ld2-1;i++) printf(" ");
	                        printf("%s",argv[3]);
	                        for(i=0;i<ld2;i++) printf(" ");
	                        printf("*\n");
	                }else{
	                         for(i=0;i<ld2-1;i++) printf(" ");
	                        printf("%s",argv[3]);
	                        for(i=0;i<ld2-1;i++) printf(" ");
	                        printf("*\n");}
	                	while(hstr>1){
	                	printf("*");
	                	for(i=0;i<width-2;i++) printf(" ");
	                	printf("*\n");
	                	hstr--;
	        	}
	                for(i=0;i<width;i++) printf("*");
	        }
	}

	return 0;
}
