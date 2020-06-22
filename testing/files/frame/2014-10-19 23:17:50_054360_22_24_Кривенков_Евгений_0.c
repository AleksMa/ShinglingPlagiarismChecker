#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
char sl[100];
int i,j,x,y;
if(argc<4)
{
        printf("Usage: frame <height> <width> <text>\n");
	return 0;
}
x=atoi(argv[1]);
y=atoi(argv[2]);
if (y-1<=strnlen(argv[3],1000) || x<3)
{
	printf("Error");return 0;
}
i=0;
while(i<y)
{
	printf("*");
	i++;
}
i=0;
while(i<x/2-2+x%2)
{
	printf("\n*");
	j=0;
	while(j<y-2)
	{
		printf(" ");
		j++;
	}
	printf("*");
	i++;
}
printf("\n*");
i=0;
while(i<(y-strnlen(argv[3],1000))/2-1)
{
	printf(" ");
	i++;
}
printf("%s",argv[3]);
i=0;
while(i<(y-strnlen(argv[3],1000))/2-1+(y-strnlen(argv[3],1000))%2)
{
	printf(" ");
	i++;
}
printf("*");
i=0;
while(i<x/2-1)
{
	printf("\n*");
        j=0;
        while(j<y-2)
	{
                printf(" ");
                j++;
        }
	printf("*");
	i++;
}
printf("\n");
i=0;
while(i<y)
{
	printf("*");
	i++;
}
return 0;
}