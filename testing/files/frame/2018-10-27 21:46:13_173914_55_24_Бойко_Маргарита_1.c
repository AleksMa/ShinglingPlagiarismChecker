#include <stdio.h>
#include <string.h>
#include <locale.h>
int main(int argc, char **argv)
{

    if (argc != 4)
    {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int h = atoi(argv[1]), w = atoi(argv[2]);

     char * text = argv[3];
   //int h, w;
   //char text[65];
   //scanf("%d %d %s", &h, &w, &text);
    int length = strlen(text);

    if (length > w-2 || h == 2)
    {
        printf("Error");
        return 0;
    }

    char line[256] = "";
    for (int i = 0; i < w; i++)
        line[i] = '*';
    //printf("%s\n",line);
    char lr[256] = "";
    for (int i = 0; i < w; i++)
        lr[i] = ' ';
    lr[0] = '*'; lr[w-1] = '*';

    char text_s[256] = "";
    text_s[0] = '*';
    int center_w = (w-length)/2;
    for (int i = 1; i < center_w; i++)
    {
        text_s[i] = ' ';
    }
   // printf("%s\n", text_s);
    strcat(text_s, text);
    text_s[w-1] = '*';
    for(int i = strlen(text_s); i<w-1; i++)
        text_s[i] = ' ';

    int center_h = (h-1)/2;

    printf("%s\n", line);
    for (int i = 1; i < center_h; i++)
        printf("%s\n", lr);
    printf("%s\n", text_s);
    for (int i = center_h; i < h - 2; i++)
        printf("%s\n", lr);
    printf("%s\n", line);




        return 0;
}