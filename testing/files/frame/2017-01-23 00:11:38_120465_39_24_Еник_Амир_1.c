
#include <stdio.h>
#include <string.h>

void frame(int height,int width, const char* text){
        int i,j;
	int xframe, yframe;
	int len = strlen(text);
	if (len > width - 2  || height < 3)  {
		printf("Error\n");
		return 0;
	}
	yframe = height % 2 ? height / 2 : height/ 2 -1;
	xframe = (width - len)/ 2;
	
	//top half
	for(i = 0; i < width; ++i) printf("*");
	for(i = 1; i < yframe; ++i) {
		printf("\n*");
		for (j = 1; j < width -1; ++j) printf(" ");
		printf("*");
	}
	//text
	printf("\n*");
	for(i = 1; i < xframe; ++i) printf(" ");
	printf("%s", text);
	for(i = xframe + len; i < width - 1 ; ++i) printf(" ");
	printf("*");
	
	//bottom half
	for(i = yframe + 2; i < height; ++i) {
		printf("\n*");
		for (j = 1; j < width -1; ++j) printf(" ");
		printf("*");
	}
	printf("\n");
	for(i = 0; i < width; ++i) printf("*");
	printf("\n");
	
	
}

int main(int argc, char **argv)
{
	if (argc < 4) 
		printf("Usage: frame <height> <width> <text>\n");
	else
		frame( atoi(argv[1]), atoi(argv[2]), argv[3]);
	return 0;
}