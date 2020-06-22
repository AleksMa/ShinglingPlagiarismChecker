#include <stdio.h>

int main(int argc, char **argv){
    char *str=0;
    int height=0, width=0, stroka=0, i=0, x1=0, y1=0, x2=0, y2=0, j=0, k = 0;
    if (argc != 4){
        printf ("Usage: frame <height> <width> <text>\n");
    }
    else {
        stroka = strlen (argv[3]);
        str = argv[3];
        height = atoi (argv[1]);
        width = atoi (argv[2]);
        if (height<3){
            printf ("Error");
        }
        else {
            if (stroka>width-2){
                printf ("Error");
            }
            else{
                x2= (width-stroka)/2;
                y2= ((height-1)/2);
                y2 = y2 ? y2 : 1;

                for (i=0; i<height; i++){
                    printf("*");
                    for (j=1; j<width-1; j++)
                        if ((!i) || (i == (height-1)))
                            printf ("*");
                        else {
                            if ((i==y2) && (j==x2)){
                                printf("%s",str);
                                j+=stroka-1;
                            } else printf ("%c", ' ');
                        }
                    printf("*\n");
                }
            }
        }
    }
    return 0;
}
