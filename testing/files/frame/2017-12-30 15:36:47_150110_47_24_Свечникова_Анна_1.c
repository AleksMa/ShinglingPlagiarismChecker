#include<stdio.h>
#include<string.h>

int main( int argc, char **argv)
{
        if(argc!=4){
		printf("%s", "Usage: frame <height> <width> <text>");
		return 0;
	}
	int n=strlen(argv[3]);
	int h=atoi(argv[1]);
	int w=atoi(argv[2]);
	if((h<3)||(n>w-2)){
		printf("%s", "Error");
		return 0;
	}
	int y=h/2;
	if(h%2==0) --y;
	int x=w/2-n/2;
	if(w%2==0){
		--x;
		if(n%2==0) ++x;
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if((i==y)&&(j==x)){
				printf("%s", argv[3]);
				j+=(n-1);
			}
			else{
				if((i==0)||(i==h-1)) printf("*");
				else
					if ((j==0)||(j==w-1)) printf("*");
					else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
