#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc!=4) printf("%s\n", "Usage: frame <height> <width> <text>");
    else if ((atoi(argv[1])<3) || (atoi(argv[2])<(strlen(argv[3])+2))) printf("%s\n", "Error");
    else {
        int height=atoi(argv[1]), width=atoi(argv[2]), i, j;
        char *text=argv[3];
        int cy=(height-2)/2+(height-2)%2, cx=(width-2-strlen(text))/2;
        for(i=0; i<width; i++)
            printf("%c", '*');
	printf("\n");
	for(i=1; i<cy; i++)
	{
		printf("%c", '*');
		for(j=0; j<width-2; j++)
			printf("%c", ' ');
		printf("%c\n", '*');
	}
	printf("%c", '*');
	for(i=0; i<cx; i++)
		printf("%c", ' ');
	printf("%s", text);
	for(i=0; i<cx+(width-2-strlen(text))%2; i++)
		printf("%c", ' ');
	printf("%c\n", '*');
	if((height-2)%2==0) for(i=1; i<=cy; i++)
	{
		printf("%c", '*');
		for(j=0; j<width-2; j++)
			printf("%c", ' ');
		printf("%c\n", '*');
	}
	else for(i=1; i<cy; i++)
	{
		printf("%c", '*');
		for(j=0; j<width-2; j++)
			printf("%c", ' ');
		printf("%c\n", '*');
	}
	for(i=0; i<width; i++)
		printf("%c", '*');				

    }
    return 0;
}