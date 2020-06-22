#include <stdio.h>
#include <stdlib.h>
#define KRAI for (i = 0; i < width; i++) \
      printf("*"); \
    printf("\n");
#define SEREDINA_1 for (i = 0; i < inheight/2; i++){ \
      printf("*"); \
      for (j = 0; j < inwidth; j++) \
        printf(" "); \
      printf("*\n"); \
    }
#define SEREDINA_2 for (i = 0; i < inheight-inheight/2; i++){ \
      printf("*"); \
      for (j = 0; j < inwidth; j++) \
	printf(" "); \
      printf("*\n"); \
    }

void Ramka(int height, int width, char *str);

int main(int argc, char **argv){
  if (argc < 4){
    printf("usage: frame <height> <width> <text>\n");
    return 0;
  }

  Ramka((int)strtol(argv[1], &argv[2], 10), (int)strtol(argv[2], &argv[3], 10), argv[3]);
  return 0;
}

void Ramka(int height, int width, char *str){
  if ((height < 3) || (width - 2 < strnlen(str, 256)))
    printf("Error");
  else{
    int inheight = height - 3, inwidth = width - 2, i, j,
    space_1 = (inwidth - strnlen(str, 256))/2,
    space_2 = (inwidth - strnlen(str, 256)) - space_1;
    KRAI
    
    SEREDINA_1
    
    printf("*");
    for (i = 0; i < space_1; i++)
	printf(" ");
    printf("%s", str);
    for (i = 0; i < space_2; i++)
	printf(" ");
    printf("*\n");
    
    SEREDINA_2
    
    KRAI
    }
}