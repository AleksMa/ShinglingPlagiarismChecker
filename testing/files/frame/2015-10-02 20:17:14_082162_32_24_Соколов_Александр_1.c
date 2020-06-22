#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
        int x,y,xc,yc,i;
        if (argc != 4) 
		printf("Usage: frame <height> <width> <text>\n");
	else if (atoi(argv[1])<3 || (atoi(argv[2]) - 2) < strlen(argv[3])) 
		printf("Error\n");
	else
	{
		xc = (atoi(argv[2])-strlen(argv[3]))/2;  
		yc = atoi(argv[1]) / 2 ;	

		if (atoi(argv[1]) % 2 !=0) 
			++yc;

		for (y = 1; y <= atoi(argv[1]); ++y) 
		{	

			for (x = 0; x < atoi(argv[2]); ++x) 
			{
				if ( (y==1) || (y==atoi(argv[1])) )
				{	printf("*");
					continue;
				}				
				if (x == 0) 
				{	
					printf("*");
					continue;
				}
				if (x == atoi(argv[2])-1) 
				{
					printf("*");
					continue;
				}
				if ((y == yc) && x >= xc  &&  (x < xc + strlen(argv[3])) )
				{
					printf("%s", argv[3]);
					x+=strlen(argv[3])-1;
					continue;
				}
				else 
				{
					if(x<xc)
					{	for(i=x;i<xc;++i)
							printf(" ");
						x=xc-1;
						continue;
					}
					else
					{
						for(i=x;i<atoi(argv[2])-1;++i)
							printf(" ");
						x=atoi(argv[2])-2;
						continue;
					}
				}
			}
		
			printf("\n");
		}

	}
}