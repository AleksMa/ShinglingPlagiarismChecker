
#include <stdio.h>
#include <string.h>

int main(int argc,char **argv)
{
        if (argc != 4) printf("Usage: frame <height> <width> <text>\n");
	else if ((atoi(argv[2])-2 < strlen(argv[3])) || (atoi(argv[1]) < 3)) printf("Error\n");
		else {
			int i,j;
			int length=atoi(argv[2]),width=atoi(argv[1]);
			for(i=1;i<=length;i++) printf("*");
			printf("\n");
			int ins;
			if (width%2) ins=(width-2)/2+1;
			else ins=(width-2)/2;
			for(i=1;i<ins;i++){
				for(j=1;j<=length;j++)
					if(j==1 || j==length) printf("*");
					else printf(" ");
				printf("\n");
			}
			for(i=1;i<=length;i++){
				if (i==1 || i==length) printf("*");
				else if (i==(length-strlen(argv[3]))/2+1){
						printf(argv[3]);
						i+=strlen(argv[3])-1;
					} else printf(" "); 
			}
			printf("\n");
			for(i=ins;i<width-2;i++){
				for(j=1;j<=length;j++)
					if(j==1 || j==length) printf("*");
					else printf(" ");
				printf("\n");
			}
			for(i=1;i<=length;i++) printf("*");
			printf("\n");
		}	
	return 0;	
}			