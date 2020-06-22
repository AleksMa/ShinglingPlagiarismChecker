#include <stdio.h>
#include <string.h>


int main(int argc, char **argv)
{
    if (argc < 4) {
        printf ("Usage: frame <height> <width> <text>\n");
	return 0;
    }
    
    int i, j, sum, height, width;
    char text[1000];
    
    /* Получение аргументов */
    height = atoi (argv[1]);
    width = atoi (argv[2]);
    strcpy (text, argv[3]);
    
    /* Проверка на ошибку */
    if (strlen(text) + 2 > width) {
	printf("Error\n");
	return 0;
    }
    if (height < 3) {
	printf("Error\n");
	return 0;
    }
    
    /* Печатаем звездочки в начале */
    for (i = 0; i < width; i++) printf("*");
    
    height-= 2;
    printf("\n");
    
    /* Печатаем звездочки по границам */
    for (i = 0; i < (height-1)/2; i++) {
	printf("*");
	for (j = 0; j < (width - 2); j++) {
	    printf(" ");
	}
	printf("*\n");
    }
    
    /* Печатаем звездочки и сама слово */
    printf("*");
    for (i = 0; i < (width - 2 - strlen(text)) / 2; i++) {
	printf(" ");
    }
    printf("%s", text);
    i += strlen(text);
    for (; i < width - 2; i++) {
	printf(" ");
    }
    printf("*\n");
    
    /* Печатаем звездочки по границе */
    for (i = (height+1)/2; i < height; i++) {
	printf("*");
	for (j = 0; j < width - 2; j++) {
	    printf(" ");
	}
	printf("*\n");
    }
    
    /* Звездочки в конце */
    for (i = 0; i < width; i++) printf("*");
    printf("\n");
    
    return 0;
}
 
