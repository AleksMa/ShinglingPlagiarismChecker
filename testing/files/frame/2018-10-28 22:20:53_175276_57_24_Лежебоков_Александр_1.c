#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int n=0,m=0,l,cv=0,csh=0,q=0;
    if (argc!=4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    n= atoi(argv[1]);
    m= atoi(argv[2]);
    cv=(n-1)/2;
    if ((strlen(argv[3]))%2 == 1) csh=(m-1)/2-strlen(argv[3])/2;
    else csh=(m)/2-strlen(argv[3])/2;
    if ((strlen(argv[3])>0)&&((n<3)||(strlen(argv[3])+2>m))) {
        printf("Error");
        return 0;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if ((i==0)||(i==n-1)) printf("*");
            else {
                if ((j==0)||(j==m-1)) printf("*");
                else {
                    if((i==cv)&&(j==csh)){
                        while (q<strlen(argv[3])){
                            printf("%c",argv[3][q]);
                            q++;
                        }
                        j+=strlen(argv[3])-1;
                    }
                    else printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
  