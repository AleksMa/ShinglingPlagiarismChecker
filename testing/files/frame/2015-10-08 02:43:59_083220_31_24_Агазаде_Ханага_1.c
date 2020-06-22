#include <stdio.h>

int main(int argc , char **argv)
{
        if(argc != 4) {
	printf("Usage: frame <height> <width> <text>\n");
	return 0;
	}
	int height = atoi(argv[1]);
	int width = atoi(argv[2]);
	char *text = argv[3];
	int len = strlen(text);
	if(len > width - 2 || height <= 2) {
		printf("Error\n");
		return 0;
	}

	unsigned int i;
	char s1[width+1];
	s1[width] = '\0';
	for(i = 0; i < width; i++)
		s1[i] = '*';
	printf("%s\n", s1);
	char s2[width+1];
	s2[width] = '\0';
	s2[0] = s2[width - 1] = '*';
	for(i = 1; i < width - 1; i++)
		s2[i] = ' ';

	int x1 = height % 2 == 0 ? height / 2 - 2 : (height + 1) / 2 - 2;
	int x2 = height % 2 == 0 ? height / 2 - 1 : (height + 1) / 2 - 2;
	for(i = 1; i <= x1; i++) printf("%s\n", s2);
	printf("*");
	for(i = 1; i <= (width - len) / 2 - 1; i++) printf(" ");
	printf("%s", text);
	for(i = 1; i <= (width - len + 1) / 2 - 1; i++) printf(" ");
	printf("*\n");
	for(i = 1; i <= x2; i++) printf("%s\n", s2);
	printf("%s\n", s1);		
	return 0;
}