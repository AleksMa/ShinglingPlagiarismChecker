#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{ 
  int height=1, width=2, a = 0, b=0, c=0;
  if (argc != 4){
    printf("Usage: frame <height> <width> <text>");
    return 0;
  }
  height = atoi(argv[1]);
  width = atoi(argv[2]);
  if ((width-2) < strlen(argv[3]) || (width < 3) || (height < 3)){
    printf("Error");
    return 0;
  }
  for (int i=0; i<width; i++) printf("*");
  printf("\n");
  if (height % 2 == 0)
    a = -1; 
  for (int i=0; i < (height-2) ; i++){
    if (i != ((height-2)/2 + a)){
      printf("*");
      for (int j=0; j<(width-2); j++) printf(" ");
        printf("*\n");
    }
    else{
      printf("*");
      for (int c=0; c < ((width - 2 - strlen(argv[3]))/2); c++){
        printf(" ");
        b=c+1;
      }
      printf("%s", argv[3]);
        for (int e=0; e < (width - 2 - strlen(argv[3]) - b); e++) printf(" ");
          printf("*\n");
    }
  }
        for (int i=0; i<width; i++) printf("*");
        return 0; 
}