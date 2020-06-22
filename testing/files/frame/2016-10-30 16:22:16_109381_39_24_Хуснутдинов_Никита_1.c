#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
        int w, h;
	char* s;
	
	if(argc!=4){
		printf("Usage: frame <height> <width> <text>\n");
		return -1;
	}
	
	h=atoi((char*)argv[1]);
	w=atoi((char*)argv[2]);
	s=(char*)argv[3];	
	if(w<=2 || h<3 || strlen(s)+2>w){
		printf("Error\n");
		return -1;
	}
	
	h=h-1;
	
	int hs=w/(h);
	if(hs==0) hs=1;
	
    int i,j;
    int si;
    if ((strlen(s)==1)||(strlen(s)%2==0)) si=(w/2-strlen(s)/2);
        else si=(w/2-strlen(s)/2)-1;
        char* so=(char *)malloc(w+1);
	
	//1
	so[w]='\0';
	
	memset(so, '*', w);

	printf("%s\n",so);
	
	for(i=1;i<h;i++){
		memset(so, ' ', w);
			     so[0]='*';
		
		if(i==h/2){
                        
			strncpy(&so[si], s, strlen(s));
		}
    
		so[w-1]='*';
		
		printf("%s", so);
		printf("\n");
	}
	
	//3
	memset(so, '*', w);
	printf("%s\n", so);
	
	free(so);
	return 0;
}