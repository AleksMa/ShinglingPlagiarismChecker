////////////////////////////////////////////////////////////////////////////////////
////////////////Сергей Юрьевич поправте пожалуйста в условии задачи/////////////////
//"usage: frame <height> <width> <text>" на "Usage: frame <height> <width> <text>"//
///////////////////////////////"ERROR" на "Error"///////////////////////////////////
/////////////////////Так как в тестах проверка именно на эти строки/////////////////
////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void putLine(int size) {
    while (size--) putchar('*');
    putchar('\n');
}

void putEmptyLine(int size) {
    size-=2;
    putchar('*');
    while (size--) putchar(' ');
    printf("*\n");
}
void putEmptyLineNTimes(int size, int count) {
    while (count--) putEmptyLine(size);
}

void putText(int width, char* text) {
    putchar('*');
    
    size_t length = strlen(text);
    size_t i=0;
    
    for (i=0;i<(width-length-2)/2;i++) putchar(' ');
    printf("%s",text);
    for (i=0;i<(width-length-1)/2;i++) putchar(' ');
    
    printf("*\n");
}

int main(int argc, char **argv)
{
    if (argc!=4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    

    int width = atoi(argv[2]);
    int height = atoi(argv[1]);
    char* text = argv[3];
    
    if (height<3 || (strlen(text) > width-2)) {
        printf("Error");
        return 0;
    }
    
    
    
    putLine(width);
    putEmptyLineNTimes(width, (height-3)/2);
    putText(width,text);
    putEmptyLineNTimes(width, (height-2)/2);
    putLine(width);
    
    
    
    
    
    return 0;
}