#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string(int limit, char* str) {
    printf("*");
    limit -= 2;
    int i, var = 0, k = limit - strlen(str);
    for(i = 0; i < k/2; i++) {
          printf(" ");
          ++var;
          }
    printf("%s", str);
    for(i = 0;i < k - var; i++) printf(" ");
    printf("*\n");
}

int main(int argc, char **argv) {
    int wig, hei, i, f;
    if(argc != 4) {
                  printf("Usage: frame <height> <width> <text>\n");
                  return 0;
                  }
    char* str = argv[3];
    sscanf(argv[1], "%d", &hei);
    sscanf(argv[2], "%d", &wig);
    if(wig < strlen(str)+2 || hei < 3) {
                   printf("Error");
                   return 0;
                   }
    for(i = 0; i < hei; i++) {
          if(i == 0 || i == hei-1) { for(f = 0; f < wig; f++) printf("*");
                                     printf("\n");
                                   }
          else if(i == hei/2 && hei%2 != 0) string(wig, str);
          else if(i == hei/2 - 1 && hei%2 == 0) string(wig, str);
          else string(wig, "");
          }
    return 0;
}
