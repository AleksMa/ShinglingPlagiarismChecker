#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  if (argc != 4){
    printf("Usage: frame <height> <width> <text>\n");
    return 0;
  }
  int height = atoi(argv[1]);
  int width = atoi(argv[2]);
  char *text = argv[3];
  int length = strlen(text);
  if (length > width - 2 || height < 3){
    printf("Error\n");
    return 0;
  }
  for (int i = 0; i < height; i++){
    if (i == 0|| i == height -1){
      for (int j = 0; j < width; j++){
        printf("*");
      }
    } else if (i == (height / 2) - (height -1)%2){
      printf("*");
      for (int j = 0; j < (width - length - 2) / 2; j++){
        printf(" ");
      }
      printf("%s", text);
      for (int j = 0; j < (width - length - 2) / 2 + (width-length)%2; j++){
        printf(" ");
      }
      printf("*");
    } else {
      printf("*");
      for(int j = 1; j < width - 1; j++){
        printf(" ");
      }
      printf("*");
    }
    printf("\n");
  }
  return 0;
}