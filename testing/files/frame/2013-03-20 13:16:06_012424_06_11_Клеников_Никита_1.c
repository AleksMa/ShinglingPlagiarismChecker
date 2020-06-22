#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int main(int argc, char **argv)
{
    int i, j, k, height, width, length, q, len;
        char **matrix, *o;

	if (argc != 4)
	{
		printf("usage: frame <height> <width> <text>\n");
		return 0;
	}

	len = strnlen(argv[3],MAX);
	
	height = (int)strtol(argv[1],&o,10);
	width = (int)strtol(argv[2],&o,10);
	length = strnlen(argv[3],MAX);
	q = (width - len)/2;
	
	
	if((length > width-2)||(height < 3))
	{
		printf("ERROR\n");
		return 0;
	}
	matrix = (char**)malloc(height*sizeof(char*));
	for(i=0;i<height;i++)
		matrix[i]=(char*)malloc((width+1)*sizeof(char));
	for(i=0;i<width;i++)
		matrix[0][i] = '*';
	for(i=0;i<height;i++)
		matrix[i][0] = '*';
	for(i=0;i<height;i++)
		matrix[i][width-1] = '*';
	for(i=0;i<width;i++)
		matrix[height-1][i] = '*';
	for(i=1;i<height-1;i++)
		for(j=1;j<width-1;j++)
			matrix[i][j] = ' ';
	for(k=q;k<(q+len);k++)
	    matrix[height/2][k] = argv[3][k-q];
	/*for(i=1;i!=length;i++)
	if(((width - length) % 2) == 0)
		strncpy(matrix[height/2]+(width-length)/2,argv[3],MAX);
	if(((width - length) % 2) != 0)
		strncpy(matrix[height/2]+(width-length)/2+1,argv[3],MAX);*/
	for(i=0;i<height;i++)
		matrix[i][width] = '\0';
	 for(i=0;i<height;i++)
		printf("%s\n", matrix[i]);
	for(i=0;i<height;i++)
		free(matrix[i]);
	free(matrix);
	return 0;
}