#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid (unsigned h, unsigned w, char *p)
{
 if (strlen(p) > (w-2)) return (0);
 if (h < 3) return (0);
 return (1);
}

void draw (unsigned h, unsigned w, char *p)
{
    int i, j;
    int goldst, goldt;

    goldt = (w - strlen(p)) / 2;

    if (h % 2 != 0) goldst = h / 2;
    else goldst = h / 2 - 1;

    for (j = 0; j < h; j++){
        if (j == 0 || j == h-1){
            for(i = 0; i < w; i++) printf("*");
            printf("\n");
        }
        else{
            if (j != goldst){
                for(i = 0; i < w; i++){
                    if (i == 0 || i == w-1) printf("*");
                    else printf(" ");
                }
                printf("\n");
            }
            else{
                for(i = 0; i < w; i++){
                    if (i == 0 || i == w-1) printf("*");
                    else{
                        if (i != goldt) printf(" ");
                        else{
                            printf("%s", p);
                            i += strlen(p) - 1;
                        }
                    }
                }
                printf("\n");
            }
        }
        //printf("\n");
    }
}

int main(int argc, char *argv[]) {

 if (argc == 4) {
  unsigned h = atoi (argv[1]);
  unsigned w = atoi (argv[2]);
  char     *p = argv[3];

  if (is_valid (h, w, p)) draw(h, w, p);
    else printf("Error");
 }
 else printf("Usage: frame <height> <width> <text>");
 return 0;
}

