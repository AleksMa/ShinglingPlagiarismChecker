#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int main(int argc, char *argv[])
{
        int i,h,g,z;
	if (argc!=4)printf("Usage: frame <height> <width> <text>");
	g=(atoi(argv[1])%2==0)? atoi(argv[1])/2:atoi(argv[1])/2+1;
	if(argc==4){
		if ((atoi(argv[1])<3) || ((atoi(argv[2])-2)<(strlen(argv[3]))))printf("Error");
		if ((atoi(argv[1])>2) && ((atoi(argv[2])-2)>(strlen(argv[3]))-1)){
			for (h=1;h<=atoi(argv[1]);h++){
				for (i=1;i<=atoi(argv[2]);i++){
					if ((h==1)||(h==atoi(argv[1]))){
						(i==atoi(argv[2]))? printf("*\n"):printf("*");}
					else if (h==g){
						if(i==1)printf("*");

						for(z=0;z<(atoi(argv[2])-2-strlen(argv[3]))/2;z++)printf(" ");
						if(z==(atoi(argv[2])-2-strlen(argv[3]))/2)printf("%s",argv[3]);
						for(z=((atoi(argv[2])-2-strlen(argv[3]))/2)+strlen(argv[3]);z+2<atoi(argv[2]);z++)printf(" ");
						i=(atoi(argv[2]));	
						if(i==atoi(argv[2]))printf("*\n");
					}
					else{
						(i==1)?printf("*"):(i==atoi(argv[2]))? printf("*\n"):printf(" ");
					}
				}
			}
		}
	}	
	return 0;
}