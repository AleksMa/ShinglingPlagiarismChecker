#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv){
        char *e, *text1,*text2;
	int i;
	int height = strtol( argv[1], &e, 10);
	int width = strtol( argv[2] , &e, 10);
	int textof = strlen (argv[3]);
	if (argc != 4){
		printf ("usage: frame <height> <width> <text>\n");
		return 0;
	}
	if (width < textof+2 || height <= 2 ){
		printf ("Error\n");
		return 0;
	}
	text1 = (char*)malloc(width+1);
	text2 = (char*)malloc(width+1);
	
	for (i=0; i<width; i++)
		text1[i]='*';
	text1[width]='\0';
	
	for (i=0; i<width;i++)
		text2[i]=' ';
	text2[0]='*';
	text2[width-1]='*';
	text2[width]='\0';
	
	printf ("%s\n", text1);

	for (i=(height-3)/2;i>0;i--)
		printf ("%s\n", text2);

	printf("*");
	for (i=(width-textof-2)/2; i>0; i--)
		printf(" ");
	printf ("%s", argv[3]);
	for (i=(width-textof-2) - (width-textof-2)/2; i>0;  i--)
		printf(" ");
	printf("*\n");

	for (i=height -3  - (height - 3)/2; i>0; i--)
	        printf ("%s\n", text2);

	printf ("%s\n", text1);

	free (text1);
	free (text2);
	return 0;
}