#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void frame(int width) {
  for(int i = 0; i < width; i++) {
    printf("*");
  }
  printf("\n");
}

void lines(int width) {
  printf("*");
  for(int i = 0; i < width - 2; i++){
    printf(" ");
  }
  printf("*\n");
}

void textPrint(char* text, int width) {
  int len = strlen(text);
  int i = 0;
  int k = (width - len)/2;
  printf("*");
  for(i++; i < k; i++) {
    printf(" ");
  }

  for(int l = 0; l < len; i++,l++)
  {
    printf("%c", text[l]);
  }

  for(; i < width - 1; i++) {
    printf(" ");
  }
  printf("*\n");
}


void printStar(int width, int height, char* text) {
    int h = (height)/2;
    int i = 1;
    frame(width);
    for(; i < (height-1)/2 ; i++) {
      lines(width);
    }
    textPrint(text, width);
    for(; i < height - 2; i++) {
      lines(width);
    }
    frame(width);

}

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    printf("Usage: frame <height> <width> <text>");
    return 0;
  }



  if(atoi(argv[2]) - 2 < strlen(argv[3]) || atoi(argv[2])< 3 || atoi(argv[1]) < 3) {
    printf("Error");
    return 0;
  }

  printStar(atoi(argv[2]), atoi(argv[1]), argv[3]);

  return 0;
}
