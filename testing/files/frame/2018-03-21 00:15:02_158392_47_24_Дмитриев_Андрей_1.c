#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

void drawHLine(uint16_t w)
{
 uint16_t i = 0;
 for(i = 0; i < w; i++)
  printf("*");
 printf("\n");
}

void drawText(char* s, uint16_t w)
{
 uint16_t i = 0;
 printf("*");
 if(NULL != s)
 {
  for(i = 1; i < (w - strlen(s)) / 2; i++)
   printf(" ");
  printf("%s", s);
  for(i = 1 + (w - strlen(s)) / 2 + strlen(s); i < w; i++)
   printf(" ");
 }
 printf("*");
 printf("\n");
}

int main(int argc, char *argv[])
{
 uint16_t w = 0, h = 0, i = 0;
 if(4 != argc)
 {
  printf("Usage: frame <height> <width> <text>\n");
  return -1;
 }
 h = strtoll(argv[1], (char **) NULL, 10);
 w = strtoll(argv[2], (char **) NULL, 10);

 if(
    (h < 3) ||
    (w < 3) ||
    (strlen(argv[3]) > (uint16_t)(w - 2))
   )
 {
  printf("Error\n");
  return -1;
 }
 drawHLine(w);
 for(i = 1; i < (h - 1) / 2; i++)
  drawText("", w);
 drawText(argv[3], w);
 for(i = 1 + (h - 1) / 2 + 1; i < h; i++)
  drawText("", w);
 drawHLine(w);
 return 1;
}