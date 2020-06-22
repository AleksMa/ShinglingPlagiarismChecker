#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv) 
{
        int width, height;
        char *text;
        char *str1;
        char *str2;
        char *str3;
        int i;

        if (argc!=4) {
                printf ("Usage: frame <height> <width> <text>\n");
                return -1;
        }
        else {
                height=atoi(argv[1]);
                width=atoi(argv[2]);
                text=argv[3];
        }
        if (height<3 || width<2 || width<strlen(text)+2) {
                printf ("Error\n");
                return -1;
        }
        str1=(char *)malloc(width+1);
        str2=(char *)malloc(width+1);
        str3=(char *)malloc(width+1);
        if (str1==NULL || str2==NULL || str3==NULL) {
                free (str1);
                free (str2);
                free (str3);
                printf ("Not enough memory\n");
                return -1;
        }
        for (i=0; i<width; i++) {
                str1[i]='*';
        }
        str1[width]=0;
        str2[0]=str2[width-1]='*';
        for (i=1; i<width-1; i++) {
                str2[i]=' ';
        }
        str2[width]=0;
        str3[0]='*';
        for (i=0; i<(width-2-strlen(text))/2; i++) {
                str3[i+1]=' ';
        }
        strcpy (str3+1+i, text);
        for (i=strlen(str3); i<width-1; i++) {
                str3[i]=' ';
        }
        str3[width-1]='*';
        str3[width]=0;
        printf ("%s\n", str1);
        for (i=0; i<(height-3)/2; i++) {
                printf ("%s\n", str2);
        }
        printf ("%s\n", str3);
        for (i=(height-3)/2+2; i<height-1; i++) {
                printf ("%s\n", str2);
        }
        printf ("%s\n", str1);
        free (str1);
        free (str2);
        free (str3);
        return 0;
}