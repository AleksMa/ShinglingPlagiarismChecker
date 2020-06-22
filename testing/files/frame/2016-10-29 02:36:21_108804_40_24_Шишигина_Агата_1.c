
#include <stdio.h>
#include <string.h>

void boards(int width);
void topbottom(int width);
void middle(int width, char *text);

int main(int argc, char **argv)
{
    int h, w, length, i;
    char *t;
    if (argc!=4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    
    h=atoi(argv[1]);
    w=atoi(argv[2]);
    t=argv[3];
    length=strlen(t);

    if ((length>w-2)||(h<3)){
        printf("Error");
        return 0;
    }

    for (i=1;i<=h;i++){
        if ((i==1)||(i==h))
            topbottom(w);
        else if (((h%2==0)&&(i==h/2))||((h%2!=0)&&(i==h/2+1)))
            middle(w,t);
        else boards(w);
    }

    return 0;
}

void topbottom(int width)
{
    int i;
    for (i=0;i<width;i++)
        putchar('*');
    putchar('\n');
}

void boards(int width)
{
    int i;
    for (i=0;i<width;i++){
        if ((i==0)||(i==width-1))
            putchar('*');
        else putchar(' ');
    }
    putchar('\n');
}


void middle(int width, char *text)
{
    int i, length, len;
    len=strlen(text);
    length=(width-len)/2-1;
    putchar('*');
    for (i=0;i<length;i++)
         putchar(' ');
    printf("%s", text);
    if (((width%2==0)&&(len%2==0))||((width%2!=0)&&(len%2!=0))){
        for (i=0;i<length;i++)
          putchar(' ');
    }
    else if ((len%2!=0)||(width%2!=0)){
        for (i=0;i<=length;i++)
          putchar(' ');
    }
    putchar('*');
    putchar('\n');
}


