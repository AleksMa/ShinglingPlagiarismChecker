#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char** argv)
{        
        if((argc>5) ||(argc<4) ){
        	printf("Usage: frame <height> <width> <text>");
		return 1;
	}
        int i,i1,k,tar;
	int len=strlen(argv[3]);
	char* s =calloc(len+1,sizeof(char)); 
	int b =	atoi(argv[2]);
	int f = atoi(argv[1]);
	int t1,t2;
	int zaz;
	if((f<=2)||((b-2)<len)){
		printf("Error");
                free(s);
		return 1;
	}
	else{ 
		for(i=0; i<f; i++){
			if ((i==0) ||(i==(f-1))){//print str with star*
				for(k=0; b>k; k++){
					printf("*");
					if(k==b-1)
						printf("\n");
				}
			}
			
			
			tar=(f-1)/2;
			if((i!=0)&&(i!=f-1)&&(i!=tar)){
				for(i1=0; i1<b; i1++){			
					if ((i1==0 )|| (i1==b-1))
						printf("*");
					else printf(" ");
				}
                        	printf("\n");
			}
			if(i==tar){
				printf("*");
				zaz=(b-len-2)/2;
				for(t2=0; t2<zaz; t2++)
					printf(" ");
				printf("%s", argv[3]);
				for(t1=0; t1<(zaz + ((b-len-2)%2)); t1++)
					printf(" ");
				
				printf("*\n");
			}	
		}	
	}	
	free(s);
	return 0;		
}