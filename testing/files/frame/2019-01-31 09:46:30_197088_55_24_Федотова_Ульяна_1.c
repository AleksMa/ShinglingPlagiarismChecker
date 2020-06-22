#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun2(int n){
    int i;
    for ( i = 0; i < n; i++)
    printf("*");
}


void fun1(int n, int p, char *s, int l){
    int i;
    printf("*");
    for ( i = 1; i < p - 1 ; i++)
        printf(" ");
    printf("%s", s);
    for ( i = p + l; i < n; i++)
        printf(" ");
    printf("*");
    printf("\n");
}

int main (int argc, char **argv){
    if (argc != 4){
        printf("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    char *st = argv[3] ;
    int l,i;
    int a,b;
    l=strlen(st);
    if ((l+2 > atoi(argv[2])) || ( atoi(argv[1]) < 3))
        printf("Error");
    else{
        a=(atoi(argv[2]) - l)/2 + 1;
        b=atoi(argv[1])/2 + (atoi(argv[1]) % 2);
        fun2(atoi(argv[2]));
        printf("\n");
        for ( i = 1; i < atoi(argv[1])- 1; i++)
            if ( i != b - 1){
                printf("*");
                for ( int p = 1; p < atoi(argv[2]) - 1; p++)
                    printf(" ");
                printf("*");
                printf("\n");
            }
            else
                fun1(atoi(argv[2]),a,st,l);
                fun2(atoi(argv[2]));
    }
    return 0;
}