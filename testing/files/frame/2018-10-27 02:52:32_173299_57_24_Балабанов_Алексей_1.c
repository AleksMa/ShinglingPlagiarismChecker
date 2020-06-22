#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
  if(argc != 4) {
    printf("Usage: frame <height> <width> <text>");
    return 0;
  }
  char string[100];
  strncpy(string, argv[3], strlen(argv[3]) + 1);
  int length = strlen(string);
  int h = atoi(argv[1]), w = atoi(argv[2]);
  int hmid = (h-1)/2, wspacel = (w-length-2)/2, wspacer = w-length-2-wspacel;
  if((h < 3) || (w < length + 2)){
    printf("Error");
    return 0;
  }
  for(int i = 0; i < h; i++){
    if((i == 0) || (i == h-1)){
      for(int j = 0; j < w; j++) printf("*");
    } else{
      printf("*");
      if(i == hmid){
        for(int j = 0; j < wspacel; j++) printf(" ");
        printf("%s", string);
        for(int j = 0; j < wspacer; j++) printf(" ");
      } else{
        for(int j = 0; j < w - 2; j++) printf(" ");
      }
      printf("*");
    }
    if(i != h-1) printf("\n");
  }
  return 0;
}