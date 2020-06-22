
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc!=4) {
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    char s[1000];
    int h=atoi(argv[1]),w=atoi(argv[2]);
    if (strnlen(argv[3],1000)>w-2 || h<3) {
        printf("Error");
        return 0;
    }
    char *ans[h];
    for (int i=0;i<h;i++) {
        ans[i]=(char*)malloc((w+1)*sizeof(char));
        ans[i][w]=0;
        for (int j=0;j<w;j++) ans[i][j]=32;
    }
    for (int i=0;i<w;i++){
        ans[0][i]=42;
        ans[h-1][i]=42;
    }
    for (int i=1;i<h-1;i++){
        ans[i][0]=42;
        ans[i][w-1]=42;
    }
    int place=h/2-1+h%2;
    int left=(w-strlen(argv[3]))/2, right=left+strlen(argv[3]);
    ans[place][left]=0;
    strcat(ans[place],argv[3]);
    ans[place][right]=32;
    ans[place][w-1]=42;
    for (int i=0;i<h;i++){
        puts(ans[i]);
        free(ans[i]);
    }
    return 0;
}
