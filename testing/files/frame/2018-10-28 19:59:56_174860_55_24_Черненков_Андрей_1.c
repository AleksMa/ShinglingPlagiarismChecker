
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv){
        if (argc != 4){
		printf("Usage: frame <height> <width> <text>");
		return 0;
	};
	int height = atoi(argv[1]), width = atoi(argv[2]);
	char *text = argv[3];
	int length = strlen(text);
	if (((width - 2) < length) || (height < 3)){
		printf("Error\n");
		return 0;
	};
	int heightMid = ((height- 1) / 2) - 1;
	int widthMid = ((width- length - 2)/2);
	
	
	//Рисуем крышу
	for (int i = 0; i < width; i++)
		printf("*");
	printf("\n");
	
	//Рисуем верхнюю часть стен
	for (int j = 0; j < heightMid; j++){
		printf("*");
		for(int i = 0; i < width - 2; i++)
			printf(" ");
		printf("*\n");
	};
	
	//Рисуем строку с текстом
	printf("*");
	for (int i = 0; i < widthMid; i++)
		printf(" ");
	printf("%s", text);
	for (int i = widthMid + length; i < width - 2 ; i++)
		printf(" ");
	printf("*\n");

	//Рисуем нижнюю часть стен
	for (int j = heightMid+1; j < height - 2; j++){
		printf("*");
		for(int i = 0; i < width - 2; i++)
			printf(" ");
		printf("*\n");
	};
	
	//Рисуем пол
	for (int i = 0; i < width; i++)
		printf("*");
	printf("\n");
	return 0;
}


