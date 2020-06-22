#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(!(argc == 4)){
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    unsigned int height = atoi(argv[1]);
    unsigned int width = atoi(argv[2]);
    char *text = argv[3];
    unsigned int i, j, h; //Счетчики

    unsigned int len = strlen(text);
    unsigned int white_hight = height - 3;    //Суммарная высота белого пространства
    unsigned int white_width = width - 2 - len; //Ширина белого поля

    if(width < 3 || height < 3 || len > width - 2){
        puts("Error\n");
        return 0;
    }
    for(i = 0; i < width; ++i) putchar('*');  //первая строка
    for(h = 0; h < white_hight/2; ++h){
        putchar('\n');
        putchar('*');
        for(j = 2; j < width; ++j) putchar(' ');
        putchar('*');
    }
    //вписываем слово
    putchar('\n');
    putchar('*');
    for(i = 0; i < white_width/2; ++i)
        putchar(' ');
    printf(text);
    for(; i < white_width; ++i)
        putchar(' ');
    putchar('*');
    for(; h < white_hight; ++h){
        putchar('\n');
        putchar('*');
        for(j = 2; j < width; ++j) putchar(' ');
        putchar('*');
    }
    putchar('\n');
    for(i = 0; i < width; ++i) putchar('*');  //последняя строка
    putchar('\n');
    return 0;
}